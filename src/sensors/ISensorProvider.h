#pragma once
#include <stdint.h>

class ISensorProvider {
public:
    virtual float get_raw_value() const = 0;
    virtual float get_linear_value(float targetMin, float targetMax) const = 0;
};