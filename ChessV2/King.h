#pragma once
#include "Figure.h"
class King :
    public Figure
{
public:
    King(bool color);
    ~King() override;
    virtual string type() const override;
    virtual bool nextStroke(int _numberOfDirections, int& _x, int& _y) override;
};

