#pragma once
#include "Figure.h"
class Peshka :
    public Figure
{
    bool firstStroke;
    bool playerColor;
public:
    Peshka(bool color, bool _playerColor);
    ~Peshka() override;
    virtual string type() const override;
    virtual bool nextStroke(int _numberOfDirections, int& _x, int& _y) override;

    void setFirstStroke();
};

