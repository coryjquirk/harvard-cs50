#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//plaintext:  HELLO
//ciphertext: EHBBQ

//function prototype
int validateKey(string cipherKey);

//argc: number of arguments
//argv[]: array of strings of all the command line arguments provided.
    //argv[0] is ./substition, argv[1] is the cipherkey.
int main(int argc, string argv[])
{
    string cipherKey = argv[1];
    bool validKey = validateKey(cipherKey);
    if (!validKey)
    {
        printf("Usage: ./substitution key\n");
    }
    else
    {
        //prompt user for string
        string plaintext = get_string("plaintext to encipher: \n");
        //print cipher text
        printf("ciphertext: %s\n", "blah\n");
        //ENCIPHER !@D2309D23D@#d23D2903DJ230D23D2#d@#d@#2982F209

        //NONALPHA: punctuation and spaces stay the same from plaintext->ciphertext.
    }
}

int validateKey(string cipherKey)
{
    //initial key validation:
    //REPETITION: no repeat characters
    //CASING: upper stays upper, lower stays lower

    //LENGTH: must be 26 characters
    if (strlen(cipherKey) != 26)
    {
        printf("Key must contain 26 characters.\n");
    }
    else
    {
        for (int i = 0; i < strlen(cipherKey); i++)
        {
            //TYPE: only letters
            if (!isalpha(cipherKey[i]))
            {
                printf("Key must contain letters only.\n");
                break;
            }
        }
    }
    return 0;
}