#include <stdio.h>
#include <stdlib.h>
#include "cardhelpers.h"

card *make_card(int suit, int value)
{
  if ( suit>=0 && suit<=3 && value>=1 && value<=13){
  card *cardptr;
  cardptr = (card *)malloc(sizeof(card));
  cardptr->suit = suit;
  cardptr->value = value;
  return cardptr;
  } 
  return NULL;
    
}


deck *make_standard_deck()
{
  deck *ndeck;
  ndeck = (deck *)malloc(sizeof(deck));
  ndeck->num_cards = 52;
  ndeck->cards = malloc(52*sizeof(deck));
  int i = 0;
  for (int a = 0; a <=3; a++)
     { if (a==0){
	 for (int b = 1; b<=13; b++){
	   ndeck->cards[i]=*make_card(a, b);
	   i++;}
       }
       else if(a==1){
	 for (int b = 1; b<=13; b++){
	   ndeck->cards[i]=*make_card(a, b);
	   i++;}
       }
       else if(a==2){
	 for (int b = 1; b<=13; b++){
	   ndeck->cards[i]=*make_card(a, b);
	   i++;}
       }
       else if(a==3){
	 for (int b = 1; b<=13; b++){
	   ndeck->cards[i]=*make_card(a, b);
	   i++;}
       }
     }
     return ndeck; 
}


int compare(card *c1, card *c2)
{
  if (c1->value < c2->value)
    return -1;
  else if (c1->value == c2->value)
   {
    if (c1->suit < c2->suit)
      return -1;
    else if(c1->suit == c2->suit)
      return 0;
    else return 1;
  }
  else return 1;
}


int find_index(deck *d, int suit, int value)
{
  if ( suit>=0 && suit<=3 && value>=1 && value<=13){  
    for (int i=0;i<=d->num_cards;i++){
    if (d->cards[i].suit == suit && d->cards[i].value == value)
      return i;
  }
  }
  return -1;
}



void print_card(card *c)
{
	char *suitchars = "CDHS";
	char *valuechars = "WA23456789TJQK";
	if (c == NULL)
	{
		printf("Card is not allocated\n");
		return;
	}
	if ((c->suit < 0) || (c->suit > 3))
		printf("Invalid suit: %d\n",c->suit);
	else if ((c->value < 0) || (c->value > 13))
		printf("Invalid value: %d\n",c->value);
	else
		printf("%c %c ", suitchars[c->suit], valuechars[c->value]);
}

