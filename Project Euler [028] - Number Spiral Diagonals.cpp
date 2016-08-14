/*
PROBLEM:
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
							*21*	22		23		24		*25*
							
							 20	    *7*		 8	    *9*		10
							 
							 19		 6		*1*		 2		11
							 
							 15		*5*		 4		*3*		12
							 
							*17*	16		15		14	   *13*

It can be verified that the sum of the numbers on the diagonals is 101. 
What is the sum of the numbers on the diagonals in a N*N, (N is odd) spiral formed in the same way? 
As the sum will be huge you have to print the result mod (10^9 + 7)

Input Format 
The first line contains an integer T , i.e., number of test cases. 
Next T lines will contain an integer N.

Output Format 
Print the values corresponding to each test case.

Constraints 
1 <= T <= 10^5
1 <= N < 10^18, N is odd

Sample Input
2
3
5

Sample Output
25
101
*/

/*
RESEARCH:
https://en.wikipedia.org/wiki/1_%2B_2_%2B_3_%2B_4_%2B_%E2%8B%AF
    - Formula to sum numbers up to n
http://www.trans4mind.com/personal_development/mathematics/series/sumNaturalSquares.htm
    - Formula to sum squares of natural numbers up to the square of n
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const long divisor = 1000000007;

int main() {
    long n, t;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        n /= 2; // find distance from centre to calculate
        n %= divisor;
        //cout << "N1: " << n << endl;
        //every number on the top-right diagonal is (2n+1)^2 = 4n^2 + 4n + 1;
        //going counter clockwise from top-right, every diagonal is 2n less (n to centre, n to other end)
        //TR: 4n^2 + 4n + 1     TL: 4n^2 + 2n + 1       BL: 4n^2 + 1       BR: 4n^2 - 2n + 1
        //Thus the sum for the nth ring set of corners is 16n^2 + 4n + 4;
        //We must also sum n rings of this number;
        //N sets of 4 = 4 * n;
        //N sets of 4n = 4 * (n * (n + 1) / 2) = 2 * (n * (n + 1))
        //N sets of 16n^2 = 16 * (n * (n + 1) * (2n + 1) / 6) = 8 * n * (n + 1) * (2n + 1) / 3
        long result1, result2, result3, result, rem;
        rem = n % 3;
        if (rem == 0){
            result3 = (n * 8 / 3) % divisor;
            result3 %= divisor;
            result3 *= ((2*n + 1) % divisor);
            result3 %= divisor;
            result3 *= ((n+1) % divisor);
        } else if (rem == 1){
            result3 = ((2 * n + 1)/3) % divisor;
            result3 %= divisor;
            result3 *= (8 * n) % divisor;
            result3 %= divisor;
            result3 *= ((n + 1) % divisor);
        } else{
            result3 = ((n + 1) / 3) % divisor;
            result3 %= divisor;
            result3 *= (8 * n) % divisor;
            result3 %= divisor;
            result3 *= ((2*n + 1) % divisor);
        }
        result3 %= divisor;
        result1 = ((4 * n) % divisor);
        result1 %= divisor;
        result2 = (2 * n * (n + 1)) % divisor;
        result2 %= divisor;
        
        result = result1 + result2 + result3;
        result %= divisor;
        result ++; //add 1 for the 0th ring 
        result %= divisor;
        cout << result << endl;
    }
    return 0;
}
