#pragma once
#include "Figure.h"
class Ferz :
    public Figure
{
public:
    Ferz(bool color);
    ~Ferz() override;
    virtual string type() const override;
    virtual bool nextStroke(int _numberOfDirections, int& _x, int& _y) override;
};

