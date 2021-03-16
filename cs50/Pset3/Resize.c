// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }
    
    int n= 0;
    n = atoi(argv[1]);
    
    if(n>100 || n<0)
    {
        printf("Usage: 0<n<100");
        return 1;
    }
    

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }


    
    int eski_x = bi.biWidth;
    int eski_y = bi.biHeight;
    
    int yeni_x = bi.biWidth * n;
    int yeni_y  = bi.biHeight * n;

    // determine padding for scanlines
    int ipadding = (4 - (eski_x * sizeof(RGBTRIPLE)) % 4) % 4;
    int opadding = (4 - (yeni_x * sizeof(RGBTRIPLE)) % 4) % 4;
    
    bi.biWidth = yeni_x;
    bi.biHeight = yeni_y;
    
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * yeni_x) + opadding) * abs(yeni_x);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

        // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    RGBTRIPLE scanline[yeni_x * sizeof(RGBTRIPLE)];



    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(eski_y); i < biHeight; i++)
    {    
        // iterate over pixels in scanline
        for (int j = 0; j < eski_x; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            for (int k = 0; k < n; k++)
            {
                scanline[(j * n) + k] = triple;
            }
        
        }

        // skip over padding, if any
        fseek(inptr, ipadding, SEEK_CUR);
        
         for (int j = 0; j < n; j++)
        {
            // write a new scanline once
            fwrite(scanline, sizeof(RGBTRIPLE), yeni_x, outptr);
        
        // then add it back (to demonstrate how)
        for (int k = 0; k < opadding; k++)
        {
            fputc(0x00, outptr);
        }
        }
    }
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}