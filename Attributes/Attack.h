#pragma once
#include "Armor.h"

class Attack {
private:
    int damageValue;

public:
    explicit Attack(int damage);

    int calculateDamage(const Armor& targetArmor) const;
    int getDamageValue() const;
};

