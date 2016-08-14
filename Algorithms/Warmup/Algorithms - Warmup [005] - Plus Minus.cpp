/*
PROBLEM:
Given an array of integers, calculate which fraction of its elements are positive, 
which fraction of its elements are negative, and which fraction of its elements are zeroes, respectively. 
Print the decimal value of each fraction on a new line.

Note: This challenge introduces precision problems. 
The test cases are scaled to six decimal places, though answers with absolute error of up to 10^-4 are acceptable.

Input Format
The first line contains an integer, N, denoting the size of the array. 
The second line contains N space-separated integers describing an array of numbers.

Output Format
You must print the following 3 lines:
A decimal representing of the fraction of positive numbers in the array.
A decimal representing of the fraction of negative numbers in the array.
A decimal representing of the fraction of zeroes in the array.

Sample Input
6
-4 3 -9 0 4 1
         
Sample Output
0.500000
0.333333
0.166667
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, temp;
    float neg = 0, pos = 0, neu = 0;
    float fneg, fpos, fneu;
    cin >> n;
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> temp;
       if (temp > 0){
           pos += 1;
       } else if (temp < 0){
           neg += 1;
       } else{
           neu += 1;
       }
    }
    fneg = neg / n;
    fpos = pos / n;
    fneu = neu / n;
    
    cout << fpos << endl << fneg << endl << fneu;
    return 0;
}
