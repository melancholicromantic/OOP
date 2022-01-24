#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "Thing.h"

class CCircle : public Thing
{
protected:
    int x, y;
    int r = 100;
    bool marked = true;

public:
    CCircle(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void drow(Graphics^ g) override
    {
        g->DrawEllipse(Pens::Red, x - r/2, y - r/2, r, r);
        
        if (marked == true)
        {
            g->DrawEllipse(Pens::Blue, x - r/2, y - r/2, r, r);
        }
        else
        {
            g->DrawEllipse(Pens::Red, x - r/2, y - r/2, r, r);
        }
    }

    void select() override
    {
        marked = true;
    }

    void unselect() override
    {
        marked = false;
    }

    bool reach(int x, int y) override
    {
        if (((x - this->x ) * (x - this->x)) + ((y - this->y) * (y - this->y)) <= (r*r))
            return true;
        else
            return false;
    }

    bool is_select() override
    {
        return marked;
    }
};

