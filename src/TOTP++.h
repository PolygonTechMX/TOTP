#include "sha1.h"
#include "b2h.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#ifndef _TOTP_H
#define _TOTP_H

class TOTP {

	public:
		char* getCode(string hmacKey, int timeStep, long timeStamp);
		char* getCodeFromSteps(long steps);
	
	private:
		uint8_t* _hmacKey;
		int _keyLength;
		int _timeStep;
		uint8_t _byteArray[8];
		uint8_t* _hash;
		int _offset;
		long _truncatedHash;
		char _code[7];
};

#endif