//Header

#include <iostream>
#include <utility>
#include <math.h>
#include <cstring>

using namespace std;

class SimpleCipher
{
    public:
        SimpleCipher();
        SimpleCipher(string, int, int);

        void setPlainText(string);
        void setEncryptionKey(int, int);

        string encrypt();
        string decrypt();

        virtual ~SimpleCipher();

    protected:

    private:
        char *plainText;
        pair<int, int> encryptionKey;

        string toBinary(int);
        double toDecimal(string);
};
