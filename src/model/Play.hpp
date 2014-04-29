#ifndef PLAY_HPP
#define PLAY_HPP

#include <vector>
#include "Denomination.hpp"
#include "Card.hpp"
#include "Trick.hpp"

class Play
{
public:
	Play();
	void setTrump(Denomination);
	const std::vector<Trick> & getTricksView(); 
	void receiveCard(Card);
	Suit getLeadingSuit();
	int getCurrentTrickStartingPlayer();
	bool hasEnded();
	int getTricksWon();
private:
	Denomination trump;
	int currentStarting;
	std::vector<Trick> tricks;
	int tricksWon;
};

#endif