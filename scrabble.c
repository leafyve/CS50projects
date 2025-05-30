#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Points
int points[] = {1, 3, 3 ,2 ,1 ,4 ,2 ,4 ,1 ,8 ,5 ,1 ,3 ,1 ,1 ,3 ,10 ,1 ,1 ,1 ,1 ,4 ,4 ,8 ,4 ,10};

// Has ASCII arrays value assigned to small letters for alphabets
int small_letters[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};

// Ascii Values for capital letters of alphabets
int capital_letters[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
int temp_points [] = {};


int compute_score(string word);

int main (void)
{

    // Prompt the user for two words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");


    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
     if (score1 > score2)
    {
        printf("Player 1 Wins! \n");
    }

    else if (score1 < score2)
    {
        printf("Player 2 Wins! \n");
    }

    else if (score1 == score2)
    {
        printf("Tie! \n");
    }
    return 0;
}


// Compute the score of each word
int compute_score(string word)
{
    int score = 0;
    //Compute and return score for string
    for (int i = 0; i < strlen(word); i++)
    {
        // checks if the letter is upper
        if (isupper(word[i]))
        {
            // if the letter is upper find the words from capital_letters array according to ASCII
            // if capital letter is found takes its index and assign points to temp_Points array accourding to the index
            // adds tem_points value to int score to calculate the total score
            for (int f = 0; f < sizeof(capital_letters); f++)
            {
                if (word[i] == capital_letters[f])
                {
                    temp_points[i] = points[f];
                    score += temp_points[i];
                }
            }
        }
        else if (islower(word[i]))
        {
            // if the letter is small find the words from small_letters array according to ASCII
            // if small letter is found takes its index and assign points to temp_Points array accourding to the index
            // adds tem_points value to int score to calculate the total score
            for (int f = 0; f < sizeof(small_letters); f++)
            {
                if (word[i] == small_letters[f])
                {
                    temp_points[i] = points[f];
                    score += temp_points[i];
                }
            }
        }
        // if the word contains anything other than aplhabets this helps to ignore them
        else
        {
            i += 1;
        }
    }
    // returns Score
    return score;

}





