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

void TestMock()
{
  When(Method(sensor1Mock, get_linear_value)).Return(9);

  ISensorProvider &sensor = sensor1Mock.get();
  auto sensorValue = sensor.get_linear_value(10, 100);

  TEST_ASSERT_EQUAL(9, sensorValue);
}

void Test_Less(void)
{
  const float target = 10;
  
  sut.setValue(target);
  When(Method(sensor1Mock, get_linear_value)).Return(target - 1);
  
  auto result = sut.getCalculation();
  TEST_ASSERT_EQUAL(0, result);
}

void Test_Greater(void)
{
  const float target = 10;
  sut.setValue(target);
  When(Method(sensor1Mock, get_linear_value)).Return(target + 1);

  auto result = sut.getCalculation();
  TEST_ASSERT_GREATER_THAN(0, result);
}

int runUnityTests()
{
  UNITY_BEGIN();

  RUN_TEST(TestMock);
  RUN_TEST(Test_Less);
  RUN_TEST(Test_Greater);

  return UNITY_END(); // stop unit testing
}

int main()
{
  return runUnityTests();
}
