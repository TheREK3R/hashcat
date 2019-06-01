#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include "shared_test.h"

extern "C" {
    #include "stdio.h"
    #include "shared.h"
}

void sharedTest::setUp(){
}

void sharedTest::tearDown(){
}

	void sharedTest::overflow_check_u32_add_test_overflow() {
		u32 a = 4200000000;
		u32 b = 4200000000;
		CPPUNIT_ASSERT(!overflow_check_u32_add(a, b));
	}

	void sharedTest::overflow_check_u32_add_test_valid() {
		u32 a = 5;
		u32 b = 5;
		CPPUNIT_ASSERT(overflow_check_u32_add(a, b));
	}

	void sharedTest::overflow_check_u32_mul_test_overflow() {
		u32 a = 4200000000;
		u32 b = 5000;
		CPPUNIT_ASSERT(!overflow_check_u32_mul(a, b));
	}

	void sharedTest::overflow_check_u32_mul_test_valid() {
		u32 a = 5;
		u32 b = 50;
		CPPUNIT_ASSERT(overflow_check_u32_mul(a, b));
	}

	void sharedTest::get_random_num_test_invalid_range() {
		u32 min = 0;
		u32 max = 0;
		u32 num = get_random_num(min, max);
		CPPUNIT_ASSERT(num == min && num == max);
	}

	void sharedTest::get_random_num_test_range_one() {
		u32 min = 0;
		u32 max = 1;
		u32 num = get_random_num(min, max);
		CPPUNIT_ASSERT(num == min || num == max);
	}

	void sharedTest::mydivc32_test_valid_division() {
		u32 dividend = 10;
		u32 divisor = 10;
		u32 divisor2 = 1;
		u32 num = mydivc32(dividend, divisor);
		u32 num2 = mydivc32(dividend, divisor2);
		CPPUNIT_ASSERT(num == 1);
		CPPUNIT_ASSERT(num2 == 10);
	}


CppUnit::Test *sharedTest::suite(){
	CppUnit::TestSuite* suite = new CppUnit::TestSuite("fileHandling Test");
	suite->addTest(new CppUnit::TestCaller<sharedTest>("overflow_check_u32_add_test_overflow", &sharedTest::overflow_check_u32_add_test_overflow));
	suite->addTest(new CppUnit::TestCaller<sharedTest>("overflow_check_u32_add_test_valid", &sharedTest::overflow_check_u32_add_test_valid));
	suite->addTest(new CppUnit::TestCaller<sharedTest>("overflow_check_u32_mul_test_overflow", &sharedTest::overflow_check_u32_mul_test_overflow));
	suite->addTest(new CppUnit::TestCaller<sharedTest>("overflow_check_u32_mul_test_valid", &sharedTest::overflow_check_u32_mul_test_valid));
	suite->addTest(new CppUnit::TestCaller<sharedTest>("get_random_num_test_invalid_range", &sharedTest::get_random_num_test_invalid_range));
	suite->addTest(new CppUnit::TestCaller<sharedTest>("get_random_num_test_range_one", &sharedTest::get_random_num_test_range_one));
	suite->addTest(new CppUnit::TestCaller<sharedTest>("mydivc32_test_valid_division", &sharedTest::mydivc32_test_valid_division));
	return suite;
}