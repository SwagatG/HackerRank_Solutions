/*
PROBLEM:
n! means n * (n-1) * ... * 3 * 2 * 1
For example, 10! = 10 * 9 * 8 * ... * 3 * 2 * 1 = 362880, 
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 = 27.

Find the sum of the digits in the number N!

Input Format 
The first line contains an integer T , i.e., number of test cases. 
Next T lines will contain an integer N.

Output Format 
Print the values corresponding to each test case.

Constraints 
1 <= T <= 100
0 <= N <= 1000

Sample Input
2
3
6

Sample Output
6
9
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
    int digits[maxN*3] {0}; // Each number will at most add three digits (as in the case of 1000)
    for (int i = 0; i < maxN * 3; i++){
        digits[i] = 0;
    }
    digits[0] = 1;
    int digSum[maxN + 1];
    digSum[0] = 1;
    int carry[2] = {0,0};
    
    for (int i = 1; i < maxN + 1; i++){
        carry[0] = 0;
        carry[1] = 0;
        for (int j = 0; j < 3 * i && j < 3011; j++){
            digits[j] *= i;
            digits[j] += carry[1];
            carry[0] += digits[j]/10;
            digits[j] = digits[j] % 10;
            carry[1] = carry[0];
            carry[0] = 0;
        }
        digSum[i] = 0;
        for (int j = 0; j < 3 * i && j < 3000; j++){
            digSum[i] += digits[j];
        }
    }
    
    for (int i = 0; i < t; i++){
        cout << digSum[n[i]] << endl;
    }
    return 0;
}
