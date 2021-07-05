#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    int end;
        printf("POPULATION GROWTH SIMULATOR\n");
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
