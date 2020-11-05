#ifndef HELPER_H
#define HELPER_H
#include <string>
#include <bitset>
using namespace std;

string text2hex(string input);
bitset<64> hex2bin(string input);
string bin2hex(string input);
string hex2text(string input);

// discovered bitset does not have shift rotate neede for des
// used rotate implementation by YSC from 
// https://stackoverflow.com/questions/47452703/overload-the-shift-operators-of-stdbitset
struct rotate
{
    rotate(std::size_t n) : value(n) {}
    std::size_t value;
};


template <std::size_t size>
std::bitset<size>& operator<<=(std::bitset<size>& bitset, rotate r) noexcept {
    bitset = bitset << r.value | bitset >> (size-r.value);
    return bitset;
}
#endif