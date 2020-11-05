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

  string key = "133457799BBCDFF1";
  
  roundKeyGenerator gen = roundKeyGenerator(key);
  gen.generateRoundKey(0);
  gen.generateRoundKey(1);
  
  return 0;
}