#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
// Matches a = 1, b = 3, c = 3, etc
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// function prototype:
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    printf("Enter words for scrabble scores:\n");
    printf("[case insensitive]\n");
    printf("[numbers or symbols are scored 0]\n");
    printf("================================\n");
    //prompt user for 2 words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    //print scores and winner
    printf("player 1: '%s' %i points\n", word1, score1);
    printf("player 2: '%s' %i points\n", word2, score2);
    if (score1 > score2){
        printf("PLAYER 1 WINS\n");
    } else if (score1==score2) {
        printf("TIE!\n");
    } else {
        printf("PLAYER 2 WINS\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++){
        char letter = word[i];
        //if lowercase, convert to upper with toupper()
        //& validate char is a letter with isalpha()
        if (islower(letter) && isalpha(letter))
        {
                //subtract 65 from newly converted lowercase char to get ASCII value
            int alphaIndex = toupper(letter) - 65;
            //match ASCII indexical value to our point table above
            int pointVal = POINTS[alphaIndex];
            //add pointVal to the running score for the word
            score += pointVal;
        }
        else if (isalpha(letter))
        {
            printf("char: %c\n", letter);
            //subtract 65 to get ASCII value
            int alphaIndex = letter - 65;
            printf("letter's index: %i\n", alphaIndex);
            //match ASCII indexical value to our point table
            int pointVal = POINTS[alphaIndex];
            printf("letter's pointval: %i\n", pointVal);
            //add pointVal to the running score for the word
            score += pointVal;
        }
    }
    return score;
}

// USEFUL METHODS:
// ==========================
// islower() - check whether a character is lowercase
// isupper() - check whether a character is uppercase
// tolower() - convert a char to lowercase
// toupper() - convert a char to uppercase
//To find the value at the nth index of an array called arr,
//we can write arr[n]. We can apply this to strings as well,
//as strings are arrays of characters.