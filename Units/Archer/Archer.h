#pragma once
#include "Unit.h"

class Archer : public Unit {
protected:
    int range;
public:
    Archer(const std::string& unitName, int h, int arm, int att, int r)
        : Unit(unitName, h, arm, att), range(r) {
    }
    std::string getType() const override { return "Archer"; }
};
