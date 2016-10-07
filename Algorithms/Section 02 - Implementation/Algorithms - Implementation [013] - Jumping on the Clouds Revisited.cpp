/*
PROBLEM:
Aerith is playing a cloud game! In this game, there are n clouds numbered sequentially from 0 to n -1. 
Each cloud is either an ordinary cloud or a thundercloud.

Aerith starts out on cloud 0 with energy level 100. She can use 1 unit of energy to make a jump of size k to cloud (i + K) % n
until she gets back to cloud 0. If Aerith lands on a thundercloud, her energy (E) decreases by 2 additional units. 
The game ends when Aerith lands back on cloud 0.

Given the values of n, k, and the configuration of the clouds, can you determine the final value of E after the game ends?

Note: Recall that % refers to the modulo operation.

Input Format
The first line contains two space-separated integers, n (the number of clouds) and k (the jump distance), respectively. 
The second line contains n space-separated integers describing the respective values of clouds c0, c1, ..., cn-1, cn. 
Each cloud is described as follows:
	If ci = 0, then cloud  is an ordinary cloud.
	If ci = 1, then cloud  is a thundercloud.

Constraints
2 <= n <= 25
1 <= k <= n
n % k = 0
ci E {1,0}

Output Format
Print the final value of E on a new line.

Sample Input
8 2
0 0 1 0 0 1 1 0

Sample Output
92
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> c(n+1);
    for(int c_i = 0;c_i < n;c_i++){
       cin >> c[c_i];
    }
    c[n] = c[0];
    
    int E = 100, currPos = 0;
    while (currPos < n){
        currPos += k;
        if (c[currPos] == 1){
            E -= 3;
        } else {
            E --;
        }
    }
    cout << E;
    return 0;
}
