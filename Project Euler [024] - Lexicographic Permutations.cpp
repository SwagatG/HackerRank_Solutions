/*
PROBLEM:
A permutation is an ordered arrangement of objects. For example, dabc is one possible permutation of the word abcd. If all of the permutations are listed alphabetically, we call it lexicographic order. The lexicographic permutations of abc are:
		abc		acb		bac		bca		cab		cba
What is the Nth lexicographic permutation of the word abcdefghijklm?

Input Format 
The first line contains an integer T , i.e., number of test cases. 
Next T lines will contain an integer N.

Output Format 
Print the values corresponding to each test case.

Constraints 
1 <= T <= 1000
1 <= N <= 13!

Sample Input
2
1
2

Sample Output
abcdefghijklm
abcdefghijkml
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    long n;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        n--;
        int initial[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
        int permute[13], counter = 1;
        vector <int> factoradic;
        //convert n to factoradic (https://en.wikipedia.org/wiki/Factorial_number_system)
        while (n != 0){
            factoradic.push_back(n % counter);
            n /= counter;
            counter ++;
        }
        for (int j = factoradic.size()-1; j < 13; j++){
            factoradic.push_back(0);
        }
        for (int j = 0; j < 13; j++){
            int shift = factoradic[12 - j];
            int remShift = shift;
            for (int k = 0; k < 13; k++){
                if (initial[k] != 0){
                    remShift --;
                    if (remShift == -1) {
                        permute[j] = initial[k];
                        initial[k] = 0;
                    }
                }
            }
        }
        char output;
        for (int j = 0; j < 13; j++){
            output = permute[j] + 96; // 'a' is 97 in ASCII
            cout << output;
        }
        cout << endl;
    }
    return 0;
}

