/** @file name: main.cpp

 *  @brief description of file.
 * This file demonstrates the object creation.
 * The use of function callers
 * The process of encapsulation
 * The process of aggregation 
 *Etc.
 * 
 * Longer description of file.
 * This file has the main function, there are to objects one for the User Class and the other for the User Info class
 * There is a function call printing the above comment to meeting requirement LO4  
 * OOP is a programming style based on the concept of objects which may contain data in the form of fields (Attributes) and code in the form of procedure (Methods)
 * Procedural programming is based on the concept of the procedure call also known as routines, subroutines, or functions. (Computational steps)
 * Functional programming style is based on the concept of evaluation of mathematical functions and avoid changing state and mutable data
 * There are other function demonstrating concepts like default and overload constructors
 * Encapsulation is also demonstrated in this file using setters and getters as well as aggregation concepts.


 *  @author Name Sheimy Paz

 *  @bug No known bugs.
 * 
 */


#include<iterator>
#include <iostream>
#include <ctime>
#include <vector>
#include <string> 

#include "User.h"
#include "UserInfo.h"
#include "TransactionData.h"

using namespace std;



/** @brief Short description of function.
* Create objects User generalUser and UserInfo individualUsers
* some callers
 *
 *  @return The word void or a description of what is returned
 * it is returnning an integer

 */
auto main()->int {

    // Creating an objects of my base class User and subclass UserInfo to this will call the constructor
    User generalUser;
    UserInfo individualUsers;


    //Callers
    individualUsers.printComparison();
    generalUser.myFunction();
    generalUser.myFunction("\nAnd additionally", " Demostrate the concept of Costruction Overloading");
    individualUsers.print();


    //Encapsulation
    individualUsers.set(5);
    std::cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
    std::cout << "This line of code shows encapsulation, The private varible x is set to "<< individualUsers.get()<<" and then it is access to it through a getter";
    std::cout << "\n-----------------------------------------------------------------------------------------------------------------------";


    //block chain code start here
    Blockchain PazCoin;
 
    //data for first block
    TransactionData data1;
    time_t data1Time;
    data1.amount = 1.5;
    data1.receiverKey = "From Sher";
    data1.senderKey = "To Ross.";
    data1.timestamp = time(&data1Time);

    std::cout << "\n\n-----------------------------------------------------------------------------------------------------------------------";
    PazCoin.addBlock(data1);
    //Using agregation
    Address add1 = Address(data1.amount, data1.receiverKey, data1.senderKey, data1.timestamp = time(&data1Time));
    Person p1 = Person(" Transfering", &add1);
    p1.display();
    //if the chain is valid we are getting 1
    cout << "It's chain Valid?" << endl << PazCoin.isChainValid() << endl;
    std::cout << "-----------------------------------------------------------------------------------------------------------------------";


    //data for second block
    TransactionData data2;
    time_t data2Time;
    data2.amount = 5.9;
    data2.receiverKey = "From David";
    data2.senderKey = "To Paul.";
    data2.timestamp = time(&data2Time);

    std::cout << "\n\n-----------------------------------------------------------------------------------------------------------------------";
    PazCoin.addBlock(data2);
    //Using agregation
    Address add2 = Address(data2.amount, data2.receiverKey, data2.senderKey, data2.timestamp = time(&data2Time));
    Person p2 = Person(" Transfering", &add2);
    p2.display();
    //if the chain is valid we are getting 1
    cout << "It's chain Valid?" << endl << PazCoin.isChainValid() << endl;
    std::cout << "-----------------------------------------------------------------------------------------------------------------------\n";


    //trying to manipulate data-> get sneaky
    Block* hackBlock = PazCoin.getLatestBlock();
    hackBlock->data.amount = 1000;
    hackBlock->data.receiverKey = "thief";

    //if the chain is not valid we are getting 0
   //Using agregation
    Address add3 = Address(hackBlock->data.amount, hackBlock->data.receiverKey, "Triying to steal. Curent Time Stamp:", data1.timestamp = time(&data1Time));
    Person thief = Person(" Transfering", &add3);
    thief.display();
    cout << "It's chain Valid?" << endl << PazCoin.isChainValid() << endl;
    std::cout << "-----------------------------------------------------------------------------------------------------------------------\n";
    return 0;
}


