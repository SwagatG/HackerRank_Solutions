/*
PROBLEM:
A palindromic number reads the same both ways. The smallest 6 digit palindrome made from the product of two 3-digit numbers is 101101 = 143 * 707. 
Find the largest palindrome made from the product of two 3-digit numbers which is less than N.

Input Format 
First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.

Output Format 
Print the required answer for each test case in a new line.

Constraints 
1 <= T <= 100
101101 <= N < 1000000 

Sample Input
2
101110
800000

Sample Output
101101
793397
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int nextPalindrome(int currNum){
    int start = currNum / 1000;
    int nextPal = start * 1000 + (start%10) * 100 + ((start%100)/10) *10 + (start-start%100)/100;
    if (nextPal > currNum){
        start --;
        nextPal = start * 1000 + (start%10) * 100 + ((start%100)/10) *10 + (start-start%100)/100;
    }
    return nextPal;
}

bool isFactor(int testCase){
    int ck;
    for (int i = 10; i < 91; i ++){
        ck = 11 * i; //Palindromes are multiples of 11.
        if (testCase % ck == 0 &&  testCase / ck < 1000 && testCase / ck > 99){
            return true;
        }
    }
    return false;
}

int main() {
    int t, n;
    bool factorCheck;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        n = nextPalindrome(n-1);
        factorCheck = isFactor(n);
        while (factorCheck == false){
            n = nextPalindrome(n-1);
            factorCheck = isFactor(n);
        }
        cout << n << endl;
    }
    return 0;
}
