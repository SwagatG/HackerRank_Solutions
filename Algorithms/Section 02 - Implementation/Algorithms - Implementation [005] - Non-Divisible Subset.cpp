/*
PROBLEM:
Given a set, S, of n distinct integers, print the size of a maximal subset, S', 
of  where the sum of any 2 numbers in S' are not evenly divisible by k.

Input Format
The first line contains 2 space-separated integers, n and k, respectively. 
The second line contains n space-separated integers (we'll refer to the ith value as ai) describing the unique values of the set.

Constraints
1 <= n <= 10^5
1 <= k <= 100
1 <= ai <= 10^9
All of the given numbers are distinct.

Output Format
Print the size of the largest possible subset (S').

Sample Input
4 3
1 7 2 4

Sample Output
3
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int rem[k] {0};
    long currNum, maxL = 0;
    for (int i = 0; i < n; i++){
        cin >> currNum;
        rem[currNum % k] ++;
    }
    for (int i = 1; i < (k/2 + k%2); i++){
        maxL += max(rem[i], rem[k-i]);
    }
    if (rem[0] > 0){
        maxL ++;
    }
    if (k % 2 == 0 && rem[k/2] > 0){
        maxL ++;
    }
    cout << maxL << endl;
    return 0;
}
