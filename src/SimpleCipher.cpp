//Implementation

#include "SimpleCipher.h"

SimpleCipher::SimpleCipher()
{
    setPlainText("");
    setEncryptionKey(1, 1);
}

SimpleCipher::SimpleCipher(string s, int n1, int n2)
{
    setPlainText(s);
    setEncryptionKey(n1, n2);
}

void SimpleCipher::setPlainText(string s)
{
    plainText = (char *) s.c_str();
}

void SimpleCipher::setEncryptionKey(int f, int s)
{
    encryptionKey = make_pair(f-1, s-1);
}

string SimpleCipher::encrypt()
{
    if(plainText != NULL && plainText[0] == '\0')
        return "";
    if(encryptionKey.first < 0 || encryptionKey.first > 4 ||
       encryptionKey.second < 0 || encryptionKey.second > 4)
        return "";

    int i = 0;
    char c = *(plainText + i);
    char *enc = plainText;

    while (c != '\0')
    {
        int d = c - 'A';

        string newS = toBinary(d);

        swap(newS[encryptionKey.first], newS[encryptionKey.second]);

        double dec = toDecimal(newS);

        char charToAdd = dec > 25 ? c : dec + 'A';

        enc[i] = charToAdd;

        i++;
        c = *(plainText + i);
    }

    return enc;
}

string SimpleCipher::decrypt()
{
    string dec = encrypt();
    return dec;
}

string SimpleCipher::toBinary(int d)
{
    int i = 4;
    string bin = "00000";

    while(d > 0)
	{
		bin[i] = d%2 + '0';

        d /= 2;
        i--;
	}

	return bin;
}

double SimpleCipher::toDecimal(string s)
{
    double d = 0;

    for(int i=0, j=4; i<5; i++, j--)
        if(s[j] == '1')
            d += pow(2.0, i);

    return d;
}

SimpleCipher::~SimpleCipher()
{
    delete[] plainText;
    plainText = NULL;
}
