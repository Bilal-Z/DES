#ifndef HELPER_H
#define HELPER_H
#include <string>
#include <bitset>
using namespace std;
bool validateInput(int input, int bits);
string text2hex(string input);
bitset<64> hex2bin(string input);
string bin2hex(string input);
string hex2text(string input);

#endif