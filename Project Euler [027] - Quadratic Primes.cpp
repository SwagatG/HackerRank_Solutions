/*
PROBLEM:
Euler published the remarkable quadratic formula: n^2 + n + 41
It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. 
However, when n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41^2 + 41 + 41 is clearly divisible by 41.

Using computers, the incredible formula n^2 - 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 80.
The product of the coefficients, -79 and 1601, is -126479.

Considering quadratics of the form: 
	n^2 + an + b, where |a| <= N and |b| <= N
where |n| is the modulus/absolute value of n.
e.g. |11| = 11 and |-4| = 4

Find the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.

Note For this challenge you can assume solution to be unique.

Input Format
The first line contains an integer N.

Output Format
Print the value of a and b separated by space.

Constraints 
42 <= N <= 2000

Sample Input
42

Sample Output
-1 41

Explanation
for a = -1 and b = 41, you get 42 primes.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    //Initialize Primes
    bool primes[105000];
    
    primes[0] = 1;
    primes[1] = 1;
    for (int i = 2; i*i < 105000; i++){
        if (primes[i] == 0){
            for (int j = i*i; j < 105000; j += i){
                primes[j] = 1;
            }
        }
    }
    vector<long> primeList;
    for (int i = 0; i < 105000; i++){
        if (primes[i] == 0){
            primeList.push_back(i);
        }
    }
    
    int a, b, maxPrime = 0, currPrime;
    long eqn;
    for (int i = -n; i <= n; i++){
        for (int j = 0; primeList[j] <= n; j++){
            currPrime = 0;
            eqn = primeList[j];
            while (primes[eqn] == 0){
                currPrime ++;
                eqn = (currPrime) * (currPrime) + i * (currPrime) + primeList[j];
                if (eqn < 0){
                    break;
                }
            }
            if (currPrime > maxPrime){
                maxPrime = currPrime;
                a = i;
                b = primeList[j];
            }
        }
    }
    cout << a << " " << b << endl;
    return 0;
}

