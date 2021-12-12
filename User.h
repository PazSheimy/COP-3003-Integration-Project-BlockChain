/** @File name: User.h

 *  @brief Brief description of file.

 *this file demonstrate the disign of a simple class named User
 *which is reused to make class named: UserInfo using hierarchies

 * Longer description of file.
 * it print information to screen
 *
 *  @author name: Sheimy Paz

 *  @bug No known bugs.
 */

#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <string> 

 //LO1.Designand implement a class.
 //LO1a. At least one class in a header file with non-trivial methods implemented in a cpp file 
 //Class name: User
class User{
private:

public:

    std::string name{};
    std::string a = "a";
    std::string b = "b";


    //LO1b.Overload a constructor
    void myFunction();
    void myFunction(std::string a, std::string b);

    void myFunction(std::string a);//function declaration
    //LO1c.Utilize an initialization list
    User() {}
    User(std::string name) : name("ale")
    {
    }


protected:

};

class Address
{
public:

    double amountC;
    std::string sender, receiver;
    time_t timeStamp = 0;
    Address(double amountC, std::string sender, std::string receiver, time_t timeStamp)
    {
        this->amountC = amountC;
        this->sender = sender;
        this->receiver = receiver;
        this->timeStamp = timeStamp;
    }
};
class Person
{
private:
    Address* address;
public:
    std::string name;
    Person(std::string name, Address* address)
    {
        this->name = name;
        this->address = address;
    }
    void display()
    {
        std::cout << name << " " << " " << address->amountC << " " << address->sender << " " << address->receiver << " " << address->timeStamp << std::endl;
    }
};


