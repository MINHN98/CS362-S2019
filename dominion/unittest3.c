#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
*   greatHallEffect Unit Test
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
    
    printf("***********************Running greatHallEffect unit test...***********************\n");
    printf("---Initializing game...\n");
    result = initializeGame(numPlayers, kingdomCards, randomSeed, &G);
    printf ("initializeGame(4, kingdomCards, 2, &G) = %d\n", result);
    assert(result == 0); // assert no errors in creating the game
    printf("Hand size after initializeGame: %d\n", G.handCount[currentPlayer]);
    
    int initialNumActions = G.numActions;
    printf("Starting number of actions: %d\n", G.numActions);

    // add smithy to hand
    printf("---Adding Great Hall to hand...\n");
    result = gainCard(great_hall, &G, 2, currentPlayer);
    printf ("gainCard(great_hall, &G, 2, currentPlayer); = %d\n", result);
    assert(result == 0); // assert no errors in gaining great_hall card


    printf("---Playing Great Hall card...\n");
    // handPos = card played (in 5th spot in array), currentPlayer = 0
    result = greatHallEffect(5, currentPlayer, &G);
    printf ("greatHallEffect(5, currentPlayer, &G) = %d\n", result);
    
    printf("---Checking if player has 1 new card in hand...\n");
    printf("Hand size after using Great Hall card: %d\n", G.handCount[currentPlayer]);
    assert(G.handCount[currentPlayer] == 6); // check if the player has 1 new card in hand
    printf("Passed.\n");

    printf("---Checking if numActions incremented...\n");
    printf("Final number of actions: %d\n", G.numActions);
    assert(G.numActions == (initialNumActions + 1)); // check if numActions incremented
    printf("Passed.\n");

    printf("-> SUCCESS: UNIT TESTS PASSED <-\n");

}