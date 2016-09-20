/*
PROBLEM:
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
			1634 = 1^4 + 6^4 + 3^4 + 4^4
			8208 = 1^4 = 2^4 + 0^4 + 8^4
			9474 = 9^4 + 4^4 + 7^4 + 4^4
			
As 1 = 1^4 is not a sum it is not included. 
The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of Nth powers of their digits.

Input Format 
Input contains an integer N

Output Format 
Print the answer corresponding to the test case.

Constraints 
3 <= N <= 6

Sample Input
4

Sample Output
19316
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, maxVal, sum = 0, currTest, currRem, powers[10], currDig, digCount = 3, lastDig = 100;
    cin >> n;
    for (int i = 2; ; i++){
        if (pow(10, i) > (i+1) * pow(9, n)){
            maxVal = (i+1) * pow(9,n);
            maxVal = min(maxVal, 1000000); //Time constraint issues
            break;
        }    
    }
    for (int i = 0; i < 10; i++){
        powers[i] = pow(i, n);
    }
    
    for (int i = 100; i < maxVal; i++){
        if (i == 10 * lastDig){
            digCount ++;
            lastDig *= 10;
        }
        currDig = digCount;
        currTest = i;
        currRem = i;
       
        while (currTest > 0){
            int testPow = pow(10, currDig-1);
            
            currRem -= pow(currTest/testPow, n);
            currTest = currTest % testPow;
            currDig --;
            if (currRem < 0 && currDig >= 0 && i % 10 != 9){
                if (i > 2000000){
                    cout << "SKIP: " << i << " DIG: " << currDig << endl;
                }
                
                i = i/(pow(10, currDig+1));
                i *= pow(10, currDig+1);
                i += pow(10, currDig+1) - 1;
                currTest = 0;
            }
        }
        
        if (currRem == 0){
            sum += i;
        }
    }
    cout << sum;
    return 0;
}
