/*
PROBLEM:
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder. 
What is the smallest positive number that is evenly divisible(divisible with no remainder) by all of the numbers from 1 to N?

Input Format 
First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.

Output Format 
Print the required answer for each test case.

Constraints 
1 <= T <= 10
1 <= N <= 40

Sample Input
2
3
10

Sample Output
6
2520
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, n, currPrime, result;
    vector<int> primes;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        primes.push_back(1);
        for (int i = 2; i <= n; i++){
            currPrime = i;
            for (int j = 0; j < primes.size(); j++){
                if (currPrime % primes[j] == 0){
                    currPrime /= primes[j];
                }
            }
            if (currPrime > 1){
                primes.push_back(currPrime);
            }
        }
        result = 1;
        for (int i = primes.size()-1; i >= 0; i--){
            result *= primes[i];
            primes.pop_back();
        }
        cout << result << endl;
    }
    return 0;
}
