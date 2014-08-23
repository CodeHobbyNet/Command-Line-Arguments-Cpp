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

#include "CommandLineArguments.h"
#include <stdexcept>
#include <sstream>
#include <iostream>

namespace CommandLineArguments
{
	std::map<std::string, std::string> CommandLineArguments::parse( int argc, char* argv[] )
	{//A method to parse the argc and argv arguments from main into a map. The key is the argument and the value is the value associated with the key, if there is one. For example, "-p 0" will have a key of "p" and a value of "0".
		std::map<std::string, std::string> parametersMap;
		std::string arg = "";//A temporary holder of an argument.
		std::string doubleDash = "--";//A string value for the double dash.
		std::string dash = "-";//A string value for the single dash.

		int i = 1;
		while( i < argc )
		{
			arg.assign( argv[i] );

			if( arg.compare( 0, 2, doubleDash) == 0 )
			{//If the first two characters of the argument is a double dash, take that part off the argument.
				arg.erase( 0, 2 );//Erase the first two characters of the string.
			}
			else if( arg.compare( 0, 1, dash ) == 0 )
			{//If the first character of the argument is a dash, take that part off the argument.
				arg.erase( 0, 1 );//Erase the first character of the string.
			}
			else
			{//The argument doesn't have a single dash when the method is looking for it.
				std::stringstream errorMessage;
				errorMessage << "Error parsing the command line arguments at argument " << i << "(counting from 0)";
				throw std::invalid_argument( errorMessage.str() );
			}

			size_t positionOfEqualsCharacter = arg.find("=");
			if( positionOfEqualsCharacter != std::string::npos )
			{//If the argument has a = character in it, that means it's of the format "argument=value", so parse it that way.
				parametersMap[arg.substr( 0, positionOfEqualsCharacter )] = arg.substr( positionOfEqualsCharacter + 1 );
			}
			else if( (i+1 < argc) && (dash.compare(0, 1, argv[i+1], 1) != 0 ) )
			{//If this isn't an equals type of argument, meaning it might be something like "-i 0", check if the next one has a dash in the beginning. If it doesn't, put both parts in the map.
				i++;//Increment i so the method will move to the second part of this argument.
				std::string arg2 = argv[i];//Create a string ot of the second part of the argument so that it can go to the map.
				parametersMap[arg] = arg2;
			}
			else
			{//This is just a single argument without an equals sign, like "-i", so just add it to the map with a null value.
				parametersMap[arg] = "";
			}

			i++;//Increment i to go to the next value.
		}

		return parametersMap;
	}
}
