#include <iostream>
#include <string>
#include "roundkeys.hpp"
#include "utils.hpp"

using namespace std;

roundKeyGenerator::roundKeyGenerator(int ck)
{
	this->cipherKey = ck;
	// break into Ci and Di
}

int roundKeyGenerator::generateRoundKey(int cipherkey, int round){
		// Shift Left both Ci and Di
		// Ci and Di to compression Pbox
		// return round key

};