#ifndef TRICK_HPP
#define TRICK_HPP

#include <vector> 
#include "model/Card.hpp"
#include "model/Denomination.hpp"
#include "ui/IObservable.hpp"

namespace model {

class Trick : public ui::IObservable<Trick>
{
public:
	//Trick(Trick&) = delete;
	//Trick(Trick&&) = delete;
	Trick(Denomination);
	void addCard(Card);
	int getWinner() const;
	std::vector<Card> const & getCardsView() const;
	bool hasEnded() const;
	
private:
	bool compareCards(Card const & card1, Card const & card2) const; // (card 1 < card 2)
	bool isTrump(Suit suit) const;
	Denomination trump;
	std::vector<Card> cards;
};

}

#endif
