#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//function prototype
int gradeString(string gradedText);

int main(void)
{
    //INPUT: user text string
    //prompt user
    string gradedText = get_string("Text: ");

    //parts of string to tesT:
    //# of letters
    //# of sentences
    //ends with .!?
    //# of words
    //separated by spaces

    //OUTPUT: Grade level #
    //if <1 "Before Grade 1", >16, "Grade 16+"
    printf("%s\n", gradedText);
    int grade = gradeString(gradedText);
}

int grade_string(string gradedText)
{
    int letterCount = 0;
    int wordCount = 0;
    int sentenceCount = 0;
    printf("string length: %lu\n", strlen(gradedText));
    for (int i = 0; i < strlen(gradedText); i++)
    {
        char character = gradedText[i];
        if (isalpha(character))
        {
            //add 1 to letter count
            letterCount++;
        }
        else if (character == ' ' && (gradedText[i-1] != '!') && (gradedText[i-1] != '.') && (gradedText[i-1] != '?'))
        {
            //add 1 to word count if there's a space that's not preceded by !?.
            wordCount++;
        }
        else if ((character == '!'|| character == '?' || character == '.') && ((gradedText[i+1] == ' ') || ((i+1)==strlen(gradedText))))
        {
            //add 1 to sentence count and word count
                //if symbol is followed by a space
                //OR if the symbol is the last character of the whole string.
            //(assuming proper English grammer with no repeat punctuation (e.g. !!, ?!, ..)
            //(and assuming all punctuation is immediately preceded by the last letter of a word.)
            sentenceCount++;
            wordCount++;
        }
    }
    printf("letter count: %i\n", letterCount);
    printf("word count: %i\n", wordCount);
    printf("sentence count: %i\n", sentenceCount);

    //grade calculation
        //Coleman-Liau index:
        //index = 0.0588 * L - 0.296 * S - 15.8
        //L: number of letters per 100 words
        //S: avg number of sentences per 100 words
    return 0;
}