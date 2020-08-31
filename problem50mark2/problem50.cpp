#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define N 1000000
using namespace std;

int isprime[N];

bool isPrime(int);

int main() {

    int number;

    cin >> number;

    for (int i = 0; i < number;i++)
        isprime[i] = 2;

    int i = 2; int fmax = 0, Ans;
    while (i < number / 2) {
        int j = i; int f = 0; int sum = 0; int Prime, fPrime;
        while (1) {
            if (isPrime(j) == 1) {
                sum += j; f++;
            }
            if (sum >= number) break;
            if (isPrime(sum) == 1) {
                Prime = sum; fPrime = f;
            }
            j++;
        }
        if (fPrime > fmax) {
            fmax = fPrime; Ans = Prime;
        }
        i++;
    }

    cout << Ans;
}

bool isPrime(int n)
{
    if (isprime[n] == 1) return true;
    else if (isprime[n] == 0) return false;
    else if (n <= 1) { isprime[n] = 0; return false; }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) { isprime[n] = 0; return false; }
    }
    isprime[n] = 1;
    return true;
}
