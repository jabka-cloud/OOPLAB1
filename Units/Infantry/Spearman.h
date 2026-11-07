#pragma once
#include "Infantry.h"

class Spearman : public Infantry {
public:
    Spearman();
    std::unique_ptr<Unit> clone() const override;
};
