#include <gtest/gtest.h>
#include "../Vector3D/Vector3D.h"
#include <sstream>
#include <cmath>


TEST(Vector3DTest, DefaultConstructor) {
    Vector3D v;
    EXPECT_DOUBLE_EQ(v.GetStartX(), 0.0);
    EXPECT_DOUBLE_EQ(v.GetStartY(), 0.0);
    EXPECT_DOUBLE_EQ(v.GetEndX(), 0.0);
    EXPECT_DOUBLE_EQ(v.GetEndY(), 0.0); 
}

TEST(Vector3DTest, ParameterizedConstructor) {
    Vector3D v(1.5, 2.5, 3.5, 4.5, 5.5, 6.5);
    EXPECT_DOUBLE_EQ(v.GetStartX(), 1.5);
    EXPECT_DOUBLE_EQ(v.GetStartY(), 2.5);
    EXPECT_DOUBLE_EQ(v.GetEndX(), 4.5);
    EXPECT_DOUBLE_EQ(v.GetEndY(), 5.5);
    EXPECT_DOUBLE_EQ(v.GetStartZ(), 3.5); 

TEST(Vector3DTest, SetStart) {
    Vector3D v;
    v.SetStart(10.0, 11.0, 12.0);
    EXPECT_DOUBLE_EQ(v.GetStartX(), 10.0);
    EXPECT_DOUBLE_EQ(v.GetStartY(), 11.0);
    EXPECT_DOUBLE_EQ(v.GetStartZ(), 12.0); 
}

TEST(Vector3DTest, SetEnd) {
    Vector3D v;
    v.SetEnd(13.0, 14.0, 15.0);
    EXPECT_DOUBLE_EQ(v.GetEndX(), 13.0);
    EXPECT_DOUBLE_EQ(v.GetEndY(), 14.0);
    EXPECT_DOUBLE_EQ(v.GetEndZ(), 15.0); 
}

TEST(Vector3DTest, GetLengthBasic) {
    Vector3D v1(0, 0, 0, 1, 0, 0);
    EXPECT_NEAR(v1.GetLength(), 1.0, Vector3D::kEpsilon);
}

TEST(Vector3DTest, GetLengthZero) {
    Vector3D zeroVector;
    EXPECT_NEAR(zeroVector.GetLength(), 0.0, Vector3D::kEpsilon);
}

TEST(Vector3DTest, GetLengthDiagonal) {
    Vector3D diagonal(0, 0, 0, 3, 4, 0);
    EXPECT_NEAR(diagonal.GetLength(), 5.0, Vector3D::kEpsilon);
}

TEST(Vector3DTest, AdditionBasic) {
    Vector3D v1(0, 0, 0, 1, 0, 0);
    Vector3D v2(0, 0, 0, 0, 1, 0);
    Vector3D sum = v1 + v2;

    EXPECT_NEAR(sum.GetEndX() - sum.GetStartX(), 1.0, Vector3D::kEpsilon);
    EXPECT_NEAR(sum.GetEndY() - sum.GetStartY(), 1.0, Vector3D::kEpsilon);
    EXPECT_NEAR(sum.GetEndZ() - sum.GetStartZ(), 0.0, Vector3D::kEpsilon); 
}

TEST(Vector3DTest, SubtractionBasic) {
    Vector3D v1(0, 0, 0, 1, 0, 0);
    Vector3D v2(0, 0, 0, 0, 1, 0);
    Vector3D diff = v1 - v2;

    EXPECT_NEAR(diff.GetEndX() - diff.GetStartX(), 1.0, Vector3D::kEpsilon);
    EXPECT_NEAR(diff.GetEndY() - diff.GetStartY(), -1.0, Vector3D::kEpsilon);
    EXPECT_NEAR(diff.GetEndZ() - diff.GetStartZ(), 0.0, Vector3D::kEpsilon); 
}

TEST(Vector3DTest, DotProductBasic) {
    Vector3D v1(0, 0, 0, 1, 0, 0);
    Vector3D v2(0, 0, 0, 0, 1, 0);

    double dot = v1 * v2;
    EXPECT_NEAR(dot, 0.0, Vector3D::kEpsilon);

    Vector3D v1_copy(0, 0, 0, 1, 0, 0);
    dot = v1 * v1_copy;
    EXPECT_NEAR(dot, 1.0, Vector3D::kEpsilon);
}

TEST(Vector3DTest, CrossProductBasic) {
    Vector3D v1(0, 0, 0, 1, 0, 0);
    Vector3D v2(0, 0, 0, 0, 1, 0);
    Vector3D cross = v1.Cross(v2);

    EXPECT_NEAR(cross.GetEndX() - cross.GetStartX(), 0.0, Vector3D::kEpsilon);
    EXPECT_NEAR(cross.GetEndY() - cross.GetStartY(), 0.0, Vector3D::kEpsilon);
    EXPECT_NEAR(cross.GetEndZ() - cross.GetStartZ(), 1.0, Vector3D::kEpsilon);
}

TEST(Vector3DTest, CrossProductReverse) {
    Vector3D v1(0, 0, 0, 1, 0, 0);
    Vector3D v2(0, 0, 0, 0, 1, 0);
    Vector3D cross = v2.Cross(v1); 

    EXPECT_NEAR(cross.GetEndZ() - cross.GetStartZ(), -1.0, Vector3D::kEpsilon);
}

TEST(Vector3DTest, ScalarMultiplicationBasic) {
    Vector3D v1(0, 0, 0, 1, 0, 0);
    Vector3D scaled = v1 * 3.5;

    EXPECT_NEAR(scaled.GetEndX() - scaled.GetStartX(), 3.5, Vector3D::kEpsilon);
    EXPECT_NEAR(scaled.GetEndY() - scaled.GetStartY(), 0.0, Vector3D::kEpsilon);
    EXPECT_NEAR(scaled.GetEndZ() - scaled.GetStartZ(), 0.0, Vector3D::kEpsilon); 
}

TEST(Vector3DTest, ScalarDivisionBasic) {
    Vector3D v(0, 0, 0, 7.0, 0, 0);
    Vector3D divided = v / 2.0;

    EXPECT_NEAR(divided.GetEndX() - divided.GetStartX(), 3.5, Vector3D::kEpsilon);
}

TEST(Vector3DTest, InPlaceAddition) {
    Vector3D v1(0, 0, 0, 1, 0, 0);
    Vector3D v2(0, 0, 0, 0, 1, 0);
    Vector3D v = v1;

    v += v2; 
    EXPECT_NEAR(v.GetEndX() - v.GetStartX(), 1.0, Vector3D::kEpsilon);
    EXPECT_NEAR(v.GetEndY() - v.GetStartY(), 1.0, Vector3D::kEpsilon);
}

TEST(Vector3DTest, InPlaceMultiplication) {
    Vector3D v1(0, 0, 0, 1, 0, 0);
    Vector3D v = v1;

    v *= 3.0;
    EXPECT_NEAR(v.GetEndX() - v.GetStartX(), 3.0, Vector3D::kEpsilon);
}

TEST(Vector3DTest, InPlaceDivision) {
    Vector3D v(0, 0, 0, 6.0, 0, 0);

    v /= 2.0; 
    EXPECT_NEAR(v.GetEndX() - v.GetStartX(), 3.0, Vector3D::kEpsilon);
}

TEST(Vector3DTest, CosineAngleBasic) {
    Vector3D v1(0, 0, 0, 1, 0, 0);
    Vector3D v2(0, 0, 0, 0, 1, 0);

    double cosAngle = v1 ^ v2;
    EXPECT_NEAR(cosAngle, 0.0, Vector3D::kEpsilon);

    Vector3D parallel(0, 0, 0, 2, 0, 0);
    cosAngle = v1 ^ parallel;
    EXPECT_NEAR(cosAngle, 1.0, Vector3D::kEpsilon);
}

TEST(Vector3DTest, CosineAngle45Degrees) {
    Vector3D v1(0, 0, 0, 1, 0, 0);
    Vector3D v2(0, 0, 0, 1, 1, 0);

    double cosAngle = v1 ^ v2;
    EXPECT_NEAR(cosAngle, sqrt(2)/2, Vector3D::kEpsilon); 
}

TEST(Vector3DTest, EqualityOperatorBasic) {
    Vector3D v1(0, 0, 0, 1, 0, 0);
    Vector3D v1_copy(0, 0, 0, 1, 0, 0);
    Vector3D v2(0, 0, 0, 0, 1, 0);

    EXPECT_TRUE(v1 == v1_copy);
    EXPECT_TRUE(v1 == v2);

    Vector3D longer(0, 0, 0, 2, 0, 0);
    EXPECT_FALSE(v1 == longer); 
}

TEST(Vector3DTest, NotEqualOperator) {
    Vector3D v1(0, 0, 0, 1, 0, 0);
    Vector3D longer(0, 0, 0, 2, 0, 0);

    EXPECT_TRUE(v1 != longer);
    EXPECT_FALSE(v1 != v1); 
}

TEST(Vector3DTest, GreaterThanOperator) {
    Vector3D v1(0, 0, 0, 1, 0, 0);
    Vector3D longer(0, 0, 0, 2, 0, 0);

    EXPECT_TRUE(longer > v1);
    EXPECT_FALSE(v1 > longer); 
}

TEST(Vector3DTest, LessThanOperator) {
    Vector3D v1(0, 0, 0, 1, 0, 0);
    Vector3D longer(0, 0, 0, 2, 0, 0);

    EXPECT_TRUE(v1 < longer);
    EXPECT_FALSE(longer < v1); 
}

TEST(Vector3DTest, GreaterOrEqualOperator) {
    Vector3D v1(0, 0, 0, 1, 0, 0);
    Vector3D longer(0, 0, 0, 2, 0, 0);
    Vector3D same(0, 0, 0, 1, 0, 0);

    EXPECT_TRUE(longer >= v1); 
    EXPECT_TRUE(v1 >= same); 
}

TEST(Vector3DTest, LessOrEqualOperator) {
    Vector3D v1(0, 0, 0, 1, 0, 0);
    Vector3D longer(0, 0, 0, 2, 0, 0);
    Vector3D same(0, 0, 0, 1, 0, 0);

    EXPECT_TRUE(v1 <= longer); 
    EXPECT_TRUE(v1 <= same); 
}

TEST(Vector3DTest, OutputOperatorBasic) {
    Vector3D v(1.5, 2.5, 3.5, 4.5, 5.5, 6.5);
    std::stringstream ss;
    ss << v;

    std::string output = ss.str();
    EXPECT_TRUE(output.find("1.5") != std::string::npos);
    EXPECT_TRUE(output.find("6.5") != std::string::npos);
    EXPECT_TRUE(output.find("Start") != std::string::npos); 
    EXPECT_TRUE(output.find("End") != std::string::npos);
}
TEST(Vector3DTest, DivisionByZeroScalar) {
    Vector3D v(0, 0, 0, 1, 0, 0);

    EXPECT_THROW(v / 0.0, std::invalid_argument);
    EXPECT_THROW(v / 1e-13, std::invalid_argument);

    Vector3D v2 = v;
    EXPECT_THROW(v2 /= 0.0, std::invalid_argument);
}

TEST(Vector3DTest, CosineWithZeroLengthVectors) {
    Vector3D zeroVector;
    Vector3D nonZeroVector(0, 0, 0, 1, 0, 0);

    EXPECT_THROW(zeroVector ^ nonZeroVector, std::invalid_argument);
    EXPECT_THROW(nonZeroVector ^ zeroVector, std::invalid_argument);
    EXPECT_THROW(zeroVector ^ zeroVector, std::invalid_argument);
}

TEST(Vector3DTest, SimpleLengthCalculation) {
    Vector3D v(0, 0, 0, 3, 4, 0);
    EXPECT_NEAR(v.GetLength(), 5.0, Vector3D::kEpsilon);
}

TEST(Vector3DTest, SimpleDotProduct) {
    Vector3D v1(0, 0, 0, 2, 0, 0);
    Vector3D v2(0, 0, 0, 0, 3, 0);

    double dot = v1 * v2;
    EXPECT_NEAR(dot, 0.0, Vector3D::kEpsilon);
}

