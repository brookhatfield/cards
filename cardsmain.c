#include <stdio.h>
#include <stdlib.h>
#include "cardhelpers.h"

int main(int argc, char *argv[])
{

	card **hand;
	deck *fulldeck;
	int i, j, k;

	/* create an array of card pointers */
	hand = (card **)malloc(sizeof(card *)*5);
	/* make a card for each one */
	for(i=0;i<5;i++)
		hand[i] = make_card(i%4, (i*17)%14);
	
	/* print out the cards in the hand */
	printf("Hand: ");
	for(i=0;i<5;i++)
 		print_card(hand[i]);
	printf("\n"); 

	/* make a standard deck of cards */
	fulldeck = make_standard_deck();
	if (fulldeck == NULL)
	{
		printf("make_standard_deck not yet implemented ... exiting\n");
		exit(0);
	}
	/* print out all of the cards */
	for(i=0;i<fulldeck->num_cards;)
		for(j=0;j<13 && i<fulldeck->num_cards;j++,i++)
		 	print_card(&(fulldeck->cards[i]));
	

	/* compare some cards */
	printf("Compare: ");
	print_card(&(fulldeck->cards[5]));
	print_card(&(fulldeck->cards[17]));
	printf(": %d\n",compare(&(fulldeck->cards[5]),&(fulldeck->cards[17])));

	printf("find index: C 5: %d", find_index(fulldeck,0,5));

}
