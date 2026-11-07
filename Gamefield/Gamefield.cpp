#include "GameField.h"
#include "GameFieldIterator.h"

GameField::GameField(int w, int h, size_t maxU) : width(w), height(h), maxUnits(maxU) {}

GameField::GameField(const GameField& other)
    : width(other.width), height(other.height), maxUnits(other.maxUnits) {
    for (const auto& u : other.units) {
        if (u) {
            units.push_back(u->clone());
        }
    }
}

GameField& GameField::operator=(const GameField& other) {
    if (this == &other) return *this;

    width = other.width;
    height = other.height;
    maxUnits = other.maxUnits;

    units.clear();
    for (const auto& u : other.units) {
        if (u) {
            units.push_back(u->clone());
        }
    }
    return *this;
}

GameField::GameField(GameField&& other) noexcept
    : width(other.width), height(other.height), maxUnits(other.maxUnits), units(std::move(other.units)) {
    other.width = 0;
    other.height = 0;
    other.maxUnits = 0;
}

GameField& GameField::operator=(GameField&& other) noexcept {
    if (this == &other) return *this;

    width = other.width;
    height = other.height;
    maxUnits = other.maxUnits;
    units = std::move(other.units);

    other.width = 0;
    other.height = 0;
    other.maxUnits = 0;

    return *this;
}

bool GameField::addUnit(std::unique_ptr<Unit> unit, int x, int y) {
    if (!unit || units.size() >= maxUnits) return false;
    if (x < 0 || x >= width || y < 0 || y >= height) return false;
    if (getUnit(x, y) != nullptr) return false; // Клетка занята

    unit->setCoordinates(x, y);
    units.push_back(std::move(unit));
    return true;
}

bool GameField::removeUnit(int x, int y) {
    for (auto it = units.begin(); it != units.end(); ++it) {
        if ((*it)->getX() == x && (*it)->getY() == y) {
            units.erase(it);
            return true;
        }
    }
    return false;
}

Unit* GameField::getUnit(int x, int y) const {
    for (const auto& u : units) {
        if (u && u->getX() == x && u->getY() == y) {
            return u.get();
        }
    }
    return nullptr;
}

void GameField::clear() {
    units.clear();
}

GameFieldIterator GameField::begin() {
    return GameFieldIterator(units, 0);
}

GameFieldIterator GameField::end() {
    return GameFieldIterator(units, units.size());
}