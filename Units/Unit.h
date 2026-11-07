#pragma once
#include <string>
#include <memory>
#include "Health.h"
#include "Armor.h"
#include "Attack.h"

class Unit {
protected:
    std::string name;
    Health health;
    Armor armor;
    Attack attack;
    int x, y;

public:
    Unit(const std::string& unitName, int h, int arm, int att, int startX = 0, int startY = 0);
    virtual ~Unit() = default;

    virtual std::unique_ptr<Unit> clone() const = 0;
    virtual std::string getType() const = 0;

    int getX() const { return x; }
    int getY() const { return y; }
    void setCoordinates(int newX, int newY) { x = newX; y = newY; }

    void move(int dx, int dy);
    void takeDamage(int damage);

    std::string getName() const { return name; }
    int getHealthValue() const { return health.getValue(); }
    bool isAlive() const { return !health.isZero(); }
};
