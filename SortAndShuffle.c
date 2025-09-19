#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "SortAndShuffle.h" // Include the function declarations

// Function to compare two strings for sorting
int compareSongs(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

// Function to insert songs for each artist
int insertSongs(char songsArtist[][MAX_LENGTH], int artistNumber, char artists[][MAX_LENGTH], char allSongs[][MAX_LENGTH], int *numOfArtists, int numSongsPerArtist[]) {
    int j;
    int allSongsIdx = (artistNumber - 1) * MAX_SONGS_PER_ARTIST; // Calculate starting index in allSongs array

    // Prompt user to enter an artist name
    do {
        printf("Insert an artist/group name:\n");
        fflush(stdout);
        fgets(artists[artistNumber - 1], MAX_LENGTH, stdin);
        artists[artistNumber - 1][strlen(artists[artistNumber - 1]) - 1] = '\0';  // Remove newline character

        // If the user enters an empty name after the first artist, stop the process
        if (artists[artistNumber - 1][0] == '\0' && artistNumber > 1) {
            return 1;
        }
    } while (artists[artistNumber - 1][0] == '\0');

    // Collect song names for the artist
    for (j = 1; j <= MAX_SONGS_PER_ARTIST; j++) {
        printf("Insert song %d for %s\n", j, artists[artistNumber - 1]);
        fflush(stdout);
        fgets(songsArtist[j - 1], MAX_LENGTH, stdin);
        songsArtist[j - 1][strlen(songsArtist[j - 1]) - 1] = '\0'; // Remove newline character

        // Store song in allSongs array
        strcpy(allSongs[allSongsIdx++], songsArtist[j - 1]);

        // Stop collecting if the input is empty (except first song)
        if (j != 1 && songsArtist[j - 1][0] == '\0') {
            break;
        }
    }

    // Store number of songs for this artist
    numSongsPerArtist[artistNumber - 1] = j - 1;
    (*numOfArtists)++; // Increment artist count
    return 1;
}

// Function to sort songs alphabetically
void sortSongs(char allSongs[][MAX_LENGTH], int numOfSongs) {
    qsort(allSongs, numOfSongs, sizeof(allSongs[0]), compareSongs);
}

// Function to shuffle songs while ensuring no repetition within 5 positions
void shuffleSongs(char songsToBeShuffled[][MAX_LENGTH], int numOfSongs) {
    int extendedSize = numOfSongs * 2; // Double the list so each song appears twice
    char extendedSongs[extendedSize][MAX_LENGTH]; // Array to store extended list
    char finalShuffled[extendedSize][MAX_LENGTH]; // Array for final shuffled list
    int placed[extendedSize]; // Array to track which songs have been placed
    int i, j, idx;

    srand(time(NULL)); // Seed random generator

    // Step 1: Duplicate the list so each song appears twice
    for (i = 0; i < extendedSize; i++) {
        strcpy(extendedSongs[i], songsToBeShuffled[i % numOfSongs]);
    }

    // Step 2: Shuffle using Fisher-Yates algorithm
    for (i = extendedSize - 1; i > 0; i--) {
        j = rand() % (i + 1);
        if (j != i) {
            char temp[MAX_LENGTH];
            strcpy(temp, extendedSongs[i]);
            strcpy(extendedSongs[i], extendedSongs[j]);
            strcpy(extendedSongs[j], temp);
        }
    }

    // Step 3: Arrange ensuring no song repeats within 5 positions
    memset(placed, 0, sizeof(placed));

    for (i = 0; i < extendedSize; i++) {
        // Find a valid song that isn't in the last 5 positions
        do {
            idx = rand() % extendedSize;
        } while (placed[idx] ||
                 (i >= 5 &&
                  (strcmp(extendedSongs[idx], finalShuffled[i - 1]) == 0 ||
                   strcmp(extendedSongs[idx], finalShuffled[i - 2]) == 0 ||
                   strcmp(extendedSongs[idx], finalShuffled[i - 3]) == 0 ||
                   strcmp(extendedSongs[idx], finalShuffled[i - 4]) == 0 ||
                   strcmp(extendedSongs[idx], finalShuffled[i - 5]) == 0)));

        // Assign the valid song
        strcpy(finalShuffled[i], extendedSongs[idx]);
        placed[idx] = 1;
    }

    // Step 4: Print the shuffled playlist
    for (i = 0; i < extendedSize; i++) {
        printf("%s\n", finalShuffled[i]);
    }
}
