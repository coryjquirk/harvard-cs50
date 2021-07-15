#include <cs50.h>
#include <stdio.h>
//STEPS
//Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
//Add the sum to the sum of the digits that weren’t multiplied by 2.
//If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

//Test numbers:
//Visa 4012888888881881
//Mastercard 2223016768739313
//American Express 378282246310005
//Invalid
//more to test: https://developer.paypal.com/docs/payflow/payflow-pro/payflow-pro-testing/
int main(void)
{
    //prompt user for card num
    long cardNum = get_long("Number: ");
    //extracting each 2nd digit starting with 2nd to last
    int digitTwo = cardNum % (100) / 10;
    int digitFour = (cardNum % 10000) / 1000;
    int digitSix = (cardNum % 1000000) / 100000;
    int digitEight = (cardNum % 100000000) / 10000000;
    int digitTen = (cardNum % 10000000000) / 1000000000;
    long digitTwelve = (cardNum % 1000000000000) / 100000000000;
    long digitFourteen = (cardNum % 100000000000000) / 10000000000000;
    long digitSixteen = (cardNum % 10000000000000000) / 1000000000000000;
    int sumOfDoubledDigits = ((((digitTwo * 2) % 100) / 10) + ((digitTwo * 2) % 10)) + ((((digitFour * 2) % 100) / 10) +
                             ((digitFour * 2) % 10)) + ((((digitSix * 2) % 100) / 10) + ((digitSix * 2) % 10)) +
                             ((((digitEight * 2) % 100) / 10) + ((digitEight * 2) % 10)) + ((((digitTen * 2) % 100) / 10) +
                             ((digitTen * 2) % 10)) + ((((digitTwelve * 2) % 100) / 10) + ((digitTwelve * 2) % 10)) +
                             ((((digitFourteen * 2) % 100) / 10) + ((digitFourteen * 2) % 10)) +
                             ((((digitSixteen * 2) % 100) / 10) + ((digitSixteen * 2) % 10));
    //adding the digits of those products together (NOT the products themselves)
    printf("Sum after doubling all digits and extracting digits from products: %i\n", sumOfDoubledDigits);
    //add that sum to the sum of the digits that weren't multiplied by 2
    //each 2nd digit starting with very last
    int digitOne = cardNum % 10;
    int digitThree = (cardNum % 1000) / 100;
    int digitFive = (cardNum % 100000) / 10000;
    int digitSeven = (cardNum % 10000000) / 1000000;
    int digitNine = (cardNum % 1000000000) / 100000000;
    long digitEleven = (cardNum % 100000000000) / 10000000000;
    long digitThirteen = (cardNum % 10000000000000) / 1000000000000;
    long digitFifteen = (cardNum % 1000000000000000) / 100000000000000;
    int sumOfRemaining = digitOne + digitThree + digitFive + digitSeven + digitNine + digitEleven + digitThirteen + digitFifteen;
    printf("Sum of remaining digits: %i\n", sumOfRemaining);
    int sumOfAll = sumOfRemaining +  sumOfDoubledDigits;
    printf("Sum of both sums: %i\n", sumOfAll);
    //VALIDATION CHECK
    //card num is valid if sumOfAll's last digit is 0
    if (sumOfAll % 10 == 0)
    {
        printf("Valid card number\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

