#pragma once
#include "Unit.h"

class Infantry : public Unit {
public:
    using Unit::Unit;
    std::string getType() const override { return "Infantry"; }
};
