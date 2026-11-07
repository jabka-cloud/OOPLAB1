#pragma once
#include "Cavalry.h"

class Cataphract : public Cavalry {
public:
    Cataphract();
    std::unique_ptr<Unit> clone() const override;
};
