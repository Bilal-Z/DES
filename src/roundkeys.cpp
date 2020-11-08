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
		Ci[i - 28] = cipherKey[i];
	}
	cout << "28bit left half, C0:  " + Ci.to_string() << endl;
	
	for (auto i = 27; i >= 0; i--)
	{
		Di[i] = cipherKey[i];
	}
	cout << "28bit right half, D0: " + string(28, ' ') + Di.to_string() << endl << endl;
	
	
}

bitset<48> roundKeyGenerator::generateRoundKey(int round){
	bitset<48> roundKey;
	// Shift Left both Ci and Di
	// by number in NumOfLeftShifts array
	Ci <<= rotate(NumOfLeftShifts[round]);
	Di <<= rotate(NumOfLeftShifts[round]);

	cout << "----------ROUND" << round + 1 << "----------" << endl;
	cout << "C" << round + 1 << ": " + Ci.to_string() << endl;
	cout << "D" << round + 1 << ": " + Di.to_string() << endl << endl;

	// concatenate Ci and Di
	bitset<56> CiDi = bitset<56>(Ci.to_string() + Di.to_string());
	cout << "C" << round + 1 << "D" << round + 1 << ": " + CiDi.to_string() << endl << endl;

	// Ci and Di to compression Pbox
	for (auto i = 0; i < 48; i++)
	{
		roundKey[47 - i] = CiDi[55 - (PC2[i] - 1)];
	}
	cout << "K" << round + 1 << ": " + roundKey.to_string() << endl << endl;

	// return round key
	return roundKey;
};