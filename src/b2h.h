#ifndef _B2H_H
#define _B2H_H

#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

class B2H
{
  public:
    vector<uint8_t> convert(string base32);
  private:
    int strbin2i(const char *s);
    string char2bin(const char s);
    string int2hex(int c);
};

#endif