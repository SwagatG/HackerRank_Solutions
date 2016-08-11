/*
PROBLEM:
The following iterative sequence is defined for the set of positive integers:
				n --> n/2				n is even
				n --> 3n + 1			n is odd
				
Using the rule above and starting with 13, we generate the following sequence:
	13 --> 40 --> 20  --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1 

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proven yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, <= N produces the longest chain? If many possible such numbers are there print the maximum one.

Note: Once the chain starts the terms are allowed to go above N.

Input Format 
The first line contains an integer T , i.e., number of test cases. 
Next T lines will contain an integer N.

Output Format 
Print the values corresponding to each test case.

Constraints 
1 <= T <= 10^4
1 <= T <= 5 * 10^6

Sample Input
 3
10 
15
20

Sample Output
9
9
19
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Global declaration allows larger array sizes, prevents segmentation fault
long maxCol[5000001];
long col[5000001];

int main() {
    int t;
    cin >> t;
    int n[t], maxN = 0;
    
    for (int i = 0; i < t; i++){
        cin >> n[i];
        if (n[i] > maxN){
            maxN = n[i];
        }
    }
    for (long i = 0; i <= maxN; i++){
        maxCol[i] = 0;
        col[i] = 0;
    }
    
    long long colCount, currTest;
    for (long i = maxN; i > 0; i--){
        currTest = i;
        colCount = 1;
        while (currTest != 1){
            if (currTest % 2 == 0){
                currTest /=2;
            } else {
                currTest = currTest * 3 + 1;
            }
            colCount ++;
        }
        col[i] = colCount;
    }
    
    for (long i = maxN; i > 0 ; i--){
        maxCol[i] = i;
        for (long j = i + 1; j <= maxN; j++){
            if (col[maxCol[j]] < col[maxCol[i]]){
                maxCol[j] = i;
            } else {
                break;
            }
        }
    }
    
    for (long i = 0; i < t; i++){
        cout << maxCol[n[i]] << endl;
    }
    return 0;
}
