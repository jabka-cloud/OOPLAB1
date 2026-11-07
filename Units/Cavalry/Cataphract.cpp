#include "Cataphract.h"

Cataphract::Cataphract() : Cavalry("Cataphract", 150, 40, 30, 2) {}

std::unique_ptr<Unit> Cataphract::clone() const {
    return std::make_unique<Cataphract>(*this);
}
