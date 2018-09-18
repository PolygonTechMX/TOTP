TOTP++ Library
====================

Library to generate Time-based One-Time Passwords.

Implements the Time-based One-Time Password algorithm specified in [RFC 6238](https://tools.ietf.org/html/rfc6238). Supports different time steps and it's compatible with tokens that uses the same standard (including software ones, like the Google Authenticator app).


Installation & usage:
--------------------
Install the library using the Library Manager or manually in the \libraries folder of your IDE

First, store your private key into an array:
```
std::string hmacKey = "JBSWY3DPEHPK3PXP";
```
Then create a new instance of the TOTP class using one of the two available constructors:
```
TOTP totp = TOTP();
```
The first assumes a timeStep of 30 seconds, value used for example by the Google Authenticator app.

Two methods are available to get a TOTP passcode:
```
char *newCode = totp.getCode(key, 30, GMT);
```
The first accept a unix timestamp (number of seconds since Epoch), the second the number of "steps" since Epoch (that is seconds / timeStep) and it's useful to get a pool of values.

Thanks to:
----------

* lucadentella, https://github.com/damico/TOTP-Arduino
* Jose Damico, https://github.com/damico/ARDUINO-OATH-TOKEN
* Peter Knight, https://github.com/Cathedrow/Cryptosuite
* Maniacbug, https://github.com/maniacbug/Cryptosuite