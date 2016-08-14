/*
PROBLEM:
Given a square matrix of size N x N, calculate the absolute difference between the sums of its diagonals.

Input Format
The first line contains a single integer, N. The next N lines denote the matrix's rows, with each line containing N space-separated integers describing the columns.

Output Format
Print the absolute difference between the two sums of the matrix's diagonals as a single integer.

Sample Input
3
11 2 4
4 5 6
10 8 -12

Sample Output
15
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, d1=0, d2=0, result;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
       }
    }
    for (int i = 0; i < n; i++){
        d1 += a[i][i];
        d2 += a[n-1-i][i];
    }
    result = abs(d1-d2);
    cout << result;
    return 0;
}
