#pragma once

class Armor {
private:
    int value;

public:
    explicit Armor(int startValue);

    int reduceDamage(int damage) const;
    int getValue() const;
};
