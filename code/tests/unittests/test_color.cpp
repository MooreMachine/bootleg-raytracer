#include "color.h"

#include "gmock/gmock.h"

#include <sstream>

using namespace testing;

TEST(ColorTest, GammaCorrectionOneSamplePerPixelReturnsSquareRoots) {
    Color pixel { 4, 4, 4 };
    
    GammaCorrection(pixel, 1);

    ASSERT_THAT(pixel.e, Each(DoubleEq(2)));
}

TEST(ColorTest, To8BitColorIfWhiteReturnAlmost256) {
    double expected = 256 * 0.999;
    Color pixel { 1, 1, 1 };

    To8BitColor(pixel);

    ASSERT_THAT(pixel.e, Each(DoubleEq(expected)));
}

TEST(ColorTest, WriteColorWhenPassingAPixelOutputsColorValue) {
    std::stringstream ss;
    Color pixel { 0.25, 0.25, 0.25 };
    int samples_per_pixel = 1;

    WriteColor(ss, pixel, samples_per_pixel);

    ASSERT_EQ(ss.str(), "128 128 128\n");
}
