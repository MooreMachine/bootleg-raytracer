#include "color.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace testing;

TEST(Color, GammaCorrectionOneSamplePerPixel) {
    Color pixel { 4, 4, 4 };
    
    GammaCorrection(pixel, 1);

    ASSERT_THAT(pixel.e, Each(DoubleEq(2)));
}
