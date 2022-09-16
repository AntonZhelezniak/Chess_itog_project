#include "Figure.h"

Figure::Figure(char symbol, int price, bool color, int numberOfDirections):
	symbol(symbol), 
	price(price), 
	color(color), 
	numberOfDirections(numberOfDirections)
{
}

Figure::~Figure()
{
}

char Figure::getSymbol() const
{
	return symbol;
}

bool Figure::getColor() const
{
	return color;
}

int Figure::getPrice() const
{
	return price;
}

int Figure::getNumberOfDirections() const
{
	return numberOfDirections;
}