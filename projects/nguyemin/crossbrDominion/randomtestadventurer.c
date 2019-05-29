#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
/*
*   Random test for playAdventurer function
*   Function definition: 
*   int playAdventurer(struct gameState *state, int drawntreasure, int currentPlayer, int cardDrawn, int z, int temphand[MAX_HAND])
*
*/
int testPlayAdventurer(int p, struct gameState *post);

int main () {

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

    struct gameState G;
    
    int n, i, p, result;
    SelectStream(2);
    PutSeed(4);
    printf ("*****RUNNING playAdventurer() RANDOM TESTS...*****\n");

    for (n = 0; n < 2000; n++) {
        printf ("---Test %d:\n", n+1);
        // Generate random game state
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        }

        // Random player
        p = floor(Random() * 4);

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
        testPlayAdventurer(p, &G);

        printf("\n");
    }

    return 0;
}


int testPlayAdventurer(int p, struct gameState *post){
    printf("TESTING PLAY ADVENTURER...\n");
    printf ("PLAYER NUMBER: %d\n", p);

    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

    int result;

    int initial_handsize = pre.handCount[p];
    printf("Initial Handsize: %d\n", initial_handsize);
    //
    int temphand[500];
    result = playAdventurer(post, 0, p, 0, 0, temphand);
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