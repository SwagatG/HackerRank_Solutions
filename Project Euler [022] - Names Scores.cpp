/*
PROBLEM:
You are given around five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list in sample is sorted into alphabetical order, PAMELA, which is worth 16 + 1 + 13 + 5 + 12 + 1 = 48, is the 5th name in the list. So, PAMELA would obtain a score of 5 * 48 = 240.

You are given Q queries, each query is a name, you have to print the score.

Input Format 
The first line contains an integer N , i.e., number of names. 
Next N lines will contain a Name. 
Followed by integer Q followed by Q lines each having a word.

Output Format 
Print the values corresponding to each test case.

Constraints 
1 <= N <= 5200
length of each word will be less than 12 
1 <= Q <= 100

Sample Input
5
ALEX
LUIS
JAMES
BRIAN
PAMELA
1
PAMELA

Sample Output
240
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector <string> names;
    string currName;
    for (int i = 0; i < n; i++){
        cin >> currName;
        names.push_back(currName);
    }
    make_heap(names.begin(), names.end());
    sort_heap(names.begin(), names.end());
    cin >> q;
    string currQ;
    for (int i = 0; i < q; i++){
        cin >> currQ;
        
        //BINARY SEARCH FOR POSIITION OF MATCH
		int lo = 0, hi = names.size() - 1, pos;
        pos = (lo + hi)/2;
        while(names[pos] != currQ && lo <= hi){
            if (names[pos] > currQ){
                hi = pos - 1;
            } else {
                lo = pos + 1;
            }
            pos = (lo + hi)/2;
        }
        
		long score = 0;
        for (int j = 0; j < names[pos].length(); j++){
            score += names[pos][j] - 64; // A is 65 on ASCII
        }
        pos += 1;
        score *= pos;
        cout << score << endl;
    }
    return 0;
}

