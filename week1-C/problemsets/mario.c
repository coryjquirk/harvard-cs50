#include <cs50.h>
#include <stdio.h>
int main(void)
{
    printf("ASCII MARIO\n");
    //prompt user for input with get_int
    int height = get_int("Height: ");
    if ( height >8 || height < 1)
    {
        printf("Height must be 1-8.\n");
    } else {
        if (height == 1)
        {
            printf("       #  #\n");
        } else if (height == 2)
        {
            printf("       #  #\n");
            printf("      ##  ##\n");
        } else if (height == 3)
        {
            printf("       #  #\n");
            printf("      ##  ##\n");
            printf("     ###  ###\n");
        } else if (height == 4)
        {
            printf("       #  #\n");
            printf("      ##  ##\n");
            printf("     ###  ###\n");
            printf("    ####  ####\n");
        } else if (height == 5)
        {
            printf("       #  #\n");
            printf("      ##  ##\n");
            printf("     ###  ###\n");
            printf("    ####  ####\n");
            printf("   #####  #####\n");
        } else if (height == 6)
        {
            printf("       #  #\n");
            printf("      ##  ##\n");
            printf("     ###  ###\n");
            printf("    ####  ####\n");
            printf("   #####  #####\n");
            printf("  ######  ######\n");
        } else if (height == 7)
        {
            printf("       #  #\n");
            printf("      ##  ##\n");
            printf("     ###  ###\n");
            printf("    ####  ####\n");
            printf("   #####  #####\n");
            printf("  ######  ######\n");
            printf(" #######  #######\n");
        }  else if (height == 8)
        {
            printf("       #  #\n");
            printf("      ##  ##\n");
            printf("     ###  ###\n");
            printf("    ####  ####\n");
            printf("   #####  #####\n");
            printf("  ######  ######\n");
            printf(" #######  #######\n");
            printf("########  ########\n");
        }
    }
}