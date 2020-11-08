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
  string plaintext[] = {"absolute", "abstract", "academic", "accepted", "accident", "accuracy", "accurate", "achieved"};
  string cipherText;

  string testCase1Key = "133457799BBCDFF1";
  string testCase1PlainText = "0123456789ABCDEF";
  string testCase1CipherText = "85E813540F0AB405";
  
  DES blockCipher = DES();
  blockCipher.inputKey(testCase1Key);

  cout << "plain text: " + testCase1PlainText << endl << endl;
  cipherText = blockCipher.encrypt(testCase1PlainText);
  cout << "cipher text: " + cipherText << endl << endl;
  return 0;
}