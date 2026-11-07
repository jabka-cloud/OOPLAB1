#include "Spearman.h"

Spearman::Spearman() : Infantry("Spearman", 90, 10, 18) {}

std::unique_ptr<Unit> Spearman::clone() const {
    return std::make_unique<Spearman>(*this);
}
