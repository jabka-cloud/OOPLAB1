#pragma once

class Health {
private:
    int value;

public:
    explicit Health(int startValue);

    void decrease(int amount);
    void increase(int amount);
    bool isZero() const;
    int getValue() const;
};
