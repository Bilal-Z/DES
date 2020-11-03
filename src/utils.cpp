#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <bitset>
#include <cstddef>
#include "utils.hpp"

using namespace std;

bool validateInput(long input, int bits)
{
  return (int)log2(input) + 1 == bits;
}

string text2hex(string input)
{
  stringstream output;

  for (size_t i = 0; i < input.length(); i++)
  {
    output << hex << setfill('0') << setw(2) << int(input[i]);
  }
  return output.str();
}

bitset<64> hex2bin (string input){
  stringstream ss;
  ss << hex << input;
  unsigned long n;
  ss >> n;
  return bitset<64> (n);
}

string bin2hex(string input){
  bitset<64> b(input);
  unsigned long n = b.to_ulong();
  stringstream ss;
  ss << hex << n;
  return ss.str();
}

string hex2text(string input){
  string output;
  string byte;
  char c;
  for (auto i = 0; i < 16; i+=2)
  {
    byte = input.substr(i,2);
    c = (char) (int)strtol(byte.c_str(), nullptr, 16);
    output.push_back(c);
  }
  return output;
}
