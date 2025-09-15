# CLI-Music-Organiser
// Header files and Constants
#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"
#define MAX_LENGTH 80





void sortArtists2(char unsortedArtists[][80] , int numOfArtists, char allSongs[][80], char newArray[][80]){

    int i, step;
    char swap[MAX_LENGTH];

    int length = numOfArtists;



    // First populate new array with all artists in unsorted array (newArray is the new sortedArray)

    for (i = 0; i < length; i++){

        strcpy(newArray[i], unsortedArtists[i]);

    }

    // iterates from each artist in the array (as a starting point to compare from that current artist to the rest in the array)
    for (step = 0 ; step < ( length - 1 ); step++)
            {
                // the rest of the artists to which the current artist is being compared to
                // the limit of the for loop decreases as step increases (i.e. as we near the end of the array)
                for (i = 0; i < length - step - 1; i++)
                {
                    if (strcmp(unsortedArtists[i], unsortedArtists[i+1]) > 0 )
                    {
                        // swap is used as a placeholder for sortedArtists[i]
                        strcpy(swap,unsortedArtists[i]);
                        // sortedArtists[i] is replaced with value of next index
                        strcpy(newArray[i], unsortedArtists[i+1]);
                        // next index is given value in placeholder swap
                        strcpy(newArray[i+1], swap);


                    }
                }

            }

}


void sortSongs2(char songsOfAnArtist[][80], int numOfArtists, char artists[][80], int numSongsPerArtist[], int artistNumber){
    int i, step;
        char swap[MAX_LENGTH];
        int length = numSongsPerArtist;
        int allSongsIdx = 0;

        // Assigns a value to allSongsIdx depending on which artistNumber it is
        // This is so we can match up the artists with their corresponding songs

        if (artistNumber == 2){
            allSongsIdx = 3;

        }
        if (artistNumber == 3){
            allSongsIdx = 6;
        }
        if (artistNumber == 4){
            allSongsIdx = 9;
        }




        // Bubble sort Algorithm
        i = allSongsIdx;
        // iterates from each song in the array (as a starting point to compare from that current song to the rest in the array)
        for (step = 0 ; step < ( length - 1 ); step++)
        {
            // the rest of the songs to which the current song is being compared to
            // the limit of the for loop decreases as step increases (i.e. as we near the end of the array)
            for (i = allSongsIdx; i < (length - step - 1) + allSongsIdx; i++)
                {
                    if (strcmp(songsOfAnArtist[i], songsOfAnArtist[i+1]) > 0 )
                    {
                        // swap is used as a placeholder for songsOfAnArtist[i]
                        strcpy(swap, songsOfAnArtist[i]);
                        // songsOfAnArtist[i] is replaced with value of next index
                        strcpy(songsOfAnArtist[i], songsOfAnArtist[i+1]);
                        // next index is given value in placeholder swap
                        strcpy(songsOfAnArtist[i+1], swap);
                    }
                }

        }





}

void shuffleSongs2(char songsToBeShuffled[][80], int numOfSongs){

    int n, i, j;
    char swap[MAX_LENGTH];
    srand(time(NULL));

    n = numOfSongs;

    // Fisher Yates Algorithm
    for (i = 1; i < n; i++)
    {
        j = rand()%(i+1);
        if (j!= i){

            strcpy(swap, songsToBeShuffled[j]);
            strcpy(songsToBeShuffled[j], songsToBeShuffled[i]);
            strcpy(songsToBeShuffled[i], swap);

        }
    }

    // Shuffle check

    if (n < 12){
        printf("Shuffle works best with 12 songs\n");
    }
    else {
        int shuffleRepeatValue = shuffleRepeat(songsToBeShuffled, n);

        // We continue shuffling while the shuffleRepeatValue from the shuffleRepeat function doesn't return '-1'
        while (shuffleRepeatValue != -1){

            for (int k = shuffleRepeatValue; k < n; k++){
                j = rand()%(k+1);
                if (j != k){
                    strcpy(swap, songsToBeShuffled[j]);
                    strcpy(songsToBeShuffled[j], songsToBeShuffled[k]);
                    strcpy(songsToBeShuffled[k],swap);
                }
            }
            shuffleRepeatValue = shuffleRepeat(songsToBeShuffled, n);
        }
    }








    // Shuffled songs are printed

    for (i = 0; i < n; i++){

        printf("%s\n", songsToBeShuffled[i]);
        fflush(stdout);

    }

}

int shuffleRepeat (char songsToBeShuffled[][MAX_LENGTH], int numOfSongs){
    int i, j, n, repeat;

    n = numOfSongs;

    // start with first song and compare to all songs that are within 5 songs distance
    // only increments once we have checked all five following songs
    for (i = 0; i < n; i++){
        repeat = 0;

        for (j = i + 1; j < i + 6 && j < n; j++){
            // We check if the two songs are equal, if so we have found a repeat
            if (strcmp(songsToBeShuffled[i],songsToBeShuffled[j]) == 0){
                repeat = 1;
                break;
            }
        }

        if (repeat == 1){
            return j;
        }

    }
    return -1;
}



int main(void)
{
    int length;
    //The array containing artists names
    char artists[4][80];
    //The array containing the sorted artists
    char sortedArtists[4][80];
    //Songs for Artist 1
    char songsArtist1[3][80];
    //Songs for Artist 2
    char songsArtist2[3][80];
    //Songs for Artist 3
    char songsArtist3[3][80];
    //Songs for Artist 4
    char songsArtist4[3][80];
    // All songs from each artist
    char allSongs[12][80];
    //The total number of artists (Note it can be less than 4)
    int numOfArtists =0;
    //The total number of songs for each artist (Note that less than 3 songs can be provided for each artist)
    int numSongsPerArtist[4] = {0, 0, 0, 0};

    /*
    * Use here functions that you should implement to insert artists and songs from the standard input.
    * Note that you also need to track the number of artists and the number of songs for each artist.
    */



    insertSongs(songsArtist1, 1, artists, allSongs ,&numOfArtists, numSongsPerArtist);
    //if (){} -- To stop adding artists
    insertSongs(songsArtist2, 2, artists, allSongs ,&numOfArtists, numSongsPerArtist);
    //if (){}
    insertSongs(songsArtist3, 3, artists, allSongs ,&numOfArtists, numSongsPerArtist);
    //if (){}
    insertSongs(songsArtist4, 4, artists, allSongs ,&numOfArtists, numSongsPerArtist);

    length = sizeof(artists)/sizeof(artists[0]);



    /*
     * Use here the function sortArtists to sort the array of the artists and sortSongs to sort the songs of each artist
     * Print each artist (alphabetically) and for each of them print the list of songs sorted alphabetically
     */

    sortArtists2(artists, numOfArtists, allSongs, sortedArtists);

    // Sorts songs for their corresponding artist
    printf("Sorted list of songs:\n");
    fflush(stdout);
    sortSongs2(allSongs, numOfArtists,artists[0], numSongsPerArtist[0], 1);
    sortSongs2(allSongs, numOfArtists,artists[1], numSongsPerArtist[1], 2);
    sortSongs2(allSongs, numOfArtists,artists[2], numSongsPerArtist[2], 3);
    sortSongs2(allSongs, numOfArtists,artists[3], numSongsPerArtist[3], 4);


    // print out artists sorted with list of their own songs


    for (int    i= 0; i < numOfArtists; i++){

        printf("%s\n",sortedArtists[i]);

        for (int j = 0; j < numOfArtists; j++){

            if (strcmp(sortedArtists[i], artists[j]) == 0){
                int k;
                int allSongsIdx = 0;

                if (j== 1){
                    allSongsIdx = 3;
                }
                if (j== 2){
                    allSongsIdx = 6;
                }
                if (j == 3){
                    allSongsIdx = 9;
                }

                k = allSongsIdx;

                while ( k< allSongsIdx + numSongsPerArtist[j]){

                    printf("\t -%s\n", allSongs[k]);
                    fflush(stdout);

                    k++;
                }
            }

        }

    }


    printf("Shuffled Playlist\n");
    fflush(stdout);

    int totalSongNum = 0;

    // To change totalSongNum for numSongsPerArtist
    for (int i = 0; i < 4; i++)
    {

        totalSongNum += numSongsPerArtist[i];

    }


    // Attaches artist name to its song
    for (int i = 0; i < totalSongNum ; i++){

        char temp[MAX_LENGTH];
        char tempArtist[MAX_LENGTH];

        if ( i < 3){
            // copying current artist to a temporary array
            strcpy(tempArtist, artists[0]);
            strcpy(temp, strcat(tempArtist, " - "));
            strcpy(allSongs[i],strcat(temp ,allSongs[i]));
        }

        if (i > 2 && i < 6){
            // copying current artist to a temporary array
            strcpy(tempArtist, artists[1]);
            strcpy(temp, strcat(tempArtist, " - "));
            strcpy(allSongs[i],strcat(temp ,allSongs[i]));
        }
        if (i > 5 && i < 9){
            // copying current artist to a temporary array
            strcpy(tempArtist, artists[2]);
            strcpy(temp, strcat(tempArtist, " - "));
            strcpy(allSongs[i],strcat(temp ,allSongs[i]));
        }
        if (i > 8 && i < 12){
            // copying current artist to a temporary array
            strcpy(tempArtist, artists[3]);
            strcpy(temp, strcat(tempArtist, " - "));
            strcpy(allSongs[i],strcat(temp ,allSongs[i]));
        }

    }



    /*
     * Use here the function shuffleSongs to shuffle all the songs
     * Print the list of shuffled songs
     */

    for (int i = 0; i < 2; i++){
        shuffleSongs2(allSongs, totalSongNum);
    }



  return 0;
}
