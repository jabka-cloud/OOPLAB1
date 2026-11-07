#pragma once
#include <vector>
#include <memory>
#include "Unit.h"

class GameFieldIterator {
private:
    const std::vector<std::unique_ptr<Unit>>& unitRef;
    size_t index;

public:
    GameFieldIterator(const std::vector<std::unique_ptr<Unit>>& units, size_t startIndex)
        : unitRef(units), index(startIndex) {
    }

    Unit* operator*() const {
        return unitRef[index].get();
    }

    GameFieldIterator& operator++() {
        if (index < unitRef.size()) {
            index++;
        }
        return *this;
    }

    bool operator!=(const GameFieldIterator& other) const {
        return index != other.index;
    }
};
