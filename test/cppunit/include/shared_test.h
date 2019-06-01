#ifndef SHARED_TEST_H
#define SHARED_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>

extern "C" {
	#include <stdio.h>
	#ifndef _TYPES_H
	#include "types.h"
	#endif
}


/*
 * Class:   shared
 * Desc:    
 */
class sharedTest : public CppUnit::TestFixture{
private:
public:
	void setUp();
	void tearDown();

	void overflow_check_u32_add_test_overflow();
	void overflow_check_u32_add_test_valid();

	void overflow_check_u32_mul_test_overflow();
	void overflow_check_u32_mul_test_valid();

	void get_random_num_test_invalid_range();
	void get_random_num_test_range_one();

	void mydivc32_test_valid_division();

	static CppUnit::Test *suite();
};

#endif
