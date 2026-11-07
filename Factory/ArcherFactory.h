#pragma once
#include "UnitFactory.h"

class ArcherFactory : public UnitFactory {
public:
    std::unique_ptr<Unit> createUnit(UnitType type) const override;
};