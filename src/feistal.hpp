#ifndef FEISTAL_H
#define FEISTAL_H
#include <string>
#include <bitset>
#include <sstream>

#include "function.hpp"

using namespace std;

class feistalNetwork {
	private:
		bitset<64> text;
		bitset<32> Li;
		bitset<32> Ri;
		roundFunction f;
	public:
		feistalNetwork(bitset<64> t);
		void encryptionRound();
		void decryptionRound();
};

#endif