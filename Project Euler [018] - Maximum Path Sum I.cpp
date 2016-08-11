/*
PROBLEM:
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23. The path is denoted by numbers with stars.

				   *3*
 				 *7*  4
			   2   *4*   6 
 			8    5   *9*   3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle given in input.

Input Format 
First line contains T, the number of testcases. For each testcase: 
First line contains N, the number of rows in the triangle. 
For next N lines, i'th line contains i numbers.

Output Format 
For each testcase, print the required answer in a newline.

Constraints 
1 <= T <= 10
1 <= N <= 15
numbers: element of [0, 100)

Sample input
1
4
3
7 4
2 4 6
8 5 9 3

Sample output
23
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
        cin >> n;
        int tri[n][n], sum[n-1][n-1];
        for (int j = 0; j < n; j++){
            for (int k = 0; k <= j; k++){
                cin >> tri[j][k];
            }
        }

        for (int j = n-2; j >= 0; j--){
            for (int k = j; k >= 0; k--){
                if (tri[j+1][k] > tri[j+1][k+1]){
                    tri[j][k] = tri[j][k] + tri[j+1][k];
                } else{
                    tri[j][k] = tri[j][k] + tri[j+1][k+1];
                }
            }
        }
        
        cout << tri[0][0] << endl;
    }
    return 0;
}

