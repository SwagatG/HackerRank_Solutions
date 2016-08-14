/*
PROBLEM:
John Watson performs an operation called a right circular rotation on an array of integers. 
After performing one right circular rotation operation, the array is transformed from  [a0, a2, ... an-1] to
[an-1, a0, ... an-2].

Watson performs this operation k times. 
To test Sherlock's ability to identify the current element at a particular position in the rotated array, 
Watson asks q queries, where each query consists of a single integer, m, 
for which you must print the element at index m in the rotated array (i.e., the value of am).

Input Format
The first line contains 3 space-separated integers, n, k, and q, respectively. 
The second line contains n space-separated integers, where each integer i describes array element ai (where 0 <= i <= n). 
Each of the q subsequent lines contains a single integer denoting m.

Constraints
1 <= n <= 10^5
1 <= ai <= 10^5
1 <= k <= 10^5
1 <= q <= 500
0 <= m <= N - 1

Output Format
For each query, print the value of the element at index m of the rotated array on a new line.

Sample Input
3 2 3
1 2 3
0
1
2

Sample Output
2
3
1
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k, q, test;
    cin >> n >> k >> q;
    int array[n], newArray[n];
    k %= n;
    for (int i = 0; i < n; i++){
        cin >> array[(i+k)%n];
    }
    for (int i = 0; i < q; i++){
        cin >> test;
        cout << array[test] << endl;
    }
    return 0;
}
