#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        return 1;
    }

    FILE *img;
    char filename[7];
    unsigned char *buffer = malloc(512);
    int counter = 0;

    while (fread(buffer, 512, 1, inptr))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter > 0)
            {
                fclose(img);
            }

            sprintf(filename, "%03d.jpg", counter);
            img = fopen(filename, "w");

            if (img == NULL)
            {
                fclose(inptr);
                free(buffer);
                fprintf(stderr, "Could not create output JPG %s", filename);
                return 3;
            }

            counter++;
        }

        if (counter > 0)
        {
            fwrite(buffer, 512, 1, img);
        }
    }

    fclose(img);
    fclose(inptr);
    free(buffer);
    return 0;
}