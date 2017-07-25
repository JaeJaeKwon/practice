#include "ftl.hpp"
#include "gtest\gtest.h"

TEST(Ctor_Test, Vec2Test) {

				EXPECT_EQ(Vector3(), Vector3(0, 0, 0));

}
TEST(operator_test, Vec2Test) {
				Vector3 v1, v2;
				v1.Set(1,3,-5);
				v2.Set(4, 0, 3);
				Vector3 result = v1 + v2;

				EXPECT_EQ(Vector3(5,3,-2), result);
}