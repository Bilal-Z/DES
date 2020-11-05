#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <cstddef>
#include "roundkeys.hpp"
#include "utils.hpp"

using namespace std;

roundKeyGenerator::roundKeyGenerator(string key)
{
	// turn 64bit input key into cipher key
	// by removing 8th bit of each byte through PC1
	bitset<64> fullKey = hex2bin(key);
	cout << "64bit full key:       " + fullKey.to_string() << endl;

	for (auto i = 0; i < 56; i++)
	{
		cipherKey[55 - i] = fullKey[63 - (PC1[i] - 1)];
	}
	cout << "56bit cipher key:     " + cipherKey.to_string() << endl;

	// break into Ci and Di
	for (auto i = 55; i >= 28; i--)
	{
		Ci[i-28] = cipherKey[i];
	}
	cout << "28bit left half, C0:  " + Ci.to_string() << endl;
	
	for (auto i = 27; i >= 0; i--)
	{
		Di[i] = cipherKey[i];
	}
	cout << "28bit right half, D0: " + string(28, ' ') + Di.to_string() << endl;
	
	
}

bitset<48> roundKeyGenerator::generateRoundKey(int round){
	bitset<48> roundkey;
	// Shift Left both Ci and Di
	// Ci and Di to compression Pbox
	// return round key
	return roundkey;
};