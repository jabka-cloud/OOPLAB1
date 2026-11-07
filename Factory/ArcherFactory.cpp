#include "ArcherFactory.h"
#include "LightArcher.h"
#include "HeavyArcher.h"
#include <stdexcept>

std::unique_ptr<Unit> ArcherFactory::createUnit(UnitType type) const {
    if (type == UnitType::LightArcher) return std::make_unique<LightArcher>();
    if (type == UnitType::HeavyArcher) return std::make_unique<HeavyArcher>();
    throw std::invalid_argument("Unknown archer type");
}