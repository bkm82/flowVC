#include "unity.h"
#include "scratch.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_add_numbers(void)
{
  TEST_ASSERT_EQUAL(5, bray_add(2,3) );
  TEST_ASSERT_EQUAL(8, bray_add(4,3) );
}


int main(void)
{
UNITY_BEGIN();
RUN_TEST(test_add_numbers);
return UNITY_END();
}
