#ifndef FILEHANDLING_TEST_H
#define FILEHANDLING_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>

extern "C" {
	#include <stdio.h>
	#ifndef _TYPES_H
	#include "types.h"
	#endif
}


/*
 * Class:   fileHandlingTest
 * Desc:    
 */
class fileHandlingTest : public CppUnit::TestFixture{
private:
	FILE *testfile;
public:
	void setUp();
	void tearDown();

	void count_lines_test_zerolines();
	void count_lines_test_oneline();
	void count_lines_test_fourlines();

	void fgetl_test_zerolines();
	void fgetl_test_oneline();

	void superchop_with_length_test_zerochars();
	void superchop_with_length_test_manychars();

	void in_superchop_test_zerochars();
	void in_superchop_test_manychars();

	static CppUnit::Test *suite();
};

#endif
