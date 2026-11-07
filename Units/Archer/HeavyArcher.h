#pragma once
#include "Archer.h"

class HeavyArcher : public Archer {
public:
    HeavyArcher();
    std::unique_ptr<Unit> clone() const override;
};
