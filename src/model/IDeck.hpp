#ifndef IDECK_H
#define IDECK_H
#include "model/Card.hpp"
class IDeck{
	public:
		virtual Card getCard()=0;
		virtual void shuffle()=0;
};
#endif
