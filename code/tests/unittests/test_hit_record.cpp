#include "hitrecord.h"

#include "ray.h"
#include "vector3.h"

#include "gmock/gmock.h"

using namespace testing;

class HitRecordTest : public Test {
protected:
    HitRecord record;
    Vector3 ray_origin = Vector3(0, 0, 0);
    Vector3 forward_direction = Vector3(0, 0, 1);
    Ray ray;

    void SetUp() override {
        record = HitRecord();
        ray = Ray(ray_origin, forward_direction);
    }
};

TEST_F(HitRecordTest, ComputeFaceNormalDirectionIfRayHitsOutwardSetsFrontFaceToTrue) {
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

    ASSERT_THAT(record.normal.e, ElementsAreArray(outward_normal.e));
}

TEST_F(HitRecordTest, ComputeFaceNormalDirectionIfRayHitsInwardSetsFrontFaceToFalse) {
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
    Vector3 inverted_outward_normal = -outward_normal;

    record.ComputeFaceNormalDirection(ray, outward_normal);

    ASSERT_THAT(record.normal.e, ElementsAreArray(inverted_outward_normal.e));
}
