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
  // Scope: Generate random keys, and generate cipher texts for 10 plain texts messages.
  string cipherKey = "908567A3F43B11CC";
  string plaintexts[10] = {"absolute", "abstract", "academic", "accepted", "accident", "accuracy", "accurate", "achieved", "acquired", "activity"};
  string ciphertexts[10];
  string decryptedPlaintexts[10];

  DES blockCipher = DES();
  blockCipher.inputKey(cipherKey);
  for (auto i = 0; i < 10; i++)
  {
    ciphertexts[i] = blockCipher.encrypt(text2hex(plaintexts[i]));
    decryptedPlaintexts[i] = hex2text(blockCipher.decrypt(ciphertexts[i]));
  }

  for (auto i = 0; i < 10; i++)
  {
    cout << "Plaintext: " + plaintexts[i] + "\tCiphertext: " + ciphertexts[i] + "\tDecrypted Plaintext: " + decryptedPlaintexts[i] << endl;
  }
  cout << endl;
  
  
  // TEST CASE 1
  // The DES Algorithm Illustrated
  // Lecture 17

  string cipherText;
  string plaintext;
  string testCase1Key = "133457799BBCDFF1";
  string testCase1PlainText = "0123456789ABCDEF";
  string testCase1CipherText = "85E813540F0AB405";
  
  
  blockCipher.inputKey(testCase1Key);

  cipherText = blockCipher.encrypt(testCase1PlainText);
  plaintext = blockCipher.decrypt(cipherText);

  cout << "TEST CASE 1 - plain text: " + testCase1PlainText << endl << endl;
  cout << "TEST CASE 1 - encrypted cipher text: " + cipherText << endl << endl;
  cout << "TEST CASE 1 - expecteed cipher text: " + testCase1CipherText << endl << endl;
  cout << "TEST CASE 1 - decrypted plain text: " + plaintext << endl << endl;

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