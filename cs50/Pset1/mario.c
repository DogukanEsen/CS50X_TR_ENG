#include <stdio.h>
#include <cs50.h>


void tekrarla(char c, int times)
{
    while (--times >= 0)
    {
        printf("%c", c);
    }
}

int main()
{
    int yukseklik, genislik;

    do
    {
        yukseklik = get_int("yukseklik: ");
        genislik = yukseklik + 1;
    }
    while (yukseklik <= 0 || yukseklik > 8);

    for (int i = 1; i <= yukseklik; i++)
    {
        int kare = i + 1;
        int bosluk = genislik - kare;

        tekrarla(' ', bosluk);
        tekrarla('#', kare);

        printf("\n");
    }
}