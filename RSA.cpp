#include "../std_lib_facilities.h"

bool isPrime(unsigned long long n)
{
    bool isP = true;

    for(unsigned long long i=2; i<=sqrt(n); i++) //You only have to go up to the square root of n
    { 
        if((n % i) == 0)
        {
            isP = false;
        }
    } 
    return isP;
}

unsigned long long getPrime(unsigned long long min, unsigned long long max)
{
    unsigned int num = 4;
    
    while(!isPrime(num))
    {
        num = (rand() % (max - min + 1)) + min;
    }

    return num;
}

unsigned long long gcd(unsigned long long x, unsigned long long y)
{
    unsigned long long high, low;
    
    // First find which number is going to be divided into 
    if(x > y)
    {
        high = x;
        low = y;
    }
    else
    {
        high = y;
        low = x;
    }

    unsigned long long lastDivisor = 0;
    
    while((high % low) != 0)
    {
        lastDivisor = high % low;
        high = low; 
        low = lastDivisor;
    }

    return lastDivisor;
}

unsigned long long lcm(unsigned long long x, unsigned long long y)
{
    return (x*y)/gcd(x,y);
}

unsigned long long modInverse(unsigned long long e, unsigned long long lam)
{
    unsigned long long mInv;

    for(unsigned long long d = 1; d<lam; d++)
    {
        if(((d*e)%lam)==1)
        {
            mInv = d;
        }
    }

    return mInv;
}

unsigned long long modExp(unsigned long long base, unsigned long long exp, unsigned long long n)
{
    unsigned long long ans = 1;

    for(unsigned long long i = 0; i < exp; i++)
    {
        ans = (ans * base) % n;
    }
    return ans;
}

