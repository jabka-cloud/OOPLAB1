#include "Swordsman.h"

Swordsman::Swordsman() : Infantry("Swordsman", 100, 20, 15) {}

std::unique_ptr<Unit> Swordsman::clone() const {
    return std::make_unique<Swordsman>(*this);
}
