/*
PROBLEM:
The sum of the squares of the first ten natural numbers is, 1^2 + 2^2 + ... + 10^2 = 385. The square of the sum of the first ten natural numbers is, (1+2+...+10)^2 = 55^2 = 3025 . Hence the absolute difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
Find the absolute difference between the sum of the squares of the first N natural numbers and the square of the sum.

Input Format 
First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.

Output Format 
Print the required answer for each test case.

Constraints 
1 <= T <= 10^4
1 <= N <= 10^4 

Sample Input
2
3
10

Sample Output
22
2640
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;


int main() {
    int n, t;
    long sumOfSq, sqOfSum, temp, sum;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        sumOfSq = 0;
        sum = 0;
        for (int j = 1; j <= n; j++){
            sumOfSq += j * j;
            sum += j;
        }
        sqOfSum = sum * sum;
        temp  = sqOfSum - sumOfSq;
        cout << fixed << setprecision(0) << temp << endl;
    }
    return 0;
}
