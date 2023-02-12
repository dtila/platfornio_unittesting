#pragma once
#include <stdint.h>
#include <string.h>
#include "../sensors/ISensorProvider.h"

class MySut
{
    ISensorProvider *_sensor1{};
    float _memorizedValue{};

public:
    MySut();

    void setSensors(ISensorProvider *sensor1);
    uint32_t getCalculation() const;
    void setValue(float value);
};