#pragma once
#include <vector>
#include <memory>
#include "Unit.h"

class GameFieldIterator;

class GameField {
private:
    int width;
    int height;
    size_t maxUnits;
    std::vector<std::unique_ptr<Unit>> units;

public:
    GameField(int w, int h, size_t maxU);

    ~GameField() = default;
    GameField(const GameField& other);
    GameField& operator=(const GameField& other);
    GameField(GameField&& other) noexcept;
    GameField& operator=(GameField&& other) noexcept; 

    bool addUnit(std::unique_ptr<Unit> unit, int x, int y);
    bool removeUnit(int x, int y);
    Unit* getUnit(int x, int y) const;

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    size_t getUnitCount() const { return units.size(); }
    void clear();

    GameFieldIterator begin();
    GameFieldIterator end();
};
