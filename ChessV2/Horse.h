#pragma once
#include "Figure.h"
class Horse :
    public Figure
{
public:
    Horse(bool color);
    ~Horse() override;
    virtual string type() const override;
    virtual bool nextStroke(int _numberOfDirections, int& _x, int& _y) override;
};

