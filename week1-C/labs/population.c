#include <cs50.h>
#include <stdio.h>

// Determine how long it takes for a population to reach a particular size.
// $ ./population
// Start size: 100
// End size: 200
// Years: 9

int main(void)
{
    int start;
    int end;
    printf("POPULATION GROWTH SIMULATOR\n");
    printf("Each year, we gain a third of the population in births,\n");
    printf("and lose a quarter of the population.\n");
    start = get_int("Starting population: ");
    end = get_int("End goal: ");
    if (start<=0){
        printf("Starting population must be greater than 0\n");
    } else if (end < start) {
        printf("End pop must be greater than start\n");
    } else {
        //convert user's int input to a float so we can simulate a growth rate
        float popgrewto = start;
        int yrs = 0;
        do
        {
            //each year we gain a third of the population, lose a fourth.
            popgrewto = popgrewto + (popgrewto/3) - (popgrewto/4);
            yrs++;
        }
        while (popgrewto<end);
        printf("Took this many years to reach end goal: %i\n", yrs);
    }
}
