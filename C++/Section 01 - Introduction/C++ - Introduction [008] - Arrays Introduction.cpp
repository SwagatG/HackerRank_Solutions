/*
PROBLEM:
An array is a series of elements of the same type placed in contiguous memory locations that can be individually referenced by adding an index to a unique identifier.

Declaration:
	int arr[10]; //Declares an array named arr of size 10, i.e; you can store 10 integers.

Accessing elements of an array:
Indexing in arrays starts from 0.So the first element is stored at arr[0],the second element at arr[1]...arr[9]
You'll be an given array of N integers and you have to print the integers in the reverse order.

Input Format
The first line of the input contains N, where N is the number of integers.
The next line contains N integers separated by a space.

Constraints
1 <= N <= 1000
1 <= Ai <= 10000, where Ai is the ith integer in the array.

Output Format
Print the N integers of the array in the reverse order in a single line separated by a space.

Sample Input
4
1 4 3 2

Sample Output
2 3 4 1
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    for (int j = n-1; j >= 0; j--){
        cout << nums[j] << " ";
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
