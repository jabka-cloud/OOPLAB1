#pragma once
#include "Unit.h"

class Cavalry : public Unit {
protected:
    int speed;
public:
    Cavalry(const std::string& unitName, int h, int arm, int att, int s)
        : Unit(unitName, h, arm, att), speed(s) {
    }
    std::string getType() const override { return "Cavalry"; }
};
