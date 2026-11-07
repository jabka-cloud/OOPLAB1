#pragma once
#include "Infantry.h"

class Swordsman : public Infantry {
public:
    Swordsman();
    std::unique_ptr<Unit> clone() const override;
};
