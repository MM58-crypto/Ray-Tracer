#include<gtest/gtest.h>
#include<iostream>
#include<math.h>
#include<tuple>

using namespace std;

// create points
tuple<int, int, int, int> createPoint(const tuple<int, int, int>& x1) {
   int x1_1, x1_2, x1_3;
   tie( x1_1, x1_2, x1_3)= x1;
   return make_tuple(x1_1, x1_2, x1_3, 1);

}
// create vectors
tuple<int, int, int, int> createVector(const tuple<int, int, int>& x1) {
   int x1_1, x1_2, x1_3;
   tie( x1_1, x1_2, x1_3)= x1;
   return make_tuple(x1_1, x1_2, x1_3, 0);

}
// adding tuples

tuple<int, int, int, int> addTuples(const tuple<int, int, int, int>& a1, const tuple<int, int, int, int>& a2) {
    int a1_1, a1_2, a1_3, a1_4;
    int a2_1, a2_2, a2_3, a2_4;
    tie(a1_1, a1_2, a1_3, a1_4) = a1;
    tie(a2_1, a2_2, a2_3, a2_4) = a2;
    return make_tuple(a1_1 + a2_1, a1_2 + a2_2, a1_3 + a2_3, a1_4 + a2_4);
}
//function to subtract tuples 
tuple<int, int, int> subtractTuples(const tuple<int, int, int>& a1, const tuple<int, int, int>& a2) {
    int a1_1, a1_2, a1_3;
    int a2_1, a2_2, a2_3;
    tie(a1_1, a1_2, a1_3) = a1;
    tie(a2_1, a2_2, a2_3) = a2;
    return make_tuple(a1_1 - a2_1, a1_2 - a2_2, a1_3 - a2_3);
}

// scalar multiplication (eg. 3.5)
tuple<double, double, double, double> scalarMultiply(const tuple<int, int, int, int>& a1) {
    int a1_1, a1_2, a1_3, a1_4;
    //int a2_1, a2_2, a2_3;
    tie(a1_1, a1_2, a1_3, a1_4) = a1;
    //tie(a2_1, a2_2, a2_3) = a2;
    return make_tuple(a1_1 * 3.5, a1_2 * 3.5, a1_3 * 3.5, a1_4 * 3.5);

}
// computing magnitude of a vector 
 double getMagnitude(const tuple<int, int, int>& a1) {
    int a1_1, a1_2, a1_3;
    //int a2_1, a2_2, a2_3;
    tie(a1_1, a1_2, a1_3) = a1;
    //tie(a2_1, a2_2, a2_3) = a2;
    return sqrt(pow(a1_1,2) + pow(a1_2,2) + pow(a1_3,2));

}
// Normalize Vectors
tuple<int, int, int> normalizeVector(const tuple<int, int, int>& v1) {
    int v1_1, v1_2, v1_3;
    tie(v1_1, v1_2, v1_3) = v1;
    return make_tuple(v1_1/getMagnitude(v1), v1_2/getMagnitude(v1), v1_3/getMagnitude(v1) );

}
// Dot product
float  dotProduct(const tuple <float, float, float>& v1, const tuple<float, float, float>& v2) {
    float v1_1, v1_2, v1_3;
    float v2_1, v2_2, v2_3;
    tie(v1_1, v1_2, v1_3) = v1;
    tie(v2_1, v2_2, v2_3) = v2;

    return (v1_1 * v2_1) + (v1_2 * v2_2) + (v1_3 * v2_3);

}
// Cross product
tuple<int, int, int> crossproduct(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    int a_1, a_2, a_3;
    int b_1, b_2, b_3;
    tie(a_1, a_2, a_3) = a;
    tie(b_1, b_2, b_3) = b;

    return make_tuple(a_2 * b_3 - a_3 * b_2, a_3 * b_1 - a_1 * b_3, a_1 * b_2 - a_2 * b_1);

}
// Color tuple <-- wrong needs to be fixed
double Color(const tuple<double, double ,double>& a1) {
    double a1_1, a1_2, a1_3;
    tie(a1_1, a1_2, a1_3) = a1;
    
    return get<0>(a1);
}
// Colors product | Blending colors
tuple<double, double, double> hadamard_product(const tuple <double, double, double>& c1, const tuple<double, double, double>& c2) {
    float c1_1, c1_2, c1_3;
    float c2_1, c2_2, c2_3;
    tie(c1_1, c1_2, c1_3) = c1;
    tie(c2_1, c2_2, c2_3) = c2;

    return make_tuple(c1_1 * c2_1, c1_2 * c2_2, c1_3 * c2_3);

}
TEST(CreatePointTest, CreatePoint) {
    tuple<int, int, int> a1 = make_tuple(3, -2, 5);
    tuple<int, int, int, int> expectedResult = make_tuple(3, -2, 5, 1);

    tuple<int, int, int, int> result = createPoint(a1);

    ASSERT_EQ(result, expectedResult);
}
TEST(CreateVectorTest, CreateVector) {
    tuple<int, int, int> a1 = make_tuple(3, -2, 5);
    tuple<int, int, int, int> expectedResult = make_tuple(3, -2, 5, 0);

    tuple<int, int, int, int> result = createVector(a1);

    ASSERT_EQ(result, expectedResult);
}
TEST(TupleAdditionTest, AddingTwoTuples) {
    tuple<int, int, int, int> a1 = make_tuple(3, -2, 5, 1);
    tuple<int, int, int, int> a2 = make_tuple(-2, 3, 1, 0);
    tuple<int, int, int, int> expectedResult = make_tuple(1, 1, 6, 1);

    tuple<int, int, int, int> result = addTuples(a1, a2);

    ASSERT_EQ(result, expectedResult);
}

TEST(TupleSubtractionTest, SubtractTwoTuples) {
     tuple<int, int, int> p1 = make_tuple(3, 2, 1);
     tuple<int, int, int> p2 = make_tuple(5, 6, 7);
     tuple<int, int, int> expected_result = make_tuple(-2, -4, -6);
     
     tuple<int, int, int> actual_result = subtractTuples(p1, p2);
     ASSERT_EQ(actual_result, expected_result);
    
}

TEST(ScalarMultiplyTest, MultiplyaTuple) {
     tuple<int, int, int, int> a = make_tuple(1, -2, 3, -4); 
     tuple<double, double, double, double> expected_result = make_tuple(3.5, -7, 10.5, -14);
     
     tuple<double, double, double, double> actual_result = scalarMultiply(a);
     ASSERT_EQ(actual_result, expected_result);
    
}

TEST(MagnitudeTest, GetMagnitude) {
    tuple<int, int, int> v = make_tuple(1, 2, 3);
    double expected_result = sqrt(14);
    double actual_result = getMagnitude(v);

    ASSERT_EQ(actual_result, expected_result);

}

TEST(NormalizeTest, NormalizeVector) {
    tuple<int, int, int> vec = make_tuple(4, 0 ,0);
    tuple<int, int, int> expected_result = make_tuple(1, 0, 0);
    
    tuple<int, int, int> actual_result = normalizeVector(vec);

    ASSERT_EQ(actual_result, expected_result);


}

TEST(DotpTest, Dotproduct) {
    tuple<float, float, float> vec1 = make_tuple(1, 2, 3);
    tuple<float, float, float> vec2 = make_tuple(2, 3, 4);
    float expected_result = 20;
    
    float actual_result = dotProduct(vec1, vec2);

    ASSERT_EQ(actual_result, expected_result);
}

TEST(CrossProductTest, Crossproduct) {
     tuple<int, int, int> a = make_tuple(1, 2, 3); 
     tuple<int, int, int> b = make_tuple(2, 3, 4); 
     tuple<int, int, int> expected_result = make_tuple(-1, 2, -1);
     
     tuple<int, int, int> actual_result = crossproduct(a,b);
     
     ASSERT_EQ(actual_result, expected_result);
    
}
TEST(ColorTest, ReturnColors) {
    tuple<double, double, double> a1 = make_tuple(-0.5, 0.4, 1.7);
    double expectedResult = -0.5;
    double a_result = Color(a1);

    ASSERT_EQ(a_result, expectedResult);
}

TEST(HadamardproductTest, Hadamardproduct) {
     tuple<double, double, double> c1 = make_tuple(1, 0.2, 0.4); 
     tuple<double, double, double> c2 = make_tuple(0.9, 1, 0.1); 
     tuple<double, double, double> expected_result = make_tuple(0.9, 0.2, 0.04);
     
     tuple<double, double, double> actual_result = hadamard_product(c1,c2);
     
     EXPECT_EQ(actual_result, expected_result);
}    
