#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
/*
*   Random test for adventurerEffect function
*   Function definition: 
*   int adventurerEffect(int currentPlayer, struct gameState *state)
*
*/
int testAdventurerEffect(int p, struct gameState *post);

int main () {

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

    struct gameState G;
    
    int n, i, p, result;
    SelectStream(2);
    PutSeed(4);
    printf ("*****RUNNING RANDOM TESTS...*****\n");

    for (n = 0; n < 2000; n++) {
        printf ("---Test %d:\n", n+1);
        // Generate random game state
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        }

        // Random player
        p = floor(Random() * 4);
        printf ("PLAYER NUMBER: %d\n", p);

        // Random deck
        G.deckCount[p] = floor(Random() * MAX_DECK);
        for(i = 0; i < G.deckCount[p]; i++){
            int randCard = (rand() % (26 - 0 + 1)) + 0; 
            G.deck[p][i] = randCard;
        }

        // Random discard
        G.discardCount[p] = floor(Random() * MAX_DECK);
        for(i = 0; i < G.discardCount[p]; i++){
            int randCard = (rand() % (26 - 0 + 1)) + 0; 
            G.discard[p][i] = randCard;
        }

        // Random hand
        G.handCount[p] = floor(Random() * MAX_HAND);
        for(i = 0; i < G.handCount[p]; i++){
            int randCard = (rand() % (26 - 0 + 1)) + 0; 
            G.hand[p][i] = randCard;
        }

        G.supplyCount[adventurer] = (rand() % (50 - 1 + 1)) + 1;

        // Gain card we are testing
        gainCard(adventurer, &G, 2, p);

        // Run test function
        testAdventurerEffect(p, &G);

        printf("\n");
    }

    // printf("---TESTING using initial initializeGame() states:\n");
    // for (n = 0; n < 2000; n++) {
    //     printf("****ITERATION %d\n", n+1);
    //     //(rand() % (upper - lower + 1)) + lower; 

    //     // random [2 , MAX_PLAYERS]
    //     int numPlayers = (rand() % (MAX_PLAYERS - 2 + 1)) + 2; 
    //     // random [1 , 999999999]
    //     int randomSeed = (rand() % (999999999 - 1 + 1)) + 1; 
    //     printf("Game Configuration:\n -Number of players: %d\n -Seed: %d\n", numPlayers, randomSeed);

    //     result = initializeGame(numPlayers, k, randomSeed, &G);
    //     assert(result == 0);

    //     int randomPlayer = (rand() % ((numPlayers - 1) - 0 + 1)) + 0; 
    //     printf("Test Player: %d\n", randomPlayer);
    //     gainCard(smithy, &G, 2, randomPlayer);
    //     result = testAdventurerEffect(randomPlayer, &G);
    //     printf("\n");
    // }


    // printf("---EDGE CASE: TESTING when there are no cards in current deck:\n");
    // for (n = 0; n < 10; n++) {
    //     printf("****ITERATION %d\n", n+1);
    //     //(rand() % (upper - lower + 1)) + lower; 

    //     // random [2 , MAX_PLAYERS]
    //     int numPlayers = (rand() % (MAX_PLAYERS - 2 + 1)) + 2; 
    //     // random [1 , 999999999]
    //     int randomSeed = (rand() % (999999999 - 1 + 1)) + 1; 
    //     printf("Game Configuration:\n -Number of players: %d\n -Seed: %d\n", numPlayers, randomSeed);

    //     result = initializeGame(numPlayers, k, randomSeed, &G);
    //     assert(result == 0);

    //     int randomPlayer = (rand() % ((numPlayers - 1) - 0 + 1)) + 0; 
    //     printf("Test Player: %d\n", randomPlayer);

    //     // Move cards from deck to discard
    //     memcpy(G.discard[randomPlayer], G.deck[randomPlayer], sizeof(G.deck[randomPlayer]));
    //     memset(G.deck[randomPlayer], 0, sizeof(G.deck[randomPlayer]));
    //     G.discardCount[randomPlayer] = G.deckCount[randomPlayer];
    //     G.deckCount[randomPlayer] = 0;

    //     gainCard(adventurer, &G, 2, randomPlayer);
    //     result = testAdventurerEffect(randomPlayer, &G);
    //     printf("\n");
    // }

    //printf("TESTS PASSED!\n");
    return 0;
}


int testAdventurerEffect(int p, struct gameState *post){
    printf("TESTING ADVENTURER EFFECT...\n");
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

    int result;

    int initial_handsize = pre.handCount[p];
    printf("Initial Handsize: %d\n", initial_handsize);

    result = adventurerEffect(p, post);
    assert(result == 0);

    int final_handsize = post->handCount[p];
    printf("Final Handsize: %d\n", final_handsize);

    //assert(final_handsize == (initial_handsize+2));
    if (final_handsize == (initial_handsize+2)){
        printf("PASSED.\n");
    }else{
        printf("FAILED.\n");
    }

    return 0;
}