/*
PROBLEM:
You are given N sticks, where the length of each stick is a positive integer. 
A cut operation is performed on the sticks such that all of them are reduced by the length of the smallest stick.

Suppose we have six sticks of the following lengths:
	5 4 4 2 2 8
Then, in one cut operation we make a cut of length 2 from each of the six sticks.
 
For the next cut operation four sticks are left (of non-zero length), whose lengths are the following: 
	3 2 2 6
The above step is repeated until no sticks are left.

Given the length of N sticks, print the number of sticks that are left before each subsequent cut operations.
Note: For each cut operation, you have to recalcuate the length of smallest sticks (excluding zero-length sticks).

Input Format 
The first line contains a single integer N. 
The next line contains N integers: a0, a1,...aN-1 separated by space, where ai represents the length of the ith stick.

Output Format 
For each operation, print the number of sticks that are cut, on separate lines.

Constraints
1 <= N <= 1000
1 <= ai <= 1000

Sample Input
6
5 4 4 2 2 8

Sample Output
6
4
2
1
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    cout << n << endl;
    int temp, count = n, min = 1000;
    while (min < 1001){
        min = 1001;
        for (int i = 0; i < n; i ++){
            if (arr[i] != 0 && arr[i] < min){
                min = arr[i];
            }
        }
        for (int i = 0; i < n; i ++){
            if (arr[i] > 0){
                arr[i] -= min;
                if (arr[i] == 0){
                    count -=1;
                    temp = arr[count];
                    arr[count] =  arr[i];
                    arr[i] = temp;
                    i -= 1;
                }
            } else {
                i = n;
            } 
        }
        if (count > 0){
            cout << count << endl;   
        } else {
            min = 1001;
        }
    }
    return 0;
}
