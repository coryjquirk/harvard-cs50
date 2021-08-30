#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//plaintext:  HELLO
//ciphertext: EHBBQ

//function prototype
bool validateKey(string cipherKey);
string encipher(string plaintext);

//argc: number of arguments
//argv[]: array of strings of all the command line arguments provided.
    //argv[0] is ./substition, argv[1] is the cipherkey.
int main(int argc, string argv[])
{
    string cipherKey = argv[1];
    if (argv[1]==NULL)
    {
    printf("Usage: ./substitution key\n");
    }
    bool repeatChars = false;
    bool validKey = validateKey(cipherKey);
    if (!validKey)
    {
    printf("Usage: ./substitution key\n");
    }
    else
    {
    //prompts user for plaintext string to be enciphered.
    string plaintext = get_string("plaintext to encipher: \n");
    //ENCIPHERING
        //CASING: upper stays upper, lower stays lower
        //NONALPHA: punctuation and spaces stay the same from plaintext->ciphertext.
    string ciphertext = encipher(plaintext);
    printf("ciphertext: %s\n", ciphertext);
    }
}

bool validateKey(string cipherKey)
{
    //test keys
    //ytnshkvefxrbauqzclwdmipgjo
    //YTNSHKVEFXRBAUQZCLWDMIPGJO
    //yTnShKvEfXrBaUqZcLwDmIpGj

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
            else if (islower(character))
            {
                //convert all 26 char to uppercase
                char upperChar = toupper(character);
                cipherKey[i] = upperChar;
            }
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
        printf("uppercase key: %s\n", cipherKey);
    }
    return true;
}

string encipher(string plaintext)
{
    int cipherCode[strlen(plaintext)];
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char letter = plaintext[i];
        if (!isalpha(letter))
        {
            printf("yup that's a space.\n");
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
        printf("cipher index: %i\n", cipherIndex);
        cipherCode[i] = cipherIndex;
        //gives us a table of 'letter A'=[0], 'letter B'=[1], etc
        //plaintext[i] = cipherKey[i]
        //ciphertext must come out with same casing as plaintext
    }
    printf("cipherCode: \n");
    for (int i = 0; i < strlen(plaintext); ++i)
    {    printf("%i", cipherCode[i]);
            printf("\n");
    }
    return "My Super Secret Code";
}