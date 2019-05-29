#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
*   mine Unit Test
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
    int bonus = 0;
    
    printf("***********************Running mine unit test...***********************\n");
    printf("---Initializing game...\n");
    result = initializeGame(numPlayers, kingdomCards, randomSeed, &G);
    printf("initializeGame(4, kingdomCards, 2, &G) = %d\n", result);
    assert(result == 0); // assert no errors in creating the game
    printf("Hand size after initializeGame: %d\n", G.handCount[currentPlayer]);
    
    // add mine to hand
    printf("---Adding mine to hand...\n");
    result = gainCard(mine, &G, 2, currentPlayer);
    printf("gainCard(mine, &G, 2, currentPlayer); = %d\n", result);
    assert(result == 0); // assert no errors in gaining mine card

    printf("---Playing mine card...\n");
    printf("Trashing copper for gold. Should return -1.\n");
    // handPos = card played (in 5th spot in array)
    result = cardEffect(mine, copper, gold, -1, &G, 5, &bonus);
    printf("cardEffect(mine, copper, gold, -1, &G, 5, &bonus) = %d\n", result); 
    //assert(result == -1);
    if(result == -1){
        printf("Passed.\n");
    }else{
        printf("FAILED: Copper can not be scrapped for gold\n");
    }

    //printf("-> SUCCESS: UNIT TESTS PASSED <-\n");
}
