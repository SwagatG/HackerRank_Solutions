/*
PROBLEM:
You are given an array of integers of size N. 
You need to print the sum of the elements in the array, keeping in mind that some of those integers may be quite large.

Input Format
The first line of the input consists of an integer N. The next line contains N space-separated integers contained in the array.

Output Format
Print a single value equal to the sum of the elements in the array.

Constraints 
1 <= N <= 10
0 <= A[i] < = 10^10

Sample Input
5
1000000001 1000000002 1000000003 1000000004 1000000005

Output
5000000015
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    long long sum=0;
    cin >> n;
    for(int i = 0;i < n;i++){
       cin >> m;
       sum += m;
    }
    cout << sum;
    return 0;
}
