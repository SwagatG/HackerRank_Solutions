/*
PROBLEM:
if and else are two of the most heavily used conditionals in C/C++. 
They are used to execute zero or one statement among many statements.

They can be used in the following three ways.
	1) if: It is used to execute a statement, given the condition is true.
		if(condition) {
		    ...
		}
	
	2) if - else: It is used to execute exactly one of the two statements.
		if(first condition) {
		    ...
		}
		else {
		    ...
		}
	2) if - else if - else: It is used to execute one of the multiple statements.
		if(first condition) {
		    ...
		}
		else if(second condition) {
		    ...
		}
		.
		.
		.
		else if((n-1)'th condition) {
		
		}
		else {
		    ...
		}

You are given a positive integer, N,:
If 1 <= N <= 9, then print the English representation of it. That is "one" for 1, "two" for 2, and so on.
Otherwise print "Greater than 9" (without quotes).

Input Format
Input will contain only one integer, N.

Constraints
1 <= N <= 10^9

Output Format
Print the output as described above.

Sample Input
5

Sample Output
five

Sample Input #01
8

Sample Output #01
eight

Sample Input #02
44

Sample Output #02
Greater than 9
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i;
    cin >> i;
    switch (i){
        case 1:
            cout << "one";
            break;
        case 2:
            cout << "two";
            break;
        case 3:
            cout << "three";
            break;
        case 4:
            cout << "four";
            break;
        case 5:
            cout << "five";
            break;
        case 6:
            cout << "six";
            break;
        case 7:
            cout << "seven";
            break;
        case 8:
            cout << "eight";
            break;
        case 9:
            cout << "nine";
            break;
        default:
            cout << "Greater than 9";
    }
   return 0;
}
