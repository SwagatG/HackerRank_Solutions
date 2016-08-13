/*
PROBLEM:
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
		1/2 = 0.5				1/3 = 0.(3)				1/4 = 0.25			1/5 = 0.2
		1/6 = 0.1(6)			1/7 = 0.(142857)		1/8 = 0.125			1/9 = 0.(1)
		1/10 = 0.1

Where  means 0.1(6) , 0.16666666... and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of smallest d < N for which 1/d contains the longest recurring cycle in its decimal fraction part.

Input Format 
The first line contains an integer T , i.e., number of test cases. 
Next T lines will contain an integer N.

Output Format 
Print the values corresponding to each test case.

Constraints 
1 <= T <= 1000
4 <= N <= 10000

Sample Input
2
5
10

Sample Output
3
7
*/

/*
RESEARCHED WORK:
https://en.wikipedia.org/wiki/Full_reptend_prime
	- Realized that primes would give the longest cycles.
	- Couldn't find a pattern for Full reptend primes, so just tested all primes.
	
https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
	- Used to quickly find primes
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findCycleLength(int seed){
    int length = 0, dividend = 1;
    vector <bool> rem(seed,false); // if a remainder has previously occured, the cycle restarted.
    while (dividend < seed)
        dividend *= 10;
    dividend %= seed;
    while (!rem[dividend]){
        rem[dividend] = true;//mark the rem as having occured already
        length ++;
        if (dividend == 0){
            return 0;//if there is no remainder, it is not a cycle
        }
        while (dividend < seed)
            dividend *= 10;
        dividend %= seed;
    }
    return length;
}

int main() {
    int t;
    cin >> t;
    int n[t], maxN = 0;
    for (int i = 0; i < t; i++){
        cin >> n[i];
        if (n[i] > maxN){
            maxN = n[i];
        }
    }
    
    bool nums[maxN]{0};
    nums[0] = 1;
    nums[1] = 1;
    for (int i = 2; i*i < maxN; i++){
        if (nums[i] == 0){
            for (int j = i*i; j < maxN; j += i){
                nums[j] = 1;
            }
        }
    }

    int maxCycle = 0, maxSeed = 0, currCycle;
    int result[maxN];
    for (int i = 3; i < maxN; i++){
        if (!nums[i]){
            currCycle = findCycleLength(i);
            if (currCycle > maxCycle){
                maxSeed = i;
                maxCycle = currCycle;
            }
        } 
        result[i] = maxSeed;        
    }
    
    for (int i = 0; i < t; i++){
        cout << result[n[i] - 1] << endl;
    }
    
    return 0;
}

