/*
PROBLEM: 
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below N.

Input Format
First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.

Constraints
1 <= T <= 10^5
1 <= N <= 10^9 

Output Format
For each test case, print an integer that denotes the sum of all the multiples of 3 or 5 below N.

Sample Input
2
10
100

Sample Output
23
2318
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long getSum (long long num){ //Gauss Style of Addition
    long long sum;
    if (num%2 == 0){
        sum = (num+1) * num/2;
    } else {
        sum = (num) * (num+1)/2;
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        long long n, threeCount, fiveCount, fifteenCount, result;
        cin >> n;
        n--; //N is not included in the sum, so the program will only need to deal with n-1 or lesser values;
        
		threeCount = (n - n % 3) / 3; //Find the largest number divisible by 3, and divide by 3
        fiveCount = (n - n % 5) / 5; //Find the largest number divisible by 5, and divide by 5
        fifteenCount = (n - n % 15) / 15; //Find the largest number divisible by 15, and divide by 15
        
        result = getSum(fiveCount) * 5 + getSum(threeCount) * 3 - getSum(fifteenCount) * 15;
        cout << result << endl;
    }
    return 0;
}
