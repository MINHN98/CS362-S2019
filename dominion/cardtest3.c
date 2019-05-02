#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
*   gardens Unit Test
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
    
    printf("***********************Running gardens unit test...***********************\n");
    printf("---Initializing game...\n");
    result = initializeGame(numPlayers, kingdomCards, randomSeed, &G);
    printf("initializeGame(4, kingdomCards, 2, &G) = %d\n", result);
    assert(result == 0); // assert no errors in creating the game
    printf("Hand size after initializeGame: %d\n", G.handCount[currentPlayer]);
    
    // add gardens to hand
    printf("---Adding gardens to hand...\n");
    result = gainCard(gardens, &G, 2, currentPlayer);
    printf("gainCard(gardens, &G, 2, currentPlayer); = %d\n", result);
    assert(result == 0); // assert no errors in gaining gardens card

    printf("---Playing gardens card...\n");
    // handPos = card played (in 5th spot in array)
    result = cardEffect(gardens, -1, -1, -1, &G, 5, &bonus);
    printf("cardEffect(gardens, -1, -1, -1, &G, 5, &bonus) = %d\n", result); 
    //assert(result == 0);
    if(result == 0){
        printf("Passed.\n");
    }else{
        printf("FAILED: Function did not return 0.\n");
    }

    //printf("-> SUCCESS: UNIT TESTS PASSED <-\n");
}
