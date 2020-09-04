#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // initialize variables and grab input
    string text = get_string("Text: \n");
    float letters = 0;
    float words = 0;
    float sentences = 0;
    
    // go through text to find letters, words, sentences
    for (int i = 0, n = strlen(text); i < n; i ++)
    {
        // character is a letter in between these ascii ranges
        if (text[i] >= 65 && text[i] <= 122)
        {
            letters ++;
        }
        
        // reads the end of a word if it's a space
        else if (text[i] == 32 && (text[i - 1] != 33 && text[i - 1] != 46 && text[i - 1] != 63))
        {
            words ++;
        }
        
        // is a sentence and a word if it ends in a . or ! or ?
        else if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences ++;
            words ++;
        }
    }
    
    // calculate index number
    float L = letters * 100 / words;
    float S = sentences * 100 / words;
    float index = round(0.0588 * L - 0.296 * S - 15.8);
    
    // print result
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Grade %i\n", (int) index);
    }
}
