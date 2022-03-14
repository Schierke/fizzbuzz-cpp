#include "dto/FizzBuzzDto.hpp"
#include <vector>
#include <string>
#include <algorithm>
class FizzBuzzTest {
    public:
    FizzBuzzTest(){};

    void runTests() {
        testSimpleCase();
        testSimpleCase2();
    }

    void testSimpleCase() {
        std::vector<std::string> expected_result = {"1", "2", "Fizz", "4", "Buzz"};

        oatpp::Object<FizzBuzzDto> dto = FizzBuzzDto::createShared();
        dto->int1 = 3;
        dto->int2 = 5;
        dto->str1 = "Fizz";
        dto->str2 = "Buzz";
        dto->max_limit = 5;

        std::vector<std::string> result = dto->computeFizzBuzz();

        OATPP_ASSERT(std::equal(expected_result.begin(), expected_result.end(), result.begin()));
    }

    void testSimpleCase2() {
        std::vector<std::string> expected_result = {"1", "Fizz", "Buzz", "Fizz", "5", "FizzBuzz"};

        oatpp::Object<FizzBuzzDto> dto = FizzBuzzDto::createShared();
        dto->int1 = 2;
        dto->int2 = 3;
        dto->str1 = "Fizz";
        dto->str2 = "Buzz";
        dto->max_limit = 6;

        std::vector<std::string> result = dto->computeFizzBuzz();

        OATPP_ASSERT(std::equal(expected_result.begin(), expected_result.end(), result.begin()));
    }
};