#include "../tests.h"
#include "sensors/ISensorProvider.h"
#include "sut/mySut.h"

using namespace fakeit;

Mock<ISensorProvider> sensor1Mock;
MySut sut;

void setUp()
{
  sut.setSensors(&sensor1Mock.get());
}

void tearDown()
{
}

void SoilHumidityLessThanTarget_NoWateringTime(void)
{
  const float target = 10;
  
  sut.setValue(target);
  When(Method(sensor1Mock, get_linear_value)).Return(target - 1);

  auto result = sut.getCalculation();
  TEST_ASSERT_EQUAL(0, result);
}

void SoilHumidityGreaterThanTarget_FireWatering(void)
{
  const float target = 10;
  sut.setValue(target);
  When(Method(sensor1Mock, get_linear_value)).Return(target + 1);

  auto result = sut.getCalculation();
  TEST_ASSERT_GREATER_THAN(0, result);

  // conditions:
  // 1. last watering should be less than 3 minutes
}

int runUnityTests()
{
  UNITY_BEGIN();

  RUN_TEST(SoilHumidityLessThanTarget_NoWateringTime);
  RUN_TEST(SoilHumidityGreaterThanTarget_FireWatering);

  return UNITY_END(); // stop unit testing
}

int main()
{
  return runUnityTests();
}
