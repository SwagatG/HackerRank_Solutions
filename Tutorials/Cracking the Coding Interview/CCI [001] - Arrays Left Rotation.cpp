/*
PROBLEM:
A left rotation operation on an array of size 1 shifts each of the array's elements 1 unit to the left.
For example, if 2 left rotations are performed on array [1,2,3,4,5], then the array would become
[3,4,5,1,2].

Given an array of n integers and a number, k, perform k left rotations on the array.
Then print the updated array as a single line of space-separated integers.

Input Format

The first line contains two space-separated integers denoting the respective values of n (the number of integers) 
and k (the number of left rotations you must perform). 
The second line contains n space-separated integers describing the respective elements of the array's initial state.

Constraints
1 <= n <= 10^5
1 <= k <= n
1 <= ai <= 10^6

Output Format
Print a single line of n space-separated integers denoting the final state of the array after 
performing k left rotations.

Sample Input
5 4
1 2 3 4 5

Sample Output
5 1 2 3 4
*/

#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

vector<int> array_left_rotation(vector<int> a, int n, int k) {
    queue<int> buffer;
    for (int i = n - 1; i >= 0; i--){
        buffer.push(a[i]);
        if (buffer.size() > k){
            a[i] = buffer.front();
            buffer.pop();
        }
    }
    for (int i = n - 1; i >= n-k; i--){
        buffer.push(0);
        a[i] = buffer.front();
        buffer.pop();
    }
    return a;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}
