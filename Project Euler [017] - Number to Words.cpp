/*
PROBLEM:
The numbers 1 to 5 written out in words are One, Two, Three, Four, Five

First character of each word will be capital letter for example: 
104382426112 is One Hundred Four Billion Three Hundred Eighty Two Million Four Hundred Twenty Six Thousand One Hundred Twelve

Given a number, you have to write it in words.

Input Format 
The first line contains an integer T , i.e., number of test cases. 
Next T lines will contain an integer N.

Output Format 
Print the values corresponding to each test case.

Constraints 
1 <= T <= 10
0 <= N <= 10^12 

Sample Input
2
10
17

Sample Output
Ten
Seventeen
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const string ones[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
const string teens[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string makeWord(long block){
    string result = "";
    if (block / 100 > 0){
        result += ones[block/100] + " Hundred";
        if (block % 100 > 0){
            result += " ";
        }
    }
    if (block % 100 < 20){
        if (block % 100 < 10){
            result += ones[block % 100];
        } else {
            result += teens[block % 100 - 10];
        }            
    } else {
        result += tens[(block/10) % 10];
        if (block % 10 > 0){
            result += " " + ones[block % 10];
        }
    }
    return result;
}

int main() {
    int t;
    long n;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        if (n == 0){
            cout << "Zero" << endl;
        } else{
            long blocks[4];
            blocks[0] = n % 1000;
            blocks[1] = (n / 1000) % 1000;
            blocks[2] = (n / 1000000) % 1000;
            blocks[3] = n / 1000000000;
            if (blocks[3] > 0){
                cout << makeWord(blocks[3]) << " Billion";
            }
            if (blocks[2] > 0) {
                if (blocks[3] > 0){
                    cout << " ";
                }
                cout << makeWord(blocks[2]) << " Million";
            }
            if (blocks[1] > 0){
                if (blocks[2] > 0 || blocks[3] > 0){
                    cout << " ";
                }
                cout << makeWord(blocks[1]) << " Thousand";
            }
            if (blocks[0] > 0){
                if (blocks[3] > 0 || blocks[2] > 0 || blocks[1] > 0){
                    cout << " ";
                }
                cout << makeWord(blocks[0]);
            }
            cout << endl;
        }
    }
    return 0;
}
