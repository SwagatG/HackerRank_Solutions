/*
PROBLEM:
Lilah has a string, s, of lowercase English letters that she repeated infinitely many times.

Given an integer, n, find and print the number of letter a's in the first  letters of Lilah's infinite string.

Input Format

The first line contains a single string, s. 
The second line contains an integer, n.

Constraints
1 <= |s| <= 100
1 <= n <= 10^12
For 25% of the test cases, n <= 10^6.

Output Format
Print a single integer denoting the number of letter a's in the first n letters 
of the infinite string created by repeating s infinitely many times.

Sample Input
aba
10

Sample Output
7
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;
    long n;
    cin >> n;
    
    int aCount = 0;
    long totalA = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'a'){
            aCount ++;
        }
    }
    
    for (int i = 0; i < (n % s.length()); i++){
        if (s[i] == 'a'){
            totalA ++;
        }
    }
    
    totalA += aCount * (n / s.length());
    
    cout << totalA;
    
    return 0;
}
