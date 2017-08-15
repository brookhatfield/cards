#ifndef CARD1HELPERS_H
#define CARD1HELPERS_H

typedef struct _card {
	int suit;
	int value;
} card;

typedef struct _deck {
	int num_cards;
	card *cards;
} deck;

card *make_card(int suit, int value);
deck *make_standard_deck();
int compare(card *c1, card *c2);
int find_index(deck *d, int suit, int value);
void print_card(card *c);

#endif
