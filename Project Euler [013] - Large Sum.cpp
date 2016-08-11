/*
PROBLEM:
Work out the first ten digits of the sum of N 50-digit numbers.

Input Format 
First line contains N, next N lines contain a 50 digit number each.

Output Format 
Print only first 10 digit of the final sum

Constraints 
1 <= N <= 10^3

Sample Input
5
37107287533902102798797998220837590246510135740250
46376937677490009712648124896970078050417018260538
74324986199524741059474233309513058123726617309629
91942213363574161572522430563301811072406154908250
23067588207539346171171980310421047513778063246676

Sample Output
2728190129
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
    string num[n];
    int sum[55];
    int currSum=0, carry=0;
    for (int i = 0; i < n; i++){
        if (i < n){
            cin >> num[i];
        }
    }
    for (int i = 0; i < 55; i++){
        sum[i] = 0;
    }

    for (int i = 49; i >= 0; i--){
        currSum = carry;
        for (int j = 0; j < n; j++){ 
            currSum += num[j][i] - 48; //'0' is 48 in ASCII
        }
        carry = currSum / 10;
        sum[49-i] = currSum % 10;
    }
    int excess = 0;
    while (carry > 0){
        sum[50+excess] = carry % 10;
        carry /= 10;
        excess ++;
    }
    
    for (int i = 54; i >0; i--){
        if (sum[i] != 0){
            for (int j = 0; j < 10; j++){
                cout << sum[i-j];
            }
            break;
        }
    }
    return 0;
}
