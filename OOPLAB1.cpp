#include <iostream>
#include "Gamefield.h"
#include "GameFieldIterator.h"
#include "InfantryFactory.h"
#include "ArcherFactory.h"
#include "CavalryFactory.h"

int main() {
    std::cout << "=== SCENARIO 1: Creating Field and Adding Units ===" << std::endl;
    GameField field(10, 10, 5);

    InfantryFactory infantryFab;
    ArcherFactory archerFab;
    CavalryFactory cavalryFab;

    field.addUnit(infantryFab.createUnit(UnitType::Swordsman), 0, 0);
    field.addUnit(archerFab.createUnit(UnitType::HeavyArcher), 1, 1);
    field.addUnit(cavalryFab.createUnit(UnitType::Cataphract), 2, 2);

    std::cout << "Units on original field: " << field.getUnitCount() << "\n" << std::endl;

    std::cout << "=== SCENARIO 2: Custom Iterator Test ===" << std::endl;
    for (auto it = field.begin(); it != field.end(); ++it) {
        Unit* u = *it;
        // Здесь u->getName() вернет нормальный русский текст ("Мечник" и т.д.)
        std::cout << " - Unit: " << u->getName()
            << " [" << u->getType() << "]"
            << " at (" << u->getX() << ", " << u->getY() << ")"
            << ", HP: " << u->getHealthValue() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== SCENARIO 3: Deep Copy (Rule of Five) ===" << std::endl;
    GameField clonedField = field;
    std::cout << "Units on cloned field: " << clonedField.getUnitCount() << std::endl;

    Unit* originalUnit = field.getUnit(0, 0);
    Unit* clonedUnit = clonedField.getUnit(0, 0);

    if (originalUnit && clonedUnit) {
        std::cout << "Original unit HP: " << originalUnit->getHealthValue() << std::endl;
        originalUnit->takeDamage(50);
        std::cout << "Original unit HP after damage: " << originalUnit->getHealthValue() << std::endl;
        std::cout << "Cloned unit HP (should remain unchanged): " << clonedUnit->getHealthValue() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== SCENARIO 4: Move Semantics (Rule of Five) ===" << std::endl;
    GameField movedField = std::move(clonedField);

    std::cout << "Units on old cloned field (should be 0): " << clonedField.getUnitCount() << std::endl;
    std::cout << "Units on new moved field: " << movedField.getUnitCount() << std::endl;
    std::cout << std::endl;

    std::cout << "=== SCENARIO 5: Removing Unit ===" << std::endl;
    std::cout << "Removing unit from (1, 1)..." << std::endl;
    movedField.removeUnit(1, 1);
    std::cout << "Units left on moved field: " << movedField.getUnitCount() << std::endl;

    return 0;
}
