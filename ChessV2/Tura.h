#pragma once
#include "Figure.h"
class Tura :
    public Figure
{
public:
    Tura(bool color);
    ~Tura() override;
    virtual string type() const override;
    virtual bool nextStroke(int _numberOfDirections, int& _x, int& _y) override;
};

