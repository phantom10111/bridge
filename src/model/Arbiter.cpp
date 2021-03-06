
#include "model/Arbiter.hpp"

namespace model {

Arbiter::Arbiter(IPlayer& player,
	std::vector<Call> const & callsView,
	Play::Tricks const & tricksView) :
	player(player), callsView(callsView), tricksView(tricksView)
{
	player.connectGameState(hand.getCardsView(), callsView, tricksView);
}

void Arbiter::addCard(Card c)
{
	hand.addCard(c);
}

void Arbiter::makeCall(Bidding &bidding)
{
	for(;;){
		Call call = player.getCall();
		if(bidding.canGetCall(call)){
			bidding.getCall(call);
			break;
		}
	}
}

int Arbiter::getHonorBonus(Denomination den) const
{
	return hand.getHonorBonus(den);
}

bool Arbiter::checkMoveValidity(Play &play, Card &card, Hand &hand)
{
	if(!hand.hasCard(card)) {
		return false;
	}
	auto & tricks = play.getTricksView(); 
	if (tricks.empty() || tricks.back().getCardsView().size() == 4) {
		return true;
	} 
	auto & cards = tricks.back().getCardsView();
	Card firstCard = cards.front();
	if (hand.hasSuit(firstCard.suit) && firstCard.suit != card.suit) {
		return false;
	}
	return true;
}
	

void Arbiter::makeMove(Play &play) 
{
	for(;;){
		Card card = player.getCard();
		if(checkMoveValidity(play, card, hand)){
			hand.removeCard(card);
			play.receiveCard(card);
			break;
		}
	}
}

void Arbiter::makeDummyMove(Play &play) 
{
	for(;;){
		Card card = player.getDummyCard();
		if(checkMoveValidity(play, card, *dummyHand)){
			dummyHand->removeCard(card);
			play.receiveCard(card);
			break;
		}
	}
}

void Arbiter::passDummyControl(Arbiter &from, Arbiter &to)
{
	to.dummyHand = &from.hand;
}

void Arbiter::connectDummyView(Arbiter &from)
{
	player.connectDummyHand(from.hand.getCardsView());
}

}
