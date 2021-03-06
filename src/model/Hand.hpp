#ifndef HAND_HPP
#define HAND_HPP

#include "model/Card.hpp"
#include "model/Denomination.hpp"
#include "ui/IObservable.hpp"
#include <vector>

namespace model {

class Hand : public ui::IObservable<Hand> {
private:
	std::vector<Card> cards;
public:
	Hand() = default;
	Hand (Hand&) = delete;
	Hand (Hand&&) = delete;
	std::vector<Card> const &getCardsView() const;
	void addCard(Card c);
	void removeCard(Card c);
	bool hasSuit(Suit suit);
	bool hasCard(Card card);
	int getHonorBonus(Denomination) const;
};

}

#endif
