#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
*   playSmithy Unit Test
*   int playSmithy(struct gameState *state, int handPos, int i, int currentPlayer)
*/

int main(){

    int result;

    int numPlayers = 4;
    int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
    int randomSeed = 2;

    struct gameState G;

    int currentPlayer = 0;    
    
    printf("***********************Running playSmithy unit test...***********************\n");
    printf("---Initializing game...\n");
    result = initializeGame(numPlayers, kingdomCards, randomSeed, &G);
    printf("initializeGame(4, kingdomCards, 2, &G) = %d\n", result);
    assert(result == 0); // assert no errors in creating the game
    printf("Hand size after initializeGame: %d\n", G.handCount[currentPlayer]);
    
    // add smithy to hand
    printf("---Adding Smithy to hand...\n");
    result = gainCard(smithy, &G, 2, currentPlayer);
    printf("gainCard(smithy, &G, 2, currentPlayer); = %d\n", result);
    assert(result == 0); // assert no errors in gaining Smithy card

    printf("---Playing Smithy card...\n");
    // handPos = card played (in 5th spot in array)
    result = playSmithy(&G, 5, 0, currentPlayer);
    printf("playSmithy(&G, 5, 0, currentPlayer) = %d\n", result);
    
    printf("---Checking if player has 3 new cards in hand...\n");
    printf("Hand size after using Smithy card: %d\n", G.handCount[currentPlayer]);
    //assert(G.handCount[currentPlayer] == 8); // check if the player has 3 new cards in hand
    if(G.handCount[currentPlayer] == 8){
        printf("Passed.\n");
    }else{
        printf("FAILED: Player does not have 3 new cards in hand.\n");
    }

    //printf("-> SUCCESS: UNIT TESTS PASSED <-\n");

}