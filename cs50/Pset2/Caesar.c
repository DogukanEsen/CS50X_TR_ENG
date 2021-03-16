#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int key = 0;
    if(argc == 2)
    {
        key = atoi(argv[1]);
    }

    if (key>=26)
    {
        key %= 26;
    }
    
    if (argc != 2 || key<=0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


string s = get_string("kelime: ");
if (argc==2)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    { 
    
        if (s[i] >= 65 && s[i] <= 90)
        {
            if(s[i] + key > 90)
            {
                s[i] -= 26;
            }
            s[i] += key;
        } else if(s[i] >= 97 && s[i] <= 122)
        {
            if(s[i] + key > 122)
            {
                s[i] -= 26;
            }
            s[i] += key;
        }
    }
}
    printf("ciphertext: %s\n",s);
}
