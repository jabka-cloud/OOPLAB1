#include "HorseArcher.h"

HorseArcher::HorseArcher() : Cavalry("HorseArcher", 90, 10, 22, 5) {}

std::unique_ptr<Unit> HorseArcher::clone() const {
    return std::make_unique<HorseArcher>(*this);
}
