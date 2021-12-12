/** @file TransactionData.h

 *  @brief Brief description of file.
 * This file demonstrate structure concepts
 * It has classes, Functions and constructions that provide de creation of a geneses block, couple of blocks and a blockchain 
 * That are being used to create transaction information.
 * Demontrate the use of an iterator
 *
 *  Longer description of file.
 * In this case the structure has a double, two strings and a time_t member
 * this conform a couple transaction of transaction that are being verify as valid or not valid using 
 * a hash and a previous hash with an iterator that confirm the block with a one if is valid or with 
 * 0 if is not valid
 * 
 *
 *  @author Name: Sheimy Paz

 *  @bug No known bugs.

 */
#pragma once
#ifndef TransactionData_h
#define TransactionData_h
#include <string> 
#include <ctime>
#include <vector>

using namespace std;


/** @brief Short description of function.
* struct TransactionData initialize attributes
* That are being used to create block for the blockchain
* It has two constructors one default and the other one
* Initializing it attributes

 *

 *Default constructor does not take any parameter
 *TransactionData()noexcept {};

 *Overloaded constructor take 4 parameters
 * TransactionData(double amt, std::string sender, std::string receiver, time_t time)
 * Double, string, string, and time_t
 *

 * Double amount @param is one of the attributes and it is used to specify the number of coins per user transaction
 * string senderKey @param is one of the attribute and it is used to define for the user sending the transaction
 * string receiverKey @param is one of the attribute and it is used to define for the user receiving the transaction
 * time_t timestamp @param is one of the attribute and it is used to define timestamo for each transaction

 *  @return the word void or a description of what is returned
 * No return

 */

struct TransactionData
{
    double amount{ 0 };
    std::string senderKey;
    std::string receiverKey;
    time_t timestamp{ 0 };

    TransactionData()noexcept {};

    TransactionData(double amt, std::string sender, std::string receiver, time_t time)
    {
        amount = amt;
        senderKey = sender;
        receiverKey = receiver;
        timestamp = time;
    };
};
/** @brief Short description of function.
* Class block has 4 private atributes 
* has some getters and setters to access this atributes 
* and and some constructors 
*
*/

class Block
{
private:
    int index;
    size_t blockHash;
    size_t previousHash;
    auto generateHash()->size_t;

public:

    //LO1b->Overload a constructor
    Block(int indx, TransactionData data);

    // Constuctor
    Block(int idx, TransactionData d, size_t prevHash);

    // Get Index
   auto getIndex()->int;

    // Get Original Hash
    auto getHash()->size_t;

    // Get Previous Hash
    auto getPreviousHash()->size_t;

    // Transaction Data
    // ideally will be a private member with a "getter": getData()
    TransactionData data;

    // Validate Hash
    auto isHashValid()->bool;
};

inline Block::Block(int indx, TransactionData data)
{
}

// Constructor with params
Block::Block(int idx, TransactionData d, size_t prevHash)
{
    index = idx;
    data = d;
    previousHash = prevHash;
    blockHash = generateHash();
}


//Generates hash for current block
//- Includes previousHash in generation
auto Block::generateHash()->size_t
{
    //part1
    hash<string> hash1; // hashes transaction data string
    hash<size_t> hash2;
    hash<size_t> finalHash;
    // creating string of transaction data
    string toHash = to_string(data.amount) + data.receiverKey + data.senderKey + to_string(data.timestamp);
    return finalHash(hash1(toHash) + hash2(previousHash));

}

// Public Functions
auto Block::getHash()->size_t { return blockHash; }

// Public Functions
auto Block::getPreviousHash()->size_t { return previousHash; }

// Public Functions 
//making them equal will mada the function invalid  if someone manipulated any transaction data and tried to generate the block again cause the hash willno //be equal again
auto Block::isHashValid()->bool { return generateHash() == getHash(); }


class Blockchain
{
private:
    auto createGenesisBlock()->Block;
 

public:
    std::vector<Block> chain;

    // Constuctor
    Blockchain();

    // Public Functions
    auto getChain()->std::vector<Block>;
    auto getLatestBlock()->Block*;
    auto isChainValid() ->bool;
    void addBlock(TransactionData data);
    //void printChain();
    //auto getIndex()->int;


};

//block chain class members
//constructor 
//default not take any arguments is going to create the genesis block
Blockchain::Blockchain()
{
    Block genesis = createGenesisBlock();
    chain.push_back(genesis); //push genesis block into block chain
}

//first block of the chain only need some data like current time and transaction data
// Genesis Block
auto Blockchain::createGenesisBlock()-> Block
{    
    //part 1
    time_t current = 0;
    TransactionData d;
    d.amount = 0;
    d.receiverKey = "none";
    d.senderKey = "none";
    d.timestamp = time(&current);//pointer to current time
   
    hash<int>hash1;
   // Return Genesis Block
   Block genesis(0, d, hash1(0));
   return genesis;

}

inline auto Blockchain::getChain() -> std::vector<Block>
{
    return std::vector<Block>();
}

//only for demo
//returning pointer
//pointer reference something in memory, it give us a memory addres its a pointer to a memory address
// with this we can manipulate the data inside that memory address
// if we were to do this without a pointer it will return the latest block of the chain but it would be immutable
// since we are returning a memory address wecan manipulate the data inside that address
//
Block* Blockchain::getLatestBlock() { return &chain.back(); }

void Blockchain::addBlock(TransactionData d) {
    int index = (int)chain.size() - 1;
    Block newBlock(index, d, getLatestBlock()->getHash());
}

auto Blockchain::isChainValid()->bool
{
    //part1
    vector<Block>::iterator it; //itereate over a vector of type block
    int chainLen = (int)chain.size();
    for (it = chain.begin(); it != chain.end(); ++it) {

        //if a currecnt block does not have a valid hash is return false

        Block currentBlock = *it;
        if (!currentBlock.isHashValid())
        {
            return false;
        }
        if (chainLen > 1) {
            Block previousBlock = *(it - 1);
            if (currentBlock.getPreviousHash() != previousBlock.getHash())
            {
                return false;
            }
        }
    }
    return true;
}

#endif /* TransactionData_h */

