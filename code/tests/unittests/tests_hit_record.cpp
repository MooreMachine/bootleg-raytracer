#include "gtest/gtest.h"
#include "vector3.h"
#include "ray.h"
#include "hitrecord.h"


class HitRecordTest : public ::testing::Test {
protected:
    HitRecord record;
    Vector3 ray_origin = Vector3(0, 0, 0);
    Vector3 forward_direction = Vector3(0, 0, 1);
    Ray ray;

    virtual void SetUp() {
        record = HitRecord();
        ray = Ray(ray_origin, forward_direction);
    }
};

TEST_F(HitRecordTest, ComputeFaceNormalDirectionIfRayHitsOutwardReturnsTrue) {
    Vector3 hit_point(0, 0, .5);
    Vector3 center(0, 0, 1);
    Vector3 outward_normal = hit_point - center;

    record.ComputeFaceNormalDirection(ray, outward_normal);

    ASSERT_TRUE(record.front_face);
}

TEST_F(HitRecordTest, ComputeFaceNormalDirectionIfRayHitsOutwardSetsNormalToOutwardNormal) {
    Vector3 hit_point(0, 0, .5);
    Vector3 center(0, 0, 1);
    Vector3 outward_normal = hit_point - center;

    record.ComputeFaceNormalDirection(ray, outward_normal);

    ASSERT_DOUBLE_EQ(record.normal.x(), outward_normal.x());
    ASSERT_DOUBLE_EQ(record.normal.y(), outward_normal.y());
    ASSERT_DOUBLE_EQ(record.normal.z(), outward_normal.z());
}

TEST_F(HitRecordTest, ComputeFaceNormalDirectionIfRayHitsInwardReturnsFalse) {
    Vector3 hit_point(0, 0, .5);
    Vector3 center(0, 0, 0);
    Vector3 outward_normal = hit_point - center;

    record.ComputeFaceNormalDirection(ray, outward_normal);

    ASSERT_FALSE(record.front_face);
}

TEST_F(HitRecordTest, ComputeFaceNormalDirectionIfRayHitsInwardSetsNormalToInvertedOutwardNormal) {
    Vector3 hit_point(0, 0, .5);
    Vector3 center(0, 0, 0);
    Vector3 outward_normal = hit_point - center;

    record.ComputeFaceNormalDirection(ray, outward_normal);

    ASSERT_DOUBLE_EQ(record.normal.x(), -outward_normal.x());
    ASSERT_DOUBLE_EQ(record.normal.y(), -outward_normal.y());
    ASSERT_DOUBLE_EQ(record.normal.z(), -outward_normal.z());
}