#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
*   councilRoomEffect Unit Test
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
    
    printf("***********************Running councilRoomEffect unit test...***********************\n");
    printf("---Initializing game...\n");
    result = initializeGame(numPlayers, kingdomCards, randomSeed, &G);
    printf("initializeGame(4, kingdomCards, 2, &G) = %d\n", result);
    assert(result == 0); // assert no errors in creating the game
    printf("Hand size after initializeGame: %d\n", G.handCount[currentPlayer]);

    int initialNumBuys = G.numBuys;
    printf("Starting number of buys: %d\n", initialNumBuys);
    
    // add Council Room to hand
    printf("---Adding Council Room to hand...\n");
    result = gainCard(council_room, &G, 2, currentPlayer);
    printf("gainCard(council_room, &G, 2, currentPlayer); = %d\n", result);
    assert(result == 0); // assert no errors in gaining Council Room card

    printf("---Playing Council Room card...\n");
    // handPos = card played (in 5th spot in array)
    result = councilRoomEffect(5, currentPlayer, &G);
    printf("councilRoomEffect(5, currentPlayer, &G) = %d\n", result);

    printf("---Checking if player one more number of buys...\n");
    printf("Final number of buys: %d\n", G.numBuys);
    assert(G.numBuys == (initialNumBuys + 1)); // check if the player has 4 new cards in hand
    printf("Passed.\n");

    printf("---Checking if player has 4 new cards in hand...\n");
    printf("Hand size after using Council Room card: %d\n", G.handCount[currentPlayer]);
    //assert(G.handCount[currentPlayer] == 9); // check if the player has 4 new cards in hand
    if(G.handCount[currentPlayer] == 9){
        printf("Passed.\n");
    }else{
        printf("FAILLED: assert G.handCount[currentPlayer] == 9\n");
    }

    //printf("-> SUCCESS: UNIT TESTS PASSED <-\n");

}