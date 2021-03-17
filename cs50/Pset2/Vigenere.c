#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char m);


int main(int argc, string argv[])
{

//Hatalar ayıklanıyor.
    if (argc == 2)
    {
        string a = argv[1];

        for (int i = 0, n = strlen(a); i < n; i++)
        {
            if (!isalpha (a[i]))
            {
                printf("Usage: kelim: keyword\n");
                return 1;
            }
        }  
        
    string s = get_string("kelime: ");
    int s_uzunluk = strlen(s);
    char ciphered[s_uzunluk];
    printf("ciphertext: ");

    for(int i = 0, j = 0; i < s_uzunluk; i++ )    
           {//sırayla fonksiyona yönlendiriliyor.
            int k = shift(a[j]);
            if (s[i] >= 65 && s[i] <= 90)
            {
                ciphered[i] = (s[i] + k - 65) % 26 + 65;
                j = (j + 1) % strlen(a);
            }
           else if(s[i] >= 97 && s[i] <= 122)
           {
               ciphered[i] = (s[i] + k - 97) % 26 + 97;
               j = (j + 1) % strlen(a);
           }else
           {
               ciphered[i] = s[i];
           }
           printf("%c", ciphered[i]);
           }
        printf("\n");
        return 0; 
    }else
    {
        printf("Usage: ./vigenere keyword");
        return 1;
    }
} 

//Fonksiyonun amacı büyük küçük harf ayrımı yapmak ve ona göre azaltmak.
 int shift(char m){
     
      if (m >= 65 && m <= 90)
      {
          m -= 65;
          
      }else if(m >= 97 && m <= 122)
      {
          m -= 97;
      }
      return m;
      }
