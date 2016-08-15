/*
PROBLEM:
Given a word 2, rearrange the letters of 2 to construct another word s in such a way that s is lexicographically greater than s. 
In case of multiple possible answers, find the lexicographically smallest one among them.

Input Format
The first line of input contains t, the number of test cases. Each of the next t lines contains w.

Constraints
1 <= t <= 10^5
1 <= |w| <= 100
w will contain only lower-case English letters and its length will not exceed 100.

Output Format
For each testcase, output a string lexicographically bigger than w in a separate line. 
In case of multiple possible answers, print the lexicographically smallest one, and if no answer exists, print no answer.

Sample Input
5
ab
bb
hefg
dhck
dkhc

Sample Output
ba
no answer
hegf
dhkc
hcdk
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        string w;
        bool isChange = false;
        cin >> w;
        int minChange = 10000, currChange, minK;
        for (int j = w.length() - 2; j >= 0; j--){
            for (int k = (w.length()-1) - j; k > 0; k--){
                currChange = w[j+k] - w[j];
                if (currChange > 0 && currChange < minChange){
                    minChange = currChange;
                    minK = k;
                }
            }
            if (minChange > 0 && minChange < 26){
                isChange = true;
                char temp;
                temp = w[j];
                w[j] = w[j+minK];
                w[j+minK] = temp;
                vector <char> ending;
                for (int k = j+1; k < w.length(); k++){
                    ending.push_back(w[k]);
                }
                make_heap(ending.begin(), ending.end());
                sort_heap(ending.begin(), ending.end());
                for (int k = 0; k < ending.size(); k++){
                    w[j+k+1] = ending[k];
                }
                j = -1;
            }
        }
        if (isChange){
            cout << w << endl;  
        } else {
            cout << "no answer\n";
        }
    }
    return 0;
}
