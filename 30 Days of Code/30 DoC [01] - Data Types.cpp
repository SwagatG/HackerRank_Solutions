/*
PROBLEM:
Task 
Complete the code in the editor below. The variables i, d, and s are already declared and initialized for you. 
You must declare 3 variables: one of type int, one of type double, and one of type String. 
Then you must read  lines of input from stdin and initialize your  variables. 
Finally, you must use the + operator to perform the following operations:

Print the sum of i plus your int variable on a new line.
Print the sum of d plus your double variable to a scale of one decimal place on a new line.
Concatenate s with the string you read as input and print the result on a new line.
	
Input Format
The first line contains an integer, i. 
The second line contains a double, d. 
The third line contains a string, s.

Output Format
Print the sum of both integers on the first line, the sum of both doubles (scaled to  decimal place) on the second line, and then the two concatenated strings on the third line.

Sample Input
12
4.0
is the best place to learn and practice coding!

Sample Output
16
8.0
HackerRank is the best place to learn and practice coding!
*/
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";
    int i2;
    double d2;
    string s2;
    cin >> i2;
    cin >> d2;
    cin.ignore(100, '\n');
    getline(cin, s2);
    cout << i + i2 << endl << fixed << setprecision(1) << d + d2 << endl << s << s2;
    return 0;
}
