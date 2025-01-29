#include "unity.h"
#include "mymath.h"
#include "io.h"


void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_vdot(void) {
    double v1[] = {1.0, 2.0, 3.0};
    double v2[] = {4.0, 5.0, 6.0};
    int dim = 3;

    double expected = 1.0 * 4.0 + 2.0 * 5.0 + 3.0 * 6.0;  // Expected result: 32.0
    double result = vdot(v1, v2, dim);
    
    TEST_ASSERT_DOUBLE_WITHIN(1e-6, expected, result);
}

void test_GetMaxEigenvalue(void) {
    double matrix[3][3] = {
        {1.0, 2.0, 3.0},
        {2.0, 5.0, 8.0},
        {3.0, 8.0, 14.0}
    };
    
    double expected = 19.384;
    double result = GetMaxEigenvalue(matrix);
    
    TEST_ASSERT_DOUBLE_WITHIN(0.01, expected, result); 
}

int main(void)
{
UNITY_BEGIN();
 RUN_TEST(test_vdot);
 RUN_TEST(test_GetMaxEigenvalue);
return UNITY_END();
}
