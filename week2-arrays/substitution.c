#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//test keys
    //vchprzgjntlskfbdqwaxeuymoi
    //VCHPRZGJNTLSKFBDQWAXEUYMOI
    //VcHpRzGjNtLsKfBdQwAxEuYmOi

bool validateKey(string cipherKey);
string encipher(string plaintext, string cipherKey);
char ciphertext[] = {'\0'};

int main(int argc, string argv[])
{
    string cipherKey = argv[1];
    if (argv[1]==NULL)
    {
        printf("Usage: ./substitution *key*\n");
    }
    bool repeatChars = false;
    bool validKey = validateKey(cipherKey);
    if (!validKey)
    {
        printf("Usage: ./substitution *key*\n");
    }
    else
    {
        for (int i = 0; i < strlen(cipherKey); i++)
        {
            char character = cipherKey[i];
            if (islower(character))
            {
                //convert all 26 char to uppercase
                char upperChar = toupper(character);
                cipherKey[i] = upperChar;
            }
        }
        string plaintext = get_string("plaintext to encipher (24 char max): \n");
        if (strlen(plaintext)>24)
        {
            printf("Sorry, for now plaintext must be 24 characters or less.\n");
        }
        else
        {
            string final = encipher(plaintext, cipherKey);
            printf("ciphertext: %s\n", final);
        }
    }
}

bool validateKey(string cipherKey)
{
    if (strlen(cipherKey) != 26)
    {
    printf("Key must contain 26 characters.\n");
    }
    else
    {
        for (int i = 0; i < strlen(cipherKey); i++)
        {
            char character = cipherKey[i];
            if (!isalpha(character))
            {
                printf("Key must contain letters only.\n");
                break;
            }
            else
            for (int j = 1 + i; j < strlen(cipherKey); j++)
            {
                if (character==cipherKey[j])
                {
                    printf("No repeat characters.\n");
                    return false;
                }
            }
        }
    }
    return true;
}

string encipher(string plaintext, string cipherKey)
{
    int cipherCode[strlen(plaintext)];
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char letter = plaintext[i];
        if (!isalpha(letter))
        {
            int c = letter;
            //ASCII val of symbol/num/space:
            cipherCode[i] = c;
        }
        else
        {
            //gives letter ASCII int value:
            int c = letter;
            //brings down ASCII val to usable ABC index:
            int cipherIndex;
            if (islower(c))
            {
                cipherIndex = c - 97;
            }
            else
            {
                cipherIndex = c - 65;
            }
            cipherCode[i] = cipherIndex;
        }
    }
    for (int j = 0; j < strlen(plaintext); ++j)
    {
        //matches cipher letter's place to its original place in plaintext:
        int alphaIndex = cipherCode[j];
        if (isalpha(plaintext[j]))
        {
            char newChar = cipherKey[alphaIndex];
            //CASE retained from plaintext -> ciphertext
            if (isupper(plaintext[j]))
            {
                char upperChar = toupper(newChar);
                strncat(ciphertext, &upperChar, 1);
            }
            else if (islower(plaintext[j]))
            {
                char lowerChar = tolower(newChar);
                strncat(ciphertext, &lowerChar, 1);
            }
        }
        else
        {
            //for non-alpha chars, newChar uses same char from plaintext[j]
            char newChar = plaintext[j];
            strncat(ciphertext, &newChar, 1);
        }
    }
    return ciphertext;
}