#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//plaintext:  HELLO
//ciphertext: EHBBQ

//function prototype
bool validateKey(string cipherKey);
string encipher(string plaintext, string cipherKey);

//argc: number of arguments
//argv[]: array of strings of all the command line arguments provided.
    //argv[0] is ./substition, argv[1] is the cipherkey.
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
    //prompts user for plaintext string to be enciphered.
    string plaintext = get_string("plaintext to encipher: \n");
    //ENCIPHERING
        //CASING: upper stays upper, lower stays lower
        //NONALPHA: punctuation and spaces stay the same from plaintext->ciphertext.
    string ciphertext = encipher(plaintext, cipherKey);
    printf("ciphertext: %s\n", ciphertext);
    }
}

bool validateKey(string cipherKey)
{
    //test keys
    //vchprzgjntlskfbdqwaxeuymoi
    //VCHPRZGJNTLSKFBDQWAXEUYMOI
    //VcHpRzGjNtLsKfBdQwAxEuYmOi

    //LENGTH: must be 26 characters
    if (strlen(cipherKey) != 26)
    {
    printf("Key must contain 26 characters.\n");
    }
    else
    {
        for (int i = 0; i < strlen(cipherKey); i++)
        {
            char character = cipherKey[i];
            //CHARACTER TYPE: only letters
            if (!isalpha(character))
            {
                printf("Key must contain letters only.\n");
                break;
            }
            else
            //REPETITION: no repeat characters
            for (int j = 1 + i; j < strlen(cipherKey); j++)
            {
                if (character==cipherKey[j])
                {
                    printf("No repeat characters.\n");
                    return false;
                }
            }
        }
        printf("raw key: %s\n", cipherKey);
    }
    return true;
}

string encipher(string plaintext, string cipherKey)
{
    int cipherCode[strlen(plaintext)];



    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("-------------------------------\n");
        char letter = plaintext[i];
        if (!isalpha(letter))
        {
            printf("yup that's a space.\n");
            printf("-------------------------------\n");
        }
        //switching char letter to int c
        int c = letter;
        int cipherIndex;
        printf("letter: %c\n", c);
        printf("ASCII val: %i\n", c);
        if (islower(c))
        {
            cipherIndex = c - 97;
        }
        else
        {
            cipherIndex = c - 65;
        }
        printf("alpha index: %i\n", cipherIndex);
        cipherCode[i] = cipherIndex;
    }
    printf("================================\n");

    printf("cipherCode: \n");

    for (int i = 0; i < strlen(plaintext); ++i)
    {
    printf("cipherCode[i]: %i", cipherCode[i]);
    printf("\n");
    int alphaIndex = cipherCode[i];
    char newChar = cipherKey[alphaIndex];
    printf("newChar: %c\n", newChar);
    printf("alphaIndex: %i\n", alphaIndex);


    //TODO: build new string out of newChars.

    printf("-------------------------------\n");
    }

    //ciphertext must eventually come out with same casing as plaintext
    return "My Enciphered Message";
}