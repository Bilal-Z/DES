#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h>
#include "utils.hpp"

using namespace std;

bool validateInput(int input, int bits)
{
  return (int)log2(input) + 1 == bits;
}

string convert2Hex(string input)
{
  stringstream output;

  for (size_t i = 0; i < input.length(); i++)
  {
    output << hex << setfill('0') << setw(2) << int(input[i]);
  }
  return output.str();
}