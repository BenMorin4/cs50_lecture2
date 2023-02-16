#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2) {
        printf("Player 1 wins!");
    } else if (score2 > score1) {
        printf("Player 2 wins!");
    } else {
        printf("Tie!");
    }

}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int place = 0;
    int score = 0;
    int pre_score = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (toupper(word[i]) > 64 && toupper(word[i]) < 92) {
            pre_score = score;
            for (int n = 65; n < 91; n++) {
                if (toupper((word[i])) == n) {
                    place = n - 65;
                    score += POINTS[place];
                    if (score != pre_score) {
                        break;
                    }
                }
            }
        }
    }
    return score;
}