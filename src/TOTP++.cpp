#include "TOTP++.h"
#include <Arduino.h>

B2H b2h = B2H();

// Generate a code, using the timestamp provided
char* TOTP::getCode(string hmacKey, int timeStep, long timeStamp) {
	vector<uint8_t> hkt = b2h.convert(hmacKey);

    uint8_t hk[hkt.size()];
	for (int i=0; i < hkt.size(); i++)
    {
        hk[i] = hkt[i];
    }

	_hmacKey = hk;
	_keyLength = hkt.size();
	_timeStep = timeStep;
	
	long steps = timeStamp / _timeStep;
	return getCodeFromSteps(steps);
}

char* TOTP::getCodeFromSteps(long steps) {	
	_byteArray[0] = 0x00;
	_byteArray[1] = 0x00;
	_byteArray[2] = 0x00;
	_byteArray[3] = 0x00;
	_byteArray[4] = (int)((steps >> 24) & 0xFF);
	_byteArray[5] = (int)((steps >> 16) & 0xFF);
	_byteArray[6] = (int)((steps >> 8) & 0XFF);
	_byteArray[7] = (int)((steps & 0XFF));

	Sha1.initHmac(_hmacKey, _keyLength);
	Sha1.write(_byteArray, 8);
	_hash = Sha1.resultHmac();

	_offset = _hash[20 - 1] & 0xF;
	_truncatedHash = 0;
	for (int j = 0; j < 4; ++j) {
	  _truncatedHash <<= 8;
	  _truncatedHash |= _hash[_offset + j];
	}
	_truncatedHash &= 0x7FFFFFFF;
	_truncatedHash %= 1000000;

	sprintf(_code, "%06ld", _truncatedHash);
	return _code;
}
