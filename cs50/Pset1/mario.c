#include <stdio.h>
#include <cs50.h>

//Burada olayın daha iyi anlaşması için fonksiyon tanımladım.
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
//Bu döngüde girdiyi alıyoruz ve maks yükseklik ayarı yapıyoruz
    do
    {
        yukseklik = get_int("yukseklik: ");
        genislik = yukseklik + 1;
    }
    while (yukseklik <= 0 || yukseklik > 8);
//Burada ise fonksiyonu kullanıyoruz.
    for (int i = 1; i <= yukseklik; i++)
    {
        int kare = i + 1;
        int bosluk = genislik - kare;

        tekrarla(' ', bosluk);
        tekrarla('#', kare);

        printf("\n");
    }
}
//Yöntem doğru fakat hata verebiliyor. Bunun nedenini bulunca sorunu çözeceğim.
