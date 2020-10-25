#include <iostream>
#include <string>

using namespace std;

class roundKeyGenerator{
	private:
	int ci;
	int di;
	int cipherKey;

	public:
	roundKeyGenerator(int ck){
		this->cipherKey = ck;
		// break into Ci and Di
	}

	int generateRoundKey(int cipherkey){
	// Shift Left both Ci and Di
	// Ci and Di to compression Pbox
	// return round key
}
};