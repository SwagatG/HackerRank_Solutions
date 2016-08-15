/*
PROBLEM:
Bob has a strange counter. At the first second, t = 1, it displays the number 3. 
At each subsequent second, the number displayed by the counter decrements by .

The counter counts down in cycles. In the second after the counter counts down to 1, 
the number becomes 2x the initial number for that countdown cycle and then continues counting down from the 
new initial number in a new cycle. The diagram below shows the counter values for each time t in the first three cycles:
		time	value			time	value			time		value
		1		3				4		6				10			12
		2		2				5		5				11			11
		3		1				6		4				12			10
								7		3				13			9
								8		2				14			8
								9		1				15			7
														...			...
														21			1

Given a time, t, find and print the value displayed by the counter at time .

Input Format
A single integer denoting the value of t.

Constraints
1 <= t <= 10^12

Subtask
1 <= t <= 10^5 for 60% of the maximum score.

Output Format
Print the value displayed by the strange counter at the given time .

Sample Input
4

Sample Output
6
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long t;
    cin >> t;
    int exp2 = 0;
    long long currVal = t;
    while (currVal - 3 * (pow(2,exp2)) > 0){
        currVal -= 3 * (pow(2,exp2));
        exp2++;
    }
    currVal = 3 * pow(2,exp2) - currVal + 1;
    cout << currVal;
    return 0;
}
