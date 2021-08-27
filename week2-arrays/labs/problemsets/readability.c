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
    int grade = gradeString(gradedText);

}

int gradeString(string gradedText)
{
    int letterCount = 0;
    int wordCount = 0;
    int sentenceCount = 0;
    printf("string length: %lu characters\n", strlen(gradedText));
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
    //test paragraph
    //Existing computer programs that measure readability are based largely upon subroutines which estimate number of syllables, usually by counting vowels. The shortcoming in estimating syllables is that it necessitates keypunching the prose into the computer. There is no need to estimate syllables since word length in letters is a better predictor of readability than word length in syllables. Therefore, a new readability formula was computed that has for its predictors letters per 100 words and sentences per 100 words. Both predictors can be counted by an optical scanning device, and thus the formula makes it economically feasible for an organization such as the U.S. Office of Education to calibrate the readability of all textbooks for the public school system.
    printf("letter count: %i\n", letterCount);
    printf("word count: %i\n", wordCount);
    printf("sentence count: %i\n", sentenceCount);

    //grade calculation
        //Coleman-Liau index:
        //index = 0.0588 * L - 0.296 * S - 15.8
        //L: number of letters per 100 words
        //S: avg number of sentences per 100 words

    float S = ((letterCount / wordCount) * 100);
    printf("S: %f\n", S);

    float L = ((sentenceCount / wordCount) * 100);
    printf("L: %f\n", L);

    int grade = ((0.0588 * L) - (0.296 * S) - 15.8);
    printf("Grade level: %i\n", grade);

    return grade;
}