#include "HeavyArcher.h"

HeavyArcher::HeavyArcher() : Archer("HeavyArcher", 80, 15, 20, 3) {}

std::unique_ptr<Unit> HeavyArcher::clone() const {
    return std::make_unique<HeavyArcher>(*this);
}
