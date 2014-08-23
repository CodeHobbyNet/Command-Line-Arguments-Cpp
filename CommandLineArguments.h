#ifndef CommandLineArguments_h
#define CommandLineArguments_h

/*
The MIT License (MIT)

Copyright (c) 2014 Code Hobby

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
See the GitHub repository at: https://github.com/CodeHobbyNet/Command-Line-Arguments-Cpp
*/

#include <map>
#include <string>

namespace CommandLineArguments
{
	class CommandLineArguments
	{//A class to convert command line arguments to a map for easier processing by another class.
		private:

		public:
			static std::map<std::string, std::string> parse( int argc, char* argv[] );//A method to parse the argc and argv arguments from main into a map. The key is the argument and the value is the value associated with the key, if there is one. For example, "-p 0" will have a key of "p" and a value of "0".
	};
}

#endif /* CommandLineArguments_h */
