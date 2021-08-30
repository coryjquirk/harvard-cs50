# harvard-cs50
Problem sets and labs for Harvard CS50 offered through OpenCourseWare.  
Course outline:  
https://cs50.harvard.edu/x/2021/

### week 1: C  
(exercises completed in the <a href="https://ide.cs50.io/">CS50 IDE</a>)  
to test for bugs and style respectively:  
library: `#include <cs50.h>`  
terminal commands: `check50 #cfile` / `style50 #cfile`  

lab:
* population growth simulation
```
$ ./population
Start size: 100
End size: 200
Years: 9
```
problem set:
* Mario ASCII art  
* Credit card number validation
    * [Luhn's algorithm](https://en.wikipedia.org/wiki/Luhn_algorithm) 

### week 2: arrays
lab:  
* Scrabble command line program:  
    * prompts users for two words  
    * iterates through letters
    * uses ASCII values to match A-Z[i] to a Scrabble letter score
    * totals letter scores for each word
    * prints winner
    * IMPROVEMENT: verify that user-entered words are real dictionary words.  
    
problem set:  
* Readability command line program
    * takes user input & verifies the reading grade level for texts
    * [Coleman-Lindau index](https://en.wikipedia.org/wiki/Coleman%E2%80%93Liau_index) formula
* Substituition comman line program
    * prompts user for scrambled alphabet cipherkey (no repeat letters, 26char only letters)
        * example keys: *vchprzgjntlskfbdqwaxeuymoi*, *VCHPRZGJNTLSKFBDQWAXEUYMOI*, *VcHpRzGjNtLsKfBdQwAxEuYmOi*
    * changes user-input plaintext to ciphertext
        * retains user casing and symbol/space/number placement
            * e.g. hELL0, W0RLd! -> jRSS0, Y0WSp!
    * usage: `./substitution *key*`
    * IMPROVEMENT: currently can only handle plaintext up to 24 characters long 
### credit
all code in labs and problem sets is originally written by me, going off of the course's distribution code.
