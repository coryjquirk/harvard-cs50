#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//function prototype
int gradeString(string textToGrade);

int main(void)
{
    //prompts user to input text to be graded
    string textToGrade = get_string("Text: ");

    int grade = gradeString(textToGrade);

    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int gradeString(string textToGrade)
{
    int letterCount = 0;
    int wordCount = 0;
    int sentenceCount = 0;
    for (int i = 0; i < strlen(textToGrade); i++)
    {
        char character = textToGrade[i];
        if (isalpha(character))
        {
            //add 1 to letter count
            letterCount++;
        }
        else if (character == ' ' && (textToGrade[i - 1] != '!') && (textToGrade[i - 1] != '.') && (textToGrade[i - 1] != '?'))
        {
            //add 1 to word count if there's a space that's not preceded by !?.
            wordCount++;
        }
        else if ((character == '!' || character == '?' || character == '.') && ((textToGrade[i + 1] == ' ') || ((i + 1) == strlen(textToGrade))))
        {
            //add 1 to sentence count and word count
            //if symbol is followed by a space
            //OR if the symbol is the last character of the whole string.
            //(assuming user input has proper English grammer with no repeat punctuation (e.g. !!, ?!, ..)
            //(and assuming all punctuation is immediately preceded by the last letter of a word.)
            sentenceCount++;
            wordCount++;
        }
    }
    //Validate behavior of letterCount, wordCount, sentenceCount:
        //https://charcounter.com/en/
    float letters = (float)letterCount;
    float words = (float)wordCount;
    float sentences = (float)sentenceCount;
    //Coleman-Liau index for determining reading level:
    //grade level = 0.0588 * L - 0.296 * S - 15.8
        //L = number of letters per 100 words
        //S = avg number of sentences per 100 words
    float G = ((0.0588 * (letters / words * 100)) - (0.296 * (sentences / words * 100)) - 15.8);
    //round() method rounds decimal to the nearest whole number.
    int grade = round(G);

    return grade;
}