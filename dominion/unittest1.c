#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
*   smithyEffect Unit Test
*
*/

int main(){

    int result;

    int numPlayers = 4;
    int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
    int randomSeed = 2;

    struct gameState G;

    int currentPlayer = 0;    
    
    printf("***********************Running smithyEffect unit test...***********************\n");
    printf("---Initializing game...\n");
    result = initializeGame(numPlayers, kingdomCards, randomSeed, &G);
    printf ("initializeGame(4, kingdomCards, 2, &G) = %d\n", result);
    assert(result == 0); // assert no errors in creating the game
    printf("Hand size after initializeGame: %d\n", G.handCount[currentPlayer]);
    
    // add smithy to hand
    printf("---Adding Smithy to hand...\n");
    result = gainCard(smithy, &G, 2, currentPlayer);
    printf("gainCard(smithy, &G, 2, currentPlayer); = %d\n", result);
    assert(result == 0); // assert no errors in gaining Smithy card

    printf("---Playing Smithy card...\n");
    // handPos = card played (in 5th spot in array)
    result = smithyEffect(5, currentPlayer, &G);
    printf("smithyEffect(5, currentPlayer, &G) = %d\n", result);
    
    printf("---Checking if player has 3 new cards in hand...\n");
    printf("Hand size after using Smithy card: %d\n", G.handCount[currentPlayer]);
    assert(G.handCount[currentPlayer] == 8); // check if the player has 3 new cards in hand
    printf("Passed.\n");

    printf("-> SUCCESS: UNIT TESTS PASSED <-\n");

}