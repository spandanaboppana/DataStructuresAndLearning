#include <iostream>
#include <string>
using namespace std;

/*
 * Prints all the bits of 'n'
 */
void printBits(int n) {

}
/**
 *
 * @param number
 * @param nthBit
 * @return true if nthBit of number is set. false otherwise
 *
 * Example number = 8 (0100), nthBit = 2, returns true.
 * zeroth bit is 0
 * first bit is 0
 * second bit is 1
 */
bool getBit(int number, int nthBit) {

}

/**
 *
 * @param number
 * @param nthBit
 * sets the nthBit of number to 1
 */
int setBit(int number, int nthBit) {

}

/**
 *
 * @param number
 * @param nthBit
 * sets the nthBit of number to 0
 */
int resetBit(int number, int nthBit) {

}

/*
 * gets the next bigger number to n that has the same number of bits set
 *
 * example:
 * Consider 7 - 0000111
 * Next bigger number to 7 that has same digits set is
 *              0001011 ==> 11
 *
 * example
 * Consider 3840
 * Its hex representation    = 0x0F00
 * Its binary representation = 0000 1111 0000 0000
 * Next bigger number is     = 0001 0000 0000 0111
 */
int getNextBigNumberWithSameBitsSet(int n) {

};


int main()
{
    printBits(10);
    printBits(3840);
    assert(getBit(3840, 8));
    assert(getBit(10, 2));
    assert(!getBit(10, 6));
    assert(setBit(0, 2) == 8);
    assert(resetBit(8, 2) == 0);

    return 0;
}
