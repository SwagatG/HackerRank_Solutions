/*
PROBLEM:
There are two kangaroos on an x-axis ready to jump in the positive direction (i.e, toward positive infinity). 
The first kangaroo starts at location x1 and moves at a rate of v1 meters per jump. 
The second kangaroo starts at location x2 and moves at a rate of v2 meters per jump. 
Given the starting locations and movement rates for each kangaroo, can you determine 
if they'll ever land at the same location at the same time?

Input Format
A single line of four space-separated integers denoting the respective values of x1, v1, x2, and v2.

Constraints
0 <= x1 < x2 <= 10000
1 <= v1, v2 <= 10000

Output Format
Print YES if they can land on the same location at the same time; otherwise, print NO.
Note: The two kangaroos must land at the same location after making the same number of jumps.

Sample Input
0 3 4 2

Sample Output
YES
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;
    int minX, minV;
    minX = min(x1, x2);
    minV = min(v1, v2);
    x1 -= minX;
    x2 -= minX;
    v1 -= minV;
    v2 -= minV;
    if (v1 == 0){
        cout << "NO\n";
    } else {
        if (x2 % v1 == 0) {
            cout << "YES\n";   
        } else{
            cout << "NO\n";
        }
    }
    return 0;
}
