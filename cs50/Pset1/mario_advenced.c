#include <stdio.h>
#include <cs50.h>

//Olayın net anlaşılması için fonksiyon oluşturuyoruz.
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
//Girdiyi alıp Maks yükseklik ayarını yapıyoruz.
    do
    {
        yukseklik = get_int("yukseklik: ");
        genislik = yukseklik;
    }
    while (yukseklik <= 0 || yukseklik > 8);
//Fonksiyonu kullanıyoruz.
    for (int i = 1; i <= yukseklik; i++)
    {
        int kare = i;
        int bosluk = genislik - kare;

        tekrarla(' ', bosluk);
        tekrarla('#', kare);
//Bu boşluğun amacı simetriyi oluşturmak.
        printf("  ");

        tekrarla('#', kare);

        printf("\n");
    }
}
