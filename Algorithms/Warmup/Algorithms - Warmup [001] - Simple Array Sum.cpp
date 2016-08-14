/*
PROBLEM:
Given an array of N integers, can you find the sum of its elements?

Input Format
The first line contains an integer, N, denoting the size of the array. 
The second line contains N space-separated integers representing the array's elements.

Output Format
Print the sum of the array's elements as a single integer.

Sample Input
6
1 2 3 4 10 11

Sample Output
31

Explanation
We print the sum of the array's elements, which is: 1 + 2 + 3 + 4 + 10 + 11 = 34.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n, m, sum=0;
    cin >> n;
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> m;
       sum += m;
    }
    cout << sum;
    return 0;
}
