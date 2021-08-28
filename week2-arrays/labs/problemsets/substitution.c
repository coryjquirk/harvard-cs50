#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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
    bool repeatChars = false;
    bool validKey = validateKey(cipherKey);
    if (!validKey)
    {
    printf("Usage: ./substitution key\n");
    }
    else
    {
    //prompt user for plaintext string to be enciphered.
    string plaintext = get_string("plaintext to encipher: \n");
    //ENCIPHER !@D2309D23D@#d23D2903DJ230D23D2#d@#d@#2982F209
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
            printf("===============================\n");
            printf("cipherKey[i]: %c\n", cipherKey[i]);
            printf("===============================\n");
            //TYPE: only letters
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
                printf("cipherKey[j]: %c\n", cipherKey[j]);
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
    return "My Super Secret Code";
}
