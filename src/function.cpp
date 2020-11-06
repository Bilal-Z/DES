#include <iostream>
#include <string>
#include <bitset>

#include "function.hpp"
#include "utils.hpp"

using namespace std;

roundFunction::roundFunction(){
	
}

bitset<32> roundFunction::function(bitset<32> RiMinusOne, bitset<48> ki)
{
	bitset<32> output;
	// expand Ri-1 to 48bits using E(expand Pbox)
	bitset<48> expandedR;
	for (auto i = 0; i < 48; i++)
	{
		expandedR[47 - i] = RiMinusOne[31 - (E[i] - 1)];
	}
	cout << "expanded Ri-1: " + expandedR.to_string() << endl;
	
	// XOR with round key
	expandedR ^= ki;
	cout << "expanded Ri-1 XOR Ki: " + expandedR.to_string() << endl;

	// pass through S boxes
	int column;
	int row;
	int substitutionNumber;
	bitset<4> outputBits;
	int k = 31; // Output bits Counter
	int j = 0; // Sbox counter
	for (auto i = 0; i < 48; i+=6)
	{
		// take ith block of 6 bits
		// use first and 6th bit to calculate row number
		row = (expandedR[47 - i] * 2) + expandedR[47 - i - 5];
		// use middle 4 for column number
		column =  (expandedR[47 - i - 1] * 8) + (expandedR[47 - i - 2] * 4) + 
					(expandedR[47 - i - 3] * 2) + expandedR[47 - i - 4];
		// get number on that row and column from jth Sbox
		substitutionNumber = SBoxes[j++][row][column];

		outputBits = bitset<4>(substitutionNumber);

		output[k--] = outputBits[3];
		output[k--] = outputBits[2];
		output[k--] = outputBits[1];
		output[k--] = outputBits[0];
	}
	
	// pass through straight Pbox
	bitset<32> temp = output;
	for (auto i = 0; i < 32; i++)
	{
		output[31 - i] = temp[31 - (P[i] - 1)];
	}

	return output;
}