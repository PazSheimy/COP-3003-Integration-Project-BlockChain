/** @File name:UserInfo.h

 * @brief Brief description of file.
 * this file demonstrates the use of subclassing the design of a simple class.
 * Hierarchies allowing code to be reuse.
 * Subclass User Info from User base class.
 * 
 * 
 * Longer description of file.
 * It prints information to screen.
 * Some explanation about the project and its purpose.
 * Has some string attributes explaining the comparison between OOP PP and FP.
 * Uses subclassing.
 * Demonstrate the concept of constructors.
 * Has an int private attribute used to demonstrate encapsulation.
 * Has comments describing visibility on inheritance models.
 * Has comments describing relationship between object-oriented inheritance and subtyping.
 * 
 * 
 *  @author name: Sheimy Paz

 *  @bug No known bugs.
 */
#pragma once
#include "User.h"
using namespace std;

/** @brief Short description of function.
* Clase UserInfo which is derived fron base class User
* Has a private member x user to demonstrate encapsulation 

 *

 *  Longer description of function.

 *

 *  @param One for each parameter with the name and a description
 * N/A

 *  @return The word void or a description of what is returned
 * none

 */
//LO2.Use subclassing to design simple class hierarchies that allow code to be reused for distinct subclasses.
class UserInfo :
	public User
{
private:
	// data hidden from outside world
	int x =0;


public:
	//LO4.Include a comment in which you compareand contrast the procedural / functional approach and the object - oriented approach
	string welcome = "In this project we are going to see implementation of key learning skills form Object oriented programing class.\nAlong with that there is a small and very basic block chain implementation with the object of understand how it works.\n";
	string opp = "OOP is a programming style based on the concept of objects which may contain data in the form of fields(Attributes) and code in the form of procedure (Methods).\n";
	string pp = "Procedural programming is based on the concept of the procedure call also known as routines, subroutines, or functions (Computational steps).\n";
	string fp = "Functional programming style is based on the concept of evaluation of mathematical functions and avoid changing state and mutable data.\n";


	// constructor is a special method that is automatically called when an object of a class is created.
	//To create a constructor, use the same name as the class, followed by parentheses ():
	UserInfo() {}

	void printComparison() {
		cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
		cout << welcome;
		cout << "-----------------------------------------------------------------------------------------------------------------------\n";
		cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
		cout<< "Comparison between Procedural/Funtional and OOP approach: \n\n" << opp << pp << fp;
		cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	}

	/*LO2a.Include comments describing the visibility inheritance model
	* When a base class is derived by a derived class with the help of inheritance, the accessibility of base class by the derived class is controlled by visibility modes.
	* The derived class doesn’t inherit access to private data members.However, it does inherit a full parent object, which contains any private members which that class declares.
	* for example:
	* A public member visibility will be open to all.It means that any class can accessand use this members.
	* A protected member visibility will be only to the derived class.It means that any derived class can accessand use any protected member.
	* A private member visibility will not be open to any other class.It means that any derived class cannot access or use its members.*/


	/*LO5.Explain the relationship between object - oriented inheritance(code - sharing and overriding) and subtyping(the idea of a subtype being usable in a context that expects the supertype).
	* subtyping(also subtype polymorphism or inclusion polymorphism) is a form of type polymorphism in which a subtype is a datatype that is related to another datatype(the supertype) 
	* by some notion of substitutability, meaning that program elements, typically subroutines or functions, written to operate on elements of the supertype can also operate on elements of the subtype.
	
	* In object-oriented programming, inheritance is the mechanism of basing an object or class upon another object (prototype-based inheritance) or class (class-based inheritance), retaining similar 
	* implementation. Also defined as deriving new classes (sub classes) from existing ones such as super class or base class and then forming them into a hierarchy of classes. In most class-based 
	* object-oriented languages, an object created through inheritance, a "child object", acquires all the properties and behaviors of the "parent object", with the exception of: constructors, destructor, 
	* overloaded *operators and friend functions of the base class.
	*/
		//function to set value of 
		// variable x
	void set(int a)
	{
		x = a;
	}

	// function to return value of
	// variable x
	int get()
	{
		return x;
	}
	void print() { 
		cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
		cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
		cout << x;
		cout << "This line of code represent the use of a sub class and describe the visibility inheritance model.\n";
		cout << "A public member visibility will be open to all.It means that any class can accessand use this members.\nA protected member visibility will be only to the derived class. It means that any derived class can accessand use any protected member.\nA private member visibility will not be open to any other class.It means that any derived class cannot access or use its members.\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	}

protected:
};

