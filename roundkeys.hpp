#ifndef ROUND_KEYS_H
#define ROUND_KEYS_H

class roundKeyGenerator
{
private:
  int ci;
  int di;
  int cipherKey;

public:
  roundKeyGenerator(int ck);
  int generateRoundKey(int cipherkey, int round);
};

#endif