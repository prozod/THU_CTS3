#define BOOST_TEST_MODULE StringTest
#include <boost/test/included/unit_test.hpp>
#include "../ulib/string.h"

using namespace ulib;

BOOST_AUTO_TEST_SUITE(StringTestSuite)
    BOOST_AUTO_TEST_CASE(DefaultConstructor) {
        string str;
        BOOST_CHECK_EQUAL(str.c_str(), "");
    }

    BOOST_AUTO_TEST_CASE(CharArrayConstructor) {
        string str("hello");
        BOOST_CHECK_EQUAL(str.c_str(), "hello");
    }

    BOOST_AUTO_TEST_CASE(STDStringConstructor) {
        std::string stdStr = "boost";
        string str(stdStr);
        BOOST_CHECK_EQUAL(str.c_str(), "boost");
    }

    BOOST_AUTO_TEST_CASE(CopyConstructor) {
        string original("copy");
        string copy(original);
        BOOST_CHECK_EQUAL(copy.c_str(), "copy");
    }

    BOOST_AUTO_TEST_CASE(AssignmentOperator) {
        string str1("assign");
        string str2;
        str2 = str1;
        BOOST_CHECK_EQUAL(str2.c_str(), "assign");
    }

    BOOST_AUTO_TEST_CASE(EqualityOperator) {
        string str1("test");
        string str2("test");
        string str3("different");

        BOOST_CHECK(str1 == str2);
        BOOST_CHECK(!(str1 == str3));
    }

    BOOST_AUTO_TEST_CASE(InequalityOperator) {
        string str1("test");
        string str2("different");

        BOOST_CHECK(str1 != str2);
        BOOST_CHECK(!(str1 != str1));
    }

    BOOST_AUTO_TEST_CASE(LessThanOperator) {
        string str1("apple");
        string str2("banana");

        BOOST_CHECK(str1 < str2);
        BOOST_CHECK(!(str2 < str1));
    }

    BOOST_AUTO_TEST_CASE(ConcatenationOperator) {
        string str1("hello");
        string str2(" world");

        str1 += str2;
        BOOST_CHECK_EQUAL(str1.c_str(), "hello world");
    }

    BOOST_AUTO_TEST_CASE(ConcatenationWithCharArray) {
        string str("boost");
        str += " test";
        BOOST_CHECK_EQUAL(str.c_str(), "boost test");
    }

    BOOST_AUTO_TEST_CASE(IndexOperator) {
        string str("index");
        BOOST_CHECK_EQUAL(str[0], 'i');
        BOOST_CHECK_EQUAL(str[1], 'n');

        str[0] = 'I';
        BOOST_CHECK_EQUAL(str[0], 'I');
    }

    BOOST_AUTO_TEST_CASE(IndexOutOfBounds) {
        string str("out");
        BOOST_CHECK_THROW(str[10], std::out_of_range);
    }

    // few edge cases, idk
    BOOST_AUTO_TEST_CASE(EmptyStringConcatenation) {
        string str1;
        string str2("non-empty");

        str1 += str2;
        BOOST_CHECK_EQUAL(str1.c_str(), "non-empty");

        string str3;
        str2 += str3;
        BOOST_CHECK_EQUAL(str2.c_str(), "non-empty");
    }

    BOOST_AUTO_TEST_CASE(ConcatenationWithSelf) {
        string str("self");
        str += str;
        BOOST_CHECK_EQUAL(str.c_str(), "selfself");
    }

    BOOST_AUTO_TEST_CASE(LongStringConcatenation) {
        string str1("long");
        string str2(" string");

        for (int i = 0; i < 1000; ++i) {
            str1 += str2;
        }
        BOOST_CHECK(str1.c_str() != nullptr);
    }

    BOOST_AUTO_TEST_CASE(CopySelfAssignment) {
        string str("self-assign");
        str = str;
        BOOST_CHECK_EQUAL(str.c_str(), "self-assign");
    }

    BOOST_AUTO_TEST_CASE(LargeStringConstruction) {
        std::string large(10000, 'a');
        string str(large);
        BOOST_CHECK_EQUAL(str.c_str(), large.c_str());
    }

    BOOST_AUTO_TEST_CASE(NullCharArray) {
        string str(nullptr);
        BOOST_CHECK_EQUAL(str.c_str(), "");
    }

BOOST_AUTO_TEST_SUITE_END()
