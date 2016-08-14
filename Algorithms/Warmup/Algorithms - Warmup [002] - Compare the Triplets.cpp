/*
PROBLEM:
Alice and Bob each created one problem for HackerRank. 
A reviewer rates the two challenges, awarding points on a scale from 1 to 100 for three categories: problem clarity, originality, and difficulty.

We define the rating for Alice's challenge to be the triplet A = (a0, a1, a2), 
and the rating for Bob's challenge to be the triplet B = (b0, b1, b2).

Your task is to find their comparison scores by comparing a0 with b0, a1 with b1, and a2 with b2.

If ai > bi, then Alice is awarded  point.
If bi > ai, then Bob is awarded  point.
If ai = bi, then neither person receives a point.
Given A and B, can you compare the two challenges and print their respective comparison points?

Input Format

The first line contains 3 space-separated integers, a0, a1, and a2, describing the respective values in triplet . 
The second line contains 3  space-separated integers, b0, b1, and b2, describing the respective values in triplet .

Constraints
1 < = ai, bi <= 100

Output Format
Print two space-separated integers denoting the respective comparison scores earned by Alice and Bob.

Sample Input
5 6 7
3 6 10

Sample Output
1 1 
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a[3], aScore = 0;
    cin >> a[0] >> a[1] >> a[2];
    int b[3], bScore = 0;
    cin >> b[0] >> b[1] >> b[2];
    for (int i = 0; i < 3; i++){
        if (a[i] > b[i]){
            aScore ++;
        } else if (a[i] != b[i]){
            bScore ++;
        }
    }
    cout << aScore << " " << bScore << endl;
    return 0;
}
