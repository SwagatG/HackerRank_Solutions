/*
PROBLEM:
Find the greatest product of K consecutive digits in the N digit number.

Input Format 
First line contains T that denotes the number of test cases. 
First line of each test case will contain two integers N & K.
Second line of each test case will contain a N digit integer. 

Output Format 
Print the required answer for each test case.

Constraints 
1 <= T <= 100
1 <= K <= 7
K <= N <= 1000 

Sample Input
2
10 5
3675356291
10 5
2709360626

Sample Output
3150
0
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int k, n, t, currP, maxP;
    string num; //Note 0 is 48 in the ASCII table
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n >> k;
        cin >> num;
        maxP = num[0] - 48;
        for (int j = 1; j < k; j++){
            maxP *= num[j] - 48;
        }
        for (int j = k; j < n; j++){
            currP = 1;
            for (int a = 0; a < k; a++){
                currP *= num[j-a] - 48;
            }
            if (currP > maxP){
                maxP = currP;
            }
        }
        cout << maxP << endl;
    }
    return 0;
}
