#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

bool unique_char(string  tex)
{
    string n = tex;

    for(int i = 0; i < strlen(n); i++)
    {
        for (int j = 0; j < strlen(n); j++)
        {
            if(i != j)
            {
                if(tex[i] == tex[j] || (tex[i] - 65) == tex[j] || tex[i] == (tex[j] - 65))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main(int argc, string argv[])
{
    string input = argv[1];

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(input) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (unique_char(input) == false)
    {
        printf("All characters must be unique.\n");
        return 1;
    }

   for (int i = 0; i < 26; i++)
    {
        if (toupper(input[i]) < 65 || toupper(input[i]) > 90)
        {
            printf("Key must only contain letters.\n");
            return 1;
        }
   }
    string txt = get_string("plaintext: \n");
    char a[strlen(txt)];
    strcpy(a, txt);
    char new_txt[200];
    int i = 0;

    while(strcmp(&a[i], "\0") > 0)
    {
        if (a[i] > 64 && a[i] < 91)
        {
            new_txt[i] = toupper(input[(a[i] - 65)]);
        }
        else if (a[i] > 96 && a[i] < 123)
        {
            new_txt[i] = tolower((input[(a[i] - 32) - 65]));
        }
        else
        {
            new_txt[i] = a[i];
        }
        i++;
    }
    printf("ciphertext: %s\n", new_txt);
    return 0;
}