/*
PROBLEM:
A Discrete Mathematics professor has a class of N students. 
Frustrated with their lack of discipline, he decides to cancel class if fewer than K students are present when class starts.

Given the arrival time of each student, determine if the class is canceled.

Input Format
The first line of input contains T, the number of test cases.
Each test case consists of two lines. 
The first line has two space-separated integers, N (students in the class) and K (the cancelation threshold). 
The second line contains N space-separated integers (a1, a1, ..., aN) describing the arrival times for each student.
Note: Non-positive arrival times indicate the student arrived early or on time; 
positive arrival times indicate the student arrived ai minutes late.

Constraints
1 <= T <= 10
1 <= N <= 1000
1 <= K <= N
-100 <= ai <= 100, where i E [1,N]

Output Format
For each test case, print the word YES if the class is canceled or NO if it is not.
Note 
If a student arrives exactly on time (ai = 0), the student is considered to have entered before the class started.

Sample Input
2
4 3
-1 -3 4 2
4 2
0 -1 2 1

Sample Output
YES
NO
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
    
int main(){
    int t;
    cin >> t;
    bool results[t]; //0-fail OR 1-pass
    for(int a0 = 0; a0 < t; a0++){
        int n, k, f, temp;
        cin >> n >> k;
        f = n;
        for(int a_i = 0;a_i < n;a_i++){
            cin >> temp;
            if (temp > 0){
                f--;
            }
        }
        if (f < k){
            results[a0] = 0;
        } else {
            results[a0] = 1;
        }
    }
    for (int i = 0; i < t; i++){
        if (results[i] == 0){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}


