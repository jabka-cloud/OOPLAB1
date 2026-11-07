#include "InfantryFactory.h"
#include "Swordsman.h"
#include "Spearman.h"
#include <stdexcept>

std::unique_ptr<Unit> InfantryFactory::createUnit(UnitType type) const {
    if (type == UnitType::Swordsman) return std::make_unique<Swordsman>();
    if (type == UnitType::Spearman) return std::make_unique<Spearman>();
    throw std::invalid_argument("Unknown infantry type");
}