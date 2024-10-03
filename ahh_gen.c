#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// Function to read words from a file into an array
int read_words(const char *filename, char words[][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    int count = 0;
    while (fgets(words[count], MAX_WORD_LENGTH, file)) {
        // Remove newline character
        words[count][strcspn(words[count], "\n")] = '\0';
        count++;
        if (count >= MAX_WORDS) {
            break;
        }
    }

    fclose(file);
    return count;
}

// Function to select a random word from the array
char* select_random_word(char words[][MAX_WORD_LENGTH], int count) {
    int index = rand() % count;
    return words[index];
}

int main() {
    char adjectives[MAX_WORDS][MAX_WORD_LENGTH];
    char nouns[MAX_WORDS][MAX_WORD_LENGTH];

    // Seed the random number generator
    srand(time(NULL));

    // Read adjectives and nouns from files
    int adj_count = read_words("./dict/adjectives.txt", adjectives);
    int noun_count = read_words("./dict/nouns.txt", nouns);

    if (adj_count == -1 || noun_count == -1) {
        return 1;
    }

    // Select a random adjective and noun
    char *random_adjective = select_random_word(adjectives, adj_count);
    char *random_noun = select_random_word(nouns, noun_count);

    // Print the random combination
    printf("%s ahh %s 😭\n", random_adjective, random_noun);

    return 0;
}

