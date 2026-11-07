#include "LightArcher.h"

LightArcher::LightArcher() : Archer("LightArcher", 60, 5, 25, 4) {}

std::unique_ptr<Unit> LightArcher::clone() const {
    return std::make_unique<LightArcher>(*this);
}
    