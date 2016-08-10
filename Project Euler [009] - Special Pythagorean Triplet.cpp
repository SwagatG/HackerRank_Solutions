/*
PROBLEM:
A Pythagorean triplet is a set of three natural numbers, a < b < c , for which, a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2

Given N, Check if there exists any Pythagorean triplet for which a + b + c = N.
Find maximum possible value of  among all such Pythagorean triplets, If there is no such Pythagorean triplet print -1.

Input Format 
The first line contains an integer T i.e. number of test cases. 
The next T lines will contain an integer N.

Output Format 
Print the value corresponding to each test case in separate lines.

Constraints 
1 <= T <= 3000
1 <= N <= 3000 

Sample Input
2
12
4

Sample Output
60
-1
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int a, b, c;
        long currP, maxP = 0;
        cin >> n;
        for (int j = 3; j < n/3; j++){ //a is smallest of the 3, so it will be no larger than n/3.
            a = j;
            b = (a*a - (a-n)*(a-n))/(2*(a-n)); //Formula Derived from substituting c = N - a - b Into a^2 + b^2 = c^2
            c = n - a - b;
            if (a*a + b*b == c*c && c > 0){
                currP = a * b * c;
                if (currP > maxP){
                    maxP = currP;
                }
            }
        }
        if (maxP > 0){
            cout << maxP << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
