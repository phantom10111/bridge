#ifndef UI_TEXT_PRINTER_HPP
#define UI_TEXT_PRINTER_HPP

#include <iostream>
#include "model/Card.hpp"
#include "model/Trick.hpp"

namespace ui
{
namespace text
{

class Printer
{
public:
	static void print(model::Suit);
	static void print(model::Rank);
	static void print(model::Card);
	static void print(model::Trick const &);
};

}
}
#endif