#include "Attack.h"

Attack::Attack(int damage) : damageValue(damage < 0 ? 0 : damage) {}

int Attack::calculateDamage(const Armor& targetArmor) const {
    return targetArmor.reduceDamage(damageValue);
}

int Attack::getDamageValue() const {
    return damageValue;
}
