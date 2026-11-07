#pragma once
#include "Cavalry.h"

class HorseArcher : public Cavalry {
public:
    HorseArcher();
    std::unique_ptr<Unit> clone() const override;
};
