/*
PROBLEM:
Given n sticks of lengths l0, l1, ... , ln-1, use 3 of the sticks to construct a non-degenerate 
triangle with the maximum possible perimeter. Then print the lengths of its sides as 3 
space-separated integers in non-decreasing order.

If there are several valid triangles having the maximum perimeter:

1) Choose the one with the longest maximum side (i.e., the largest value for the longest side of any 
    valid triangle having the maximum perimeter).
2) If more than one such triangle meets the first criterion, choose the one with the longest minimum 
    side (i.e., the largest value for the shortest side of any valid triangle having the maximum perimeter).
3) If more than one such triangle meets the second criterion, print any one of the qualifying triangles.

If no non-degenerate triangle exists, print -1.

Input Format
The first line contains single integer, n, denoting the number of sticks. 
The second line contains n space-separated integers, l0, l1, ..., ln-1, describing the respective 
stick lengths.

Constraints
3 <= n <= 50
1 <= li <= 10^9

Output Format
Print 3 non-decreasing space-separated integers, a, b, and c (where a <= b <= c) describing the 
respective lengths of a triangle meeting the criteria in the above Problem Statement.

If no non-degenerate triangle can be constructed, print -1.

Sample Input
5
1 1 1 3 3

Sample Output
1 3 3
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int l[n], temp;
    
    for (int i = 0; i < n; i++){
        cin >> l[i];
    }
    
    for (int i = 0; i < n-1; i++){
        for(int k = 0; k < n-1; k++){
            if (l[k] < l[k+1]){
                temp = l[k+1];
                l[k+1] = l[k];
                l[k] = temp;
            }
        }
    }
    
    for (int i = 0; i < n - 2; i ++){
        if (l[i] - l[i+1] - l[i+2] < 0){
            cout << l[i+2] << " " << l[i+1] << " " << l[i];
            break;
        }
        if (i == n-3){
            cout << "-1";
        }
    }
    
    return 0;
}

