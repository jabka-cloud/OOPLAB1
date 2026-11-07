#pragma once
#include <memory>
#include "Unit.h"

enum class UnitType {
    Swordsman,
    Spearman,
    LightArcher,
    HeavyArcher,
    Cataphract,
    HorseArcher
};

class UnitFactory {
public:
    virtual ~UnitFactory() = default;
    virtual std::unique_ptr<Unit> createUnit(UnitType type) const = 0;
};
