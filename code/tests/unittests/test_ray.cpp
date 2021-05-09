#include "ray.h"

#include "vector3.h"

#include "gmock/gmock.h"

using namespace testing;

class RayTest : public Test {
protected:
    Ray ray;

    void SetUp() override {
        ray = Ray { {0, 0, 0}, {1, 1, 1} };
    }
};

TEST_F(RayTest, AtMultiplyBy2ReturnsVectorOf2s) {
    Point3 result = ray.At(2);

    ASSERT_THAT(result.e, ElementsAre(2, 2, 2));
}
