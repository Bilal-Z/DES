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
	// expand Ri-1 to 48bits
	bitset<48> expandedR;
	for (auto i = 0; i < 48; i++)
	{
		expandedR[47 - i] = RiMinusOne[31 - (E[i] - 1)];
	}
	cout << "expanded Ri-1: " + expandedR.to_string() << endl;
	
	// XOR with round key
	expandedR ^= ki;
	cout << "expanded Ri-1 XOR Ki: " + expandedR.to_string() << endl;

	// pass through s boxes
	// pass through straight pbox
}