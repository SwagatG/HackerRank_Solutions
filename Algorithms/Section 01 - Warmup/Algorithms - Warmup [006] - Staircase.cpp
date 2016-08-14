/*
PROBLEM:
Consider a staircase of size :
   #
  ##
 ###
####
Observe that its base and height are both equal to n, and the image is drawn using # symbols and spaces. 
The last line is not preceded by any spaces.
Write a program that prints a staircase of size n.

Input Format
A single integer, n, denoting the size of the staircase.

Output Format
Print a staircase of size n using # symbols and spaces.
Note: The last line must have 0 spaces in it.

Sample Input
6 

Sample Output
     #
    ##
   ###
  ####
 #####
######
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
    
    for (int i = 1; i <=n; i ++){
        for (int j = n-i; j > 0; j--){
            cout << " ";
        }
        for (int k = 0; k < i; k ++){
            cout << "#";
        }
        cout << "\n";
    }
    return 0;
}
