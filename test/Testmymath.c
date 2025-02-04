#include "unity.h"
#include "mymath.h"



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

// Test for cross function
void test_cross(void) {
    double u[] = {1.0, 2.0, 3.0};
    double v[] = {4.0, 5.0, 6.0};
    double result[3];
    cross(u, v, result);
    TEST_ASSERT_EQUAL_DOUBLE(-3.0, result[0]);
    TEST_ASSERT_EQUAL_DOUBLE(6.0, result[1]);
    TEST_ASSERT_EQUAL_DOUBLE(-3.0, result[2]);
}

// Test for dist function
void test_dist(void) {
    double v1[] = {1.0, 2.0, 3.0};
    double v2[] = {4.0, 5.0, 6.0};
    double distance = dist(v1, v2, 3);
    TEST_ASSERT_EQUAL_DOUBLE(sqrt(27), distance); // sqrt((4-1)^2 + (5-2)^2 + (6-3)^2)
}

// Test for vdiff function
void test_vdiff(void) {
    double v1[] = {5.0, 2.0, 1.0};
    double v2[] = {3.0, 2.0, 0.0};
    double result[3];
    vdiff(v1, v2, result);
    TEST_ASSERT_EQUAL_DOUBLE(2.0, result[0]);
    TEST_ASSERT_EQUAL_DOUBLE(0.0, result[1]);
    TEST_ASSERT_EQUAL_DOUBLE(1.0, result[2]);
}

// Test for distline function
void test_distline(void) {
    double x1[] = {0.0, 0.0, 0.0};
    double x2[] = {1.0, 0.0, 0.0};
    double x0[] = {1.0, 3.0, 4.0};
    double result = distline(x1, x2, x0);
    double expected = 5.0;
    TEST_ASSERT_DOUBLE_WITHIN(0.001, expected, result);
    
}

// Test for TwoVectorMean function
void test_TwoVectorMean(void) {
    double v1[] = {1.0, 2.0, 3.0};
    double v2[] = {5.0, 6.0, 7.0};
    double mean[3];
    TwoVectorMean(v1, v2, mean);
    TEST_ASSERT_EQUAL_DOUBLE(3.0, mean[0]);
    TEST_ASSERT_EQUAL_DOUBLE(4.0, mean[1]);
    TEST_ASSERT_EQUAL_DOUBLE(5.0, mean[2]);
}

// Test for ThreeVectorMean function
void test_ThreeVectorMean(void) {
    double v1[] = {1.0, 2.0, 3.0};
    double v2[] = {4.0, 5.0, 6.0};
    double v3[] = {7.0, 8.0, 9.0};
    double mean[3];
    ThreeVectorMean(v1, v2, v3, mean);
    TEST_ASSERT_EQUAL_DOUBLE(4.0, mean[0]);
    TEST_ASSERT_EQUAL_DOUBLE(5.0, mean[1]);
    TEST_ASSERT_EQUAL_DOUBLE(6.0, mean[2]);
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
 RUN_TEST(test_cross);
 RUN_TEST(test_dist);
 RUN_TEST(test_vdiff);
 RUN_TEST(test_distline);
 RUN_TEST(test_TwoVectorMean);
 RUN_TEST(test_ThreeVectorMean);
 RUN_TEST(test_GetMaxEigenvalue);

return UNITY_END();
}
