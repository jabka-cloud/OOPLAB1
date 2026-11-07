#pragma once
#include "UnitFactory.h"

class InfantryFactory : public UnitFactory {
public:
    std::unique_ptr<Unit> createUnit(UnitType type) const override;
};