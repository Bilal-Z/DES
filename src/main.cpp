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

  string hex = text2hex(plaintext[0]);
  cout << hex << endl;
  bitset<64> bin = hex2bin(hex);
  cout << bin << endl;
  string hex2 = bin2hex(bin.to_string());
  cout << hex2 << endl;
  cout << hex2text(hex2) << endl;
  
  return 0;
}