#include <b2h.h>

int B2H::strbin2i(const char* s) {
    unsigned int r=0;unsigned char c;while(s&&*s){c=*s++;if(c=='0'){r=(r<<1);}
    else if(c=='1'){r=(r<<1)+1;}
    else{break;}}
    return(int)r;
}

string B2H::char2bin(const char s){
    string str;for(int i=4;i>=0;i--){str.append(1,(s&(1<<i))?'1':'0');}
    return str;
}

string B2H::int2hex(int c){
    string result;
    stringstream ss;
    ss << std::hex <<c;
    ss >> result;
    return result;
}

vector<uint8_t> B2H::convert(string base32)
{
    vector<uint8_t> hmacHex;
    string base32chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
    string bits;
    string hexs;

    for (int i=0; i < base32.length(); i++)
    {
        char c = toupper(base32.at(i));
        char val = base32chars.find(c);
        bits.append(char2bin(val));
    }

    for (int i=0; (i+4) <= bits.length(); i+=4)
    {
        string chunk = bits.substr(i, 4);
        int todec = strbin2i(chunk.c_str());
        hexs.append(int2hex(todec).c_str());
    }

    for (int i=0; (i+2) <= hexs.length(); i+=2) 
    {
        int hexNumber;
        sscanf(hexs.substr(i, 2).c_str(), "%x", &hexNumber);
        hmacHex.push_back(hexNumber);
    }

    uint8_t * hmacHex2 = &hmacHex[0];
    return hmacHex;
}