#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include "filehandling_test.h"

extern "C" {
    #include "stdio.h"
    #include "filehandling.h"
}

using std::cout;
using std::string;

void fileHandlingTest::setUp(){
    this->testfile = NULL;
}

void fileHandlingTest::tearDown(){
	if(this->testfile != NULL) fclose(this->testfile);
}

void fileHandlingTest::count_lines_test_zerolines() {
    this->testfile = fopen("./test/filehandleTest0lines.txt", "r");
    u64 linecount = count_lines(this->testfile);
    CPPUNIT_ASSERT(linecount == 0);
}

void fileHandlingTest::count_lines_test_oneline() {
    this->testfile = fopen("./test/filehandleTest1line.txt", "r");
    u64 linecount = count_lines(this->testfile);
    CPPUNIT_ASSERT(linecount == 1);
}

void fileHandlingTest::count_lines_test_fourlines() {
    this->testfile = fopen("./test/filehandleTest4lines.txt", "r");
    u64 linecount = count_lines(this->testfile);
    CPPUNIT_ASSERT(linecount == 4);
}

void fileHandlingTest::fgetl_test_zerolines() {
    this->testfile = fopen("./test/filehandleTest0lines.txt", "r");
    char* buffer = (char*) calloc(256, sizeof(char));
    size_t stringSize = fgetl(this->testfile, buffer);
    if(buffer != NULL) free(buffer);
    CPPUNIT_ASSERT(stringSize == 0);    
}

void fileHandlingTest::fgetl_test_oneline() {
    this->testfile = fopen("./test/filehandleTest1line.txt", "r");
    char* buffer = (char*) calloc(256, sizeof(char));
    size_t stringSize = fgetl(this->testfile, buffer);
    if(buffer != NULL) free(buffer);
    CPPUNIT_ASSERT(stringSize == 6);    
}

void fileHandlingTest::superchop_with_length_test_zerochars() {
    this->testfile = fopen("./test/filehandleTest0lines.txt", "r");
    char* buffer = (char*) calloc(256, sizeof(char));
    size_t length = fgetl(this->testfile, buffer);

    size_t newlen = superchop_with_length(buffer, length);
    if(buffer != NULL) free(buffer);
    CPPUNIT_ASSERT(length == newlen);
}

void fileHandlingTest::superchop_with_length_test_manychars() {
    this->testfile = fopen("./test/filehandleTest4lines.txt", "r");
    char* buffer = (char*) calloc(256, sizeof(char));
    size_t length = fgetl(this->testfile, buffer);

    //make sure a new line char is at the end because superchop will try to remove it
    buffer[length++] = '\n';
    size_t newlen = superchop_with_length(buffer, length);

    if(buffer != NULL) free(buffer);

    CPPUNIT_ASSERT(length - 1 == newlen);
}

void fileHandlingTest::in_superchop_test_zerochars() {
    this->testfile = fopen("./test/filehandleTest0lines.txt", "r");
    char* buffer = (char*) calloc(256, sizeof(char));
    size_t length = fgetl(this->testfile, buffer);
    size_t newlen = in_superchop(buffer);

    if(buffer != NULL) free(buffer);

    CPPUNIT_ASSERT(length == newlen);
}

void fileHandlingTest::in_superchop_test_manychars() {
    this->testfile = fopen("./test/filehandleTest4lines.txt", "r");
    char* buffer = (char*) calloc(256, sizeof(char));
    size_t length = fgetl(this->testfile, buffer);
    
    //insert a new line to make sure in_superchop has something to remove
    buffer[length++] = '\n';

    size_t newlen = in_superchop(buffer);

    if(buffer != NULL) 
        free(buffer);

    CPPUNIT_ASSERT(length - 1 == newlen);
}


CppUnit::Test *fileHandlingTest::suite(){
	CppUnit::TestSuite* suite = new CppUnit::TestSuite("fileHandling Test");
	suite->addTest(new CppUnit::TestCaller<fileHandlingTest>("count_lines_test_zerolines", &fileHandlingTest::count_lines_test_zerolines));
	suite->addTest(new CppUnit::TestCaller<fileHandlingTest>("count_lines_test_oneline", &fileHandlingTest::count_lines_test_oneline));
	suite->addTest(new CppUnit::TestCaller<fileHandlingTest>("count_lines_test_fourlines", &fileHandlingTest::count_lines_test_fourlines));

	suite->addTest(new CppUnit::TestCaller<fileHandlingTest>("fgetl_test_zerolines", &fileHandlingTest::fgetl_test_zerolines));
	suite->addTest(new CppUnit::TestCaller<fileHandlingTest>("fgetl_test_oneline", &fileHandlingTest::fgetl_test_oneline));

	suite->addTest(new CppUnit::TestCaller<fileHandlingTest>("superchop_with_length_test_zerochars", &fileHandlingTest::superchop_with_length_test_zerochars));
	suite->addTest(new CppUnit::TestCaller<fileHandlingTest>("superchop_with_length_test_manychars", &fileHandlingTest::superchop_with_length_test_manychars));

	suite->addTest(new CppUnit::TestCaller<fileHandlingTest>("in_superchop_test_zerochars", &fileHandlingTest::in_superchop_test_zerochars));
	suite->addTest(new CppUnit::TestCaller<fileHandlingTest>("in_superchop_test_manychars", &fileHandlingTest::in_superchop_test_manychars));

	return suite;
}

