#include "mySut.h"

MySut::MySut()
{
}

void MySut::setSensors(ISensorProvider *sensor1)
{
    this->_sensor1 = sensor1;
}


void MySut::setValue(float value)
{
    this->_memorizedValue = value;
}

uint32_t MySut::getCalculation() const
{
    float sensor = _sensor1->get_linear_value(1, 1000);
    float diff = _memorizedValue - sensor;
    if (diff <= 0)
        return 0;

    return _memorizedValue * diff;
}
