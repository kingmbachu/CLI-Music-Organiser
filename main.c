#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SortAndShuffle.h" // Include the header file for function declarations

#define MAX_ARTISTS 4 // Maximum number of artists
#define MAX_SONGS_PER_ARTIST 3 // Maximum number of songs per artist
#define MAX_LENGTH 80 // Maximum character length for artist and song names

int main(void) {

    //print ASCII art
    printf("K   K  III  N   N  GGG\n");
    printf("K  K    I   NN  N  G\n");
    printf("KKK     I   N N N  G  GG\n");
    printf("K  K    I   N  NN  G   G\n");
    printf("K   K  III  N   N  GGG\n");

    char artists[MAX_ARTISTS][MAX_LENGTH]; // Stores artist/group names
    char allSongs[MAX_ARTISTS * MAX_SONGS_PER_ARTIST][MAX_LENGTH]; // Stores all songs across all artists
    char songs[MAX_ARTISTS][MAX_SONGS_PER_ARTIST][MAX_LENGTH]; // Stores songs per artist
    int numOfArtists = 0; // Counter for the number of artists
    int numSongsPerArtist[MAX_ARTISTS] = {0}; // Array to track how many songs each artist has
    int i, j;

    // Loop to collect artist and song names
    for (i = 0; i < MAX_ARTISTS; i++) {
        if (!insertSongs(songs[i], i + 1, artists, allSongs, &numOfArtists, numSongsPerArtist)) {
            break; // Stop collecting if the function signals to stop
        }
    }

    // Display entered artist and song data
    printf("\nYou entered:\n");
    for (i = 0; i < numOfArtists; i++) {
        printf("%s\n", artists[i]); // Print artist name
        for (j = 0; j < numSongsPerArtist[i]; j++) {
            printf("  %s\n", songs[i][j]); // Print songs under the artist
        }
    }

    // Calculate total number of songs
    int totalSongs = numOfArtists * MAX_SONGS_PER_ARTIST;

    // Sort all songs alphabetically
    sortSongs(allSongs, totalSongs);

    // Display sorted songs
    printf("\nSorted List of Songs:\n");
    for (i = 0; i < totalSongs; i++) {
        printf("%s\n", allSongs[i]);
    }

    // Shuffle the songs while ensuring no early repetition
    printf("\nShuffled List of Songs:\n");
    shuffleSongs(allSongs, totalSongs);



    return 0;
}
