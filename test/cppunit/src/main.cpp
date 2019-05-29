#include <cppunit/ui/text/TestRunner.h>
#include "hwmon_test.h"
#include "convert_test.h"

int main(){
	CppUnit::TextUi::TestRunner runner;

	/*
	 * Unit:        Hwmon
	 * Test state:  All tests pass
	 */
	runner.addTest(HwmonTest::suite());

	/*
	 * Unit:        Convert
	 * Test state:  Four tests fail. The base64 string
	 *              validity checker is not robust at all.
	 *              It fails to check for valid lengths and
	 *              valid alphabetical characters. Base64
	 *              characters should be hexadecimal, not just
	 *              any alphanumeric character.
	 */
	runner.addTest(ConvertTest::suite());

	// Run tests
	runner.run();
	return 0;
}