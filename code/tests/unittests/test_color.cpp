#include "color.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace testing;

TEST(Color, GammaCorrectionOneSamplePerPixelReturnsSquareRoots) {
    Color pixel { 4, 4, 4 };
    
    GammaCorrection(pixel, 1);

    ASSERT_THAT(pixel.e, Each(DoubleEq(2)));
}

TEST(Color, To8BitColorIfWhiteReturnAlmost256) {
    double expected = 256 * 0.999;
    Color pixel { 1, 1, 1 };

    To8BitColor(pixel);

    ASSERT_THAT(pixel.e, Each(DoubleEq(expected)));
}
