/** @file name: User.cpp
*
 * @brief description of file.
 * This file as a header file with a non-trivial method implemented
 * A comment meeting requirement LO1a
 * It demonstrate construction overloading 
 *
 *
 * Longer description of file.
 * No necessary 

 *  @author Name Sheimy Paz

 *  @bug No known bugs.
 */

#include "User.h"


//LO1a.At least one class in a header file with non - trivial methods implemented in a cpp file

void User::myFunction() { 
	std::cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
	std::cout << "This part of the code demostrate the content of the base class in a header file being implementd on a cpp file." << name; }

void User::myFunction(std::string a, std::string b) {
	std::cout << a << b;
}
void User::myFunction(std::string a) {}
