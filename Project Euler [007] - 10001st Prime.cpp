/*
PROBLEM:
By listing the first six prime numbers: 2, 3, 5, 7, 11 and 13, we can see that the 6th prime is 13. 
What is the N'th prime number?

Input Format 
First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.

Output Format 
Print the required answer for each test case.

Constraints 
1 <= T <= 10^3
1 <= N <= 10^4

Sample Input
2
3
6

Sample Output
5
13
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, primeCount = 0, maxN = 0;
    bool nums[105000] {0};
    cin >> t;
    int n[t];
    for (int i = 0; i < t; i++){
        cin >> n[i];
        if (n[i] > maxN){
            maxN = n[i];
        }
    }
    int primes[maxN];
    
    nums[0] = 1;
    nums[1] = 1;
    
    for (int i = 2; i*i < 105000; i++){
        if (nums[i] == 0){
            for (int j = i*i; j < 105000; j += i){
                nums[j] = 1;
            }
        }
    }
    
    for (int i = 0; i < 105000; i++){
        if (nums[i] == 0){
            primes[primeCount] = i;
            primeCount++;
            if (primeCount > maxN){
                i = 105000;
            }
        }
    }
    
    for (int i = 0; i < t; i++){
        cout << primes[n[i]-1] << endl;
    }
    return 0;
}
