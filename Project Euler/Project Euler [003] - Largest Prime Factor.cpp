/*
PROBLEM:
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of a given number N?

Input Format 
First line contains T, the number of test cases. This is followed by T lines each containing an integer N.

Output Format 
For each test case, display the largest prime factor of N.

Constraints 
1 <= T <= 10
10 <= N <= 10^12 

Sample Input
2
10
17

Sample Output
5
17
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    long long n, maxPrime, n2;
    for (int i = 0; i < t; i ++){
        cin >> n;
        
        n2 = n;
        while (n2 % 2 == 0){ //Repeatedly divide by 2 if possible
                maxPrime = 2;
                n2 /= 2;
        }
        for (long long j = 3; j*j <= n2; j+=2){ //skipping every even number, divide if possible by greater numbers (up until the squareroot of n2)
            while (n2 % j == 0){
                maxPrime = j;
                n2 /= j;
            }
        }
        
        if (n2 != 1){ //if the above for loop ended without dividing the term to 1, the term must be the largest factor
            maxPrime = n2;
        }

        cout << maxPrime << endl;
    }
    return 0;
}
