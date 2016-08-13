/*
PROBLEM:
The Fibonacci sequence is defined by the recurrence relation:
		Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 2
		
Hence the first 12 terms will be:
	F1 = 1		F2 = 1		F3 = 2		F4 = 3		F5 = 5		F6 = 8
	F7 = 13		F8 = 21		F9 = 34		F10 = 55	F11 = 89	F12 = 144
	
The 12th term, F12, is the first term to contain three digits. 
What is the first term in the Fibonacci sequence to contain N digits?

Input Format 
The first line contains an integer T , i.e., number of test cases. 
Next T lines will contain an integer N.

Output Format 
Print the values corresponding to each test case.

Constraints 
1 <= T <= 5000
2 <= N <= 5000

Sample Input
2
3
4

Sample Output
12
17
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const double phi = (1 + sqrt(5))/2;

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
    
    long result[maxN+1];
    int digCount = 1;
    for (int i = 2; digCount <= maxN; i++){
    	//Calculate digits of Fi using Formula from - http://www.had2know.com/academics/number-digits-length-fibonacci-number.html
        if (floor(i * log10(phi) - log10(5)/2 + 1) > digCount){
            digCount ++;
            result[digCount] = i;
        }
    }

    for (int i = 0; i < t; i++){
        cout << result[n[i]] << endl;
    }
    
    return 0;
}

