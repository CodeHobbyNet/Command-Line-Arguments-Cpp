#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "CommandLineArguments.h"

class CommandLineArgumentsTest : public CppUnit::TestCase 
{
	private:
		
	public:
		void testParseArguments()
		{//Basic test of parsing a few arguments.
			//Create the test objects.
			int argc = 7;
			char* argv[] = {const_cast<char *>("./CLATest"), const_cast<char *>("-i"), const_cast<char *>("1"), const_cast<char *>("-t=test"), const_cast<char *>("-o"), const_cast<char *>("output.txt"), const_cast<char *>("--tt")};
			
			//Parse the test objects.
			std::map<std::string, std::string> output = CommandLineArguments::CommandLineArguments::parse( argc, argv );

			//Verify the values.
			CPPUNIT_ASSERT( output["i"].compare("1") == 0 );
			CPPUNIT_ASSERT( output["t"].compare("test") == 0 );
			CPPUNIT_ASSERT( output["o"].compare("output.txt") == 0 );
			CPPUNIT_ASSERT( output["tt"].compare("") == 0 );
		}

		//Create the test suite using CPPUnit macros.
		CPPUNIT_TEST_SUITE( CommandLineArgumentsTest );
		CPPUNIT_TEST( testParseArguments );
		CPPUNIT_TEST_SUITE_END( );
};

int main()
{
	CPPUNIT_TEST_SUITE_REGISTRATION( CommandLineArgumentsTest );
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry( );
	runner.addTest( registry.makeTest( ) );
	if ( runner.run( ) )
	{//Runner had success.
		return 0;
	}
	else
	{//Runner failed.
		return 1;
	}
}
