/*
PROBLEM:
2^9 = 512 and the sum of its digits is 5 + 1 + 2 = 8.

What is the sum of the digits of the number 2^N ?

Input Format 
The first line contains an integer T , i.e., number of test cases. 
Next T lines will contain an integer N.

Output Format 
Print the values corresponding to each test case.

Constraints 
1 <= T <= 100
1 <= N <= 10^4

Sample Input
3
3
4
7

Sample Output
8
7
11
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
    int n[t], maxN = 0;
    for (int i = 0; i < t; i++){
        cin >> n[i];
        if (n[i] > maxN){
            maxN = n[i];
        }
    }
    int digSum[maxN + 1];
    digSum[0] = 1;
    
    int exponent[3012] {0}; // 2 ^ 10000 has 3010 digits(1 + log10(2^10000) = 1 + 10000 * log10(2))
    exponent[0] = 1;
    int carry[2] = {0,0};
    
    for (int i = 1; i < maxN + 1; i++){
        carry[0] = 0;
        carry[1] = 0;
        for (int j = 0; j < 0.3011 * i + 1 && j < 3011; j++){
            exponent[j] *= 2;
            carry[0] += exponent[j]/10;
            exponent[j] = exponent[j] % 10 + carry[1];
            carry[1] = carry[0];
            carry[0] = 0;
        }
        digSum[i] = 0;
        for (int j = 0; j < 0.3011 * i + 1 && j < 3011; j++){
            digSum[i] += exponent[j];
        }
    }
    
    for (int i = 0 ; i < t; i++){
        cout << digSum[n[i]] << endl;
    }
    
    return 0;
}
