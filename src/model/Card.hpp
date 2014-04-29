#ifndef CARD_HPP
#define CARD_HPP

enum class Suit
{
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES
};

enum class Rank
{
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE
};

struct Card
{
	public:
	Suit suit;
	Rank rank;
	Card(Suit, Rank);
	friend bool operator==(Card &a, Card &b);
};

#endif