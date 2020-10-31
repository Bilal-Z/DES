#include <iostream>
#include <string>
#include <bitset>

#include "roundkeys.hpp"
#include "function.hpp"
#include "feistal.hpp"
#include "utils.hpp"

using namespace std;

int main()
{
  string plaintext[] = {"absolute", "abstract", "academic", "accepted", "accident", "accuracy", "accurate", "achieved"};
  // cout << validateInput(bitset<64>(plaintext[0].c_str()).to_ulong(), 64);

  cout << convert2Hex(plaintext[0]) << endl;
  return 0;
}