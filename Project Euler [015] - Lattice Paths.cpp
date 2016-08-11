/*
PROBLEM:
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
		
		 ________ 
		|   |   |			1) Right, Right, Down, Down			2) Right, Down, Right, Down
	    |___|___|			3) Right, Down, Down, Right			4) Down, Right, Right, Down
		|   |   |			5) Down, Right, Down, Right			6) Down, Down, Right, Right
	    |___|___|

How many such routes are there through a N×M grid? As number of ways can be very large, print it modulo 10^9 + 7 .

Input Format 
The first line contains an integer T , i.e., number of test cases. 
Next T lines will contain integers N and M.

Output Format 
Print the values corresponding to each test case.

Constraints 
1 <= T <= 10^3
1 <= N <= 500
1 <= M <= 500

Sample Input
2
2 2
3 2

Sample Output
6
10
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, m, t;
    cin >> t;
    long long grid[501][501];
   
    for (int i = 0; i < 501; i++){
        grid[i][0] = 1;
        grid[0][i] = 1;
    }
    for (int i = 1; i < 501; i++){
        for (int j = 1; j < 501; j++){
            grid[i][j] = (grid[i-1][j] + grid[i][j-1]) % (1000000007);
        }
    }

    for (int i = 0; i < t; i++){
        cin >> n >> m;
        cout << grid[n][m] << endl;
    }
    return 0;
}
