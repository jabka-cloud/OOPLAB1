#include "Unit.h"

Unit::Unit(const std::string& unitName, int h, int arm, int att, int startX, int startY)
    : name(unitName), health(h), armor(arm), attack(att), x(startX), y(startY) {
}

void Unit::move(int dx, int dy) {
    x += dx;
    y += dy;
}

void Unit::takeDamage(int damage) {
    int actualDamage = armor.reduceDamage(damage);
    health.decrease(actualDamage);
}
