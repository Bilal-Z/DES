#include <iostream>
#include <string>
#include <bitset>
#include <sstream>

#include "feistal.hpp"
#include "roundkeys.hpp"
#include "utils.hpp"

DES::DES(){

}

void DES::inputKey(string key){
	roundKeyGenerator generator(key);
	for (auto i = 0; i < NUM_ROUNDS; i++)
	{
		roundKeys[i] = generator.generateRoundKey(i);
	}
	
}

void DES::encryptRound(int round){
	bitset<32> LiMinusOne = Li;
	bitset<32> RiMinusOne = Ri;
	Li = RiMinusOne;
	Ri = LiMinusOne ^ f.function(RiMinusOne, roundKeys[round]);
	cout << "L" << round + 1 << ": " + Li.to_string() << endl;
	cout << "R" << round + 1 << ": " + Ri.to_string() << endl<<endl;
}


string DES::encrypt(string plaintext){
	cout << "----------ENCRYPTION----------" << endl;
	bitset<64> PT = hex2bin(plaintext);
	cout << "64bit plaintext:          " + PT.to_string() << endl;
	bitset<64> PT_IP;
	// initial permutation through IP
	for (size_t i = 0; i < 64; i++)
	{
		PT_IP[63 - i] = PT[63 - (IP[i] - 1)];
	}
	cout << "64bit plaintext after IP: " + PT_IP.to_string() << endl;

	// break into Li and Di
	for (auto i = 63; i >= 32; i--)
	{
		Li[i - 32] = PT_IP[i];
	}
	cout << "32bit left half, L0:      " + Li.to_string() << endl;
	
	for (auto i = 31; i >= 0; i--)
	{
		Ri[i] = PT_IP[i];
	}
	cout << "32bit right half, R0:     " + string(32, ' ') + Ri.to_string() << endl << endl;

	// 16 rounds
	for (auto i = 0; i < NUM_ROUNDS; i++)
	{
		encryptRound(i);
	}
	
	// reverse order make R16L16
	bitset<64> R16L16(Ri.to_string() + Li.to_string());
	cout << "R16L16: " + R16L16.to_string() << endl << endl;

	// apply inverse of initial permutation
	bitset<64> CT;
	for (size_t i = 0; i < 64; i++)
	{
		CT[63 - i] = R16L16[63 - (IPinverse[i] - 1)];
	}
	
	cout << "after inverse initial permutation: " + CT.to_string() << endl << endl;

	return bin2hex(CT.to_string());
}

// -----------------Decryption----------------------------
void DES::decryptRound(int round){
	bitset<32> LiMinusOne = Li;
	bitset<32> RiMinusOne = Ri;
	Li = RiMinusOne;
	Ri = LiMinusOne ^ f.function(RiMinusOne, roundKeys[15 - round]);
	cout << "L" << round + 1 << ": " + Li.to_string() << endl;
	cout << "R" << round + 1 << ": " + Ri.to_string() << endl<<endl;
}


string DES::decrypt(string ciphertext){
	cout << "----------DECRYPTION----------" << endl;
	bitset<64> CT = hex2bin(ciphertext);
	cout << "64bit ciphertext:          " + CT.to_string() << endl;
	bitset<64> CT_IP;
	// initial permutation through IP
	for (size_t i = 0; i < 64; i++)
	{
		CT_IP[63 - i] = CT[63 - (IP[i] - 1)];
	}
	cout << "64bit ciphertext after IP: " + CT_IP.to_string() << endl;

	// break into Li and Di
	for (auto i = 63; i >= 32; i--)
	{
		Li[i - 32] = CT_IP[i];
	}
	cout << "32bit left half, L0:      " + Li.to_string() << endl;
	
	for (auto i = 31; i >= 0; i--)
	{
		Ri[i] = CT_IP[i];
	}
	cout << "32bit right half, R0:     " + string(32, ' ') + Ri.to_string() << endl << endl;

	// 16 rounds
	for (auto i = 0; i < NUM_ROUNDS; i++)
	{
		decryptRound(i);
	}
	
	// reverse order make R16L16
	bitset<64> R16L16(Ri.to_string() + Li.to_string());
	cout << "R16L16: " + R16L16.to_string() << endl << endl;

	// apply inverse of initial permutation
	bitset<64> PT;
	for (size_t i = 0; i < 64; i++)
	{
		PT[63 - i] = R16L16[63 - (IPinverse[i] - 1)];
	}
	
	cout << "after inverse initial permutation: " + PT.to_string() << endl << endl;

	return bin2hex(PT.to_string());
}