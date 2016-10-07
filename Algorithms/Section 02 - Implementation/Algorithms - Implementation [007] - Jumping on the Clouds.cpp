/*
PROBLEM:
Emma is playing a new mobile game involving n clouds numbered from 0 to n - 1. 
A player initially starts out on cloud c0, and they must jump to cloud cn-1. 
In each step, she can jump from any cloud i to cloud i + 1 or cloud i + 2.

There are two types of clouds, ordinary clouds and thunderclouds. 
The game ends if Emma jumps onto a thundercloud, but if she reaches the last cloud (i.e., cn-1), she wins the game!

Can you find the minimum number of jumps Emma must make to win the game? 
It is guaranteed that clouds c0 and cn-1 are ordinary-clouds and it is always possible to win the game.

Input Format
The first line contains an integer, n (the total number of clouds). 
The second line contains n space-separated binary integers describing clouds c0, c1, ..., cn-1.

If ci = 0, the ith cloud is an ordinary cloud.
If ci = 1, the ith cloud is a thundercloud.

Constraints
2 <= n <= 100
ci E {0,1}
c0 = 0 = cn-1

Output Format
Print the minimum number of jumps needed to win the game.

Sample Input
7
0 0 1 0 0 1 0

Sample Output
4
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> c(n);
    for(int c_i = 0;c_i < n;c_i++){
       cin >> c[c_i];
    }
    int currCloud = 0;
    int moveCounter = 0;
    while (currCloud < n-1){
        if (currCloud == n-1){
            moveCounter++;
            currCloud++;
        } else {
            if (c[currCloud+2] == 0){
                moveCounter ++;
                currCloud += 2;
            } else {
                moveCounter++;
                currCloud ++;
            }
        }
    }
    cout << moveCounter  << endl;
    return 0;
}
