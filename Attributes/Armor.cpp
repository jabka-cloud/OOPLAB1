#include "Armor.h"

Armor::Armor(int startValue) : value(startValue < 0 ? 0 : startValue) {}

int Armor::reduceDamage(int damage) const {
    int finalDamage = damage - value;
    return finalDamage < 0 ? 0 : finalDamage;
}

int Armor::getValue() const {
    return value;
}
