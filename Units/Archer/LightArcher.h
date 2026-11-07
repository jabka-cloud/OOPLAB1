#pragma once
#include "Archer.h"

class LightArcher : public Archer {
public:
    LightArcher();
    std::unique_ptr<Unit> clone() const override;
};
