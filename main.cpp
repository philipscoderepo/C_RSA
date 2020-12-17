#include "../std_lib_facilities.h"
#include "RSA.h"
#include <ctime> //remove before submitting
#include <climits>

int main()
{
    unsigned long long p,q,n,lambda,d,e,m,c;
    unsigned int seed;

    cout << "Enter a seed: " << endl;
    cin >> seed;
    
    srand(seed);

    p = getPrime(UCHAR_MAX, USHRT_MAX);
    q = getPrime(UCHAR_MAX, USHRT_MAX);
    
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;

    n = p * q;

    cout << "n: " << n << endl;

    lambda = lcm(p-1,q-1);
    
    cout << "lambda: " << lambda << endl;

    e = getPrime(2, lambda-1);
    
    while((lambda % e) == 0)
    {
        e = getPrime(2, lambda-1);
    }

    cout << "e: " << e << endl;

    d = modInverse(e, lambda);

    cout << "d: " << d << endl;

    cout << "Public key: n = " << n << " e = " << e << endl;
    
    cout << "Private key: n = " << n << " d = " << d << endl;

    cout << "Enter a positive number less than " << n << ":" << endl;
    
    cin >> m; 

    //Ensure m is positive and less than n
    while (m < 0 && m < n)
    {
        cin >> m;
    }
    
    c = modExp(m,e,n);
    //Encrypted
    cout << "Cipher: " << c << endl;

    c = modExp(c,d,n);
    //Decrypted
    cout << "Decrypted cipher: " << c << endl;
    return 0;
}