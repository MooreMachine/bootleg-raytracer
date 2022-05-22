# Testing
## Naming Conventions

### Test Suite Name
The convention we use is 
```
<Class under test>Test
```
Example:
```
Class: HitRecord
Test Suite Name: HitRecordTest
```


### Test Name
The convention we use is UnitOfWork_StateUnderTest_ExpectedBehavior.

Because Google recommends [not to use underscores](https://github.com/google/googletest/blob/master/docs/faq.md) on 
text fixtures or test names the end result would look similar to the following example:
```
ComputeFaceNormalDirectionIfRayHitsOutwardSetsFrontFaceToTrue
```
## Structure
1. Arrange
2. Act
3. Assert

```
// Arrange
Vector3 hit_point(0, 0, .5);
Vector3 center(0, 0, 1);
Vector3 outward_normal = hit_point - center;

// Act
record.ComputeFaceNormalDirection(ray, outward_normal);

//Assert
ASSERT_TRUE(record.front_face);
```

## Building and running

To run the tests using the interactive Docker container:

1. Start the interactive container with the `run_interactive_container.sh` script.
1. Build the unit tests with `build_unit_tests.sh`.
1. Run the tests in `/build/bin/raytracer_tests`.
1. You have to option to filter out tests using the `--gtest_filter=TestNameWildcard*` flag.
