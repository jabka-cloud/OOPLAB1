#include "CavalryFactory.h"
#include "Cataphract.h"
#include "HorseArcher.h"
#include <stdexcept>

std::unique_ptr<Unit> CavalryFactory::createUnit(UnitType type) const {
    if (type == UnitType::Cataphract) return std::make_unique<Cataphract>();
    if (type == UnitType::HorseArcher) return std::make_unique<HorseArcher>();
    throw std::invalid_argument("Unknown cavalry type");
}
