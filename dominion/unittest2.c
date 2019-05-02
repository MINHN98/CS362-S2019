#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

/*
*   adventurerEffect Unit Test
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
    
    printf("***********************Running adventurerEffect unit test...***********************\n");
    printf("---Initializing game...\n");
    result = initializeGame(numPlayers, kingdomCards, randomSeed, &G);
    printf ("initializeGame(4, kingdomCards, 2, &G) = %d\n", result);
    assert(result == 0); // assert no errors in creating the game
    printf("Hand size after initializeGame: %d\n", G.handCount[currentPlayer]);

    // add adventurer to hand
    printf("---Adding Adventurer to hand...\n");
    result = gainCard(adventurer, &G, 2, currentPlayer);
    printf ("gainCard(adventurer, &G, 2, currentPlayer) = %d\n", result);
    assert(result == 0); // assert no errors in gaining Adventurer card

    printf("---Playing Adventurer card...\n");
    result = adventurerEffect(currentPlayer, &G);
    printf ("adventurerEffect(currentPlayer, &G) = %d\n", result);
    
    printf("---Checking if player has 2 new cards in hand...\n");
    int handCount = G.handCount[currentPlayer];
    printf("Hand size after using Adventurer card: %d\n", G.handCount[currentPlayer]);
    assert(handCount == 8); // check if the player has 2 new cards in hand
    printf("Passed.\n");
    
    //Check if the top two cards in hand are treasure cards
    if (handCount == 8){
        int topCard = G.hand[currentPlayer][handCount-1]; //top card of hand is most recently drawn card.
        int secondTopCard = G.hand[currentPlayer][handCount-2];
        
        printf("---Checking if top if hand is treasure card...\n");
        assert(topCard == copper || topCard == silver || topCard == gold);
        printf("Passed.\n");
        printf("---Checking if second to top if hand is treasure card...\n");
        assert(secondTopCard == copper || secondTopCard == silver || secondTopCard == gold);
        printf("Passed.\n");
    }
    printf("-> SUCCESS: UNIT TESTS PASSED <-\n");

}