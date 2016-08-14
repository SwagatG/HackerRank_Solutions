/*
PROBLEM:
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
Given N, print YES if it can be expressed as sum of two abundant numbers, else print NO.

Input Format 
The first line contains an integer T , i.e., number of test cases. 
Next T lines will contain an integer N.

Output Format 
Print the values corresponding to each test case.

Constraints 
1 <= T <= 100
1 <= N <= 10^5

Sample Input
2
24
49

Sample Output
YES
NO
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long divSum (long seed){
    long sum = 0;
    for (long i = 1; i*i <= seed; i++){
        if (seed % i == 0){
            sum += i + seed/i;
            if (i*i == seed){
                sum -= i;
            } 
        }
    }
    sum -= seed;
    return sum;
}

int main() {
    int t;
    cin >> t;
    long n[t], maxN;
    for (int i = 0; i < t; i++){
        cin >> n[i];
        if (n[i] > maxN){
            maxN = n[i];
        }
    }
    vector <long> abList;
    bool isAb[maxN+1];
    isAb[0] = 0;
    for (int i = 1; i <= maxN; i++){
        if (divSum(i) > i){
            abList.push_back(i);
            isAb[i] = true;
        } else {
            isAb[i] = false;
        }
    }
    bool isAbSum;
    for (int i = 0; i < t; i++){
        isAbSum = false;
        for (int j = 0; abList[j] <= n[i]/2; j++){
            if (isAb[n[i] - abList[j]]){
                isAbSum = true;
                break;
            }
        }
        if (isAbSum){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

