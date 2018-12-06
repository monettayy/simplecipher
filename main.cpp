//Fornaleza, Monette L.
//Driver

#include "SimpleCipher.h"

int main()
{

    string plainText = "PROGRAM";
    SimpleCipher cipher1 (plainText, 2, 5);
    cout << "PLAINTEXT = " << plainText << endl;
    cout << "ENCRYPT = " << cipher1.encrypt() << endl;
    cout << "DECRYPT = " << cipher1.decrypt() << endl << endl;

    SimpleCipher cipher;
    string p = "UNIVERSITY";
    cipher.setPlainText(p);
    cipher.setEncryptionKey(1,4);
    string s = cipher.encrypt();
    cout << "PLAINTEXT = " << p << endl;
    cout << "ENCRYPT = " << s << endl;
    cout << "DECRYPT = " << cipher.decrypt() << endl;

    return 0;
}
