/*
PROBLEM:
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n). 
If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55, and 110 therefore d(220) = 284. 
The proper divisors of 284 are 1, 2, 4, 71 and 142 so d(284) = 220.

Evaluate the sum of all the amicable numbers under N.

Input Format 
The first line contains an integer T , i.e., number of test cases. 
Next T lines will contain an integer N.

Output Format 
Print the values corresponding to each test case.

Constraints 
1 <= T <= 1000
1 <= N <= 10^5

Sample Input
1
300

Sample Output
504
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int divSum (int seed){
    int sum = 0;
    for (int i = 1; i*i <= seed; i++){
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
    int n[t], maxN = 0;
    for (int i = 0; i < t; i++){
        cin >> n[i];
        if (n[i] > maxN){
            maxN = n[i];
        }
    }
    bool isAm[maxN] {0};
    int response[maxN];
    for (int i = 0; i < maxN; i++){
        isAm[i] = 0;
        response[i] = 0;
    }
    int currSum;
    for (int i = 1; i < maxN; i++){
        if (isAm[i] == false){
            currSum = divSum(i);
            if (i == divSum(currSum) && i != currSum){
                isAm[i] = true;
                if (isAm[currSum] < maxN){
                    isAm[currSum] = true;
                }
            }
        }
    }
    for (int i = 1; i < maxN; i++){
        response[i] += response[i-1];
        if (isAm[i-1] == 1){
            response[i] += i-1;
        }
    }
    
    for (int i = 0; i < t; i++){
        cout << response[n[i] - 1] << endl;
    }
    return 0; 
}
