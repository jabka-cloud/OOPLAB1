#include "Health.h"

Health::Health(int startValue) : value(startValue < 0 ? 0 : startValue) {}

void Health::decrease(int amount) {
    if (amount > 0) {
        value -= amount;
        if (value < 0) value = 0;
    }
}

void Health::increase(int amount) {
    if (amount > 0) {
        value += amount;
    }
}

bool Health::isZero() const {
    return value == 0;
}

int Health::getValue() const {
    return value;
}
