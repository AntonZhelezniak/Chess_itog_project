#pragma once
#include "Figure.h"
class Slon :
    public Figure
{
public:
    Slon(bool color);
    ~Slon() override;
    virtual string type() const override;
    virtual bool nextStroke(int _numberOfDirections, int& _x, int& _y) override;
};

