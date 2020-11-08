#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <cstddef>

#include "roundkeys.hpp"
#include "function.hpp"
#include "feistal.hpp"
#include "utils.hpp"

using namespace std;

int main()
{
  string plaintexts[] = {"absolute", "abstract", "academic", "accepted", "accident", "accuracy", "accurate", "achieved"};

  // TEST CASE 1
  // The DES Algorithm Illustrated
  // Lecture 17

  string cipherText;
  string pt;
  string testCase1Key = "133457799BBCDFF1";
  string testCase1PlainText = "0123456789ABCDEF";
  string testCase1CipherText = "85E813540F0AB405";
  
  DES blockCipher = DES();
  blockCipher.inputKey(testCase1Key);

  cipherText = blockCipher.encrypt(testCase1PlainText);
  pt = blockCipher.decrypt(cipherText);

  cout << "TEST CASE 1 - plain text: " + testCase1PlainText << endl << endl;
  cout << "TEST CASE 1 - calculated cipher text: " + cipherText << endl << endl;
  cout << "TEST CASE 1 - expecteed cipher text: " + cipherText << endl << endl;
  cout << "TEST CASE 1 - calculated plain text: " + pt << endl << endl;

  // TEST CASE 2
  // MAINTENANCE TESTING FOR THE DATAENCRYPTION STANDARD
  // Section 3.2 Page 10
  // https://nvlpubs.nist.gov/nistpubs/Legacy/SP/nbsspecialpublication500-61.pdf

  string key = "5555555555555555";
  string input = "FFFFFFFFFFFFFFFF";
  string output;
  string lastCipher = "BF1FF37BC46CC2CA";
  int testLength = 3;
  for (auto i = 0; i < testLength; i++)
  {
    blockCipher.inputKey(key);
    output = blockCipher.encrypt(input);
    input = output;
    output = blockCipher.encrypt(input);
    key = output;
    blockCipher.inputKey(key);
    output = blockCipher.decrypt(input);
    key = output;
  }
  cout << "TEST CASE 2 - calculated last cipher: " + output << endl << endl;

  return 0;
}