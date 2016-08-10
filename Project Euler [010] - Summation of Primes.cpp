/*
PROBLEM:
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes not greater than given N.

Input Format 
The first line contains an integer T i.e. number of the test cases. 
The next T lines will contains an integer N.

Output Format 
Print the value corresponding to each test case in seperate line.

Constraints 
1 <= T <= 10^4
1 <= N <= 10^6 

Sample Input
2
5
10

Sample Output
10
17
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, primeCount = 0, maxN = 0;
    cin >> t;
    int n[t];
    for (int i = 0; i < t; i++){
        cin >> n[i];
        if (n[i] > maxN){
            maxN = n[i];
        }
    }
    bool nums[maxN] {0};
    nums[0] = 1;
    nums[1] = 1;
    
    for (int i = 2; i*i <= maxN; i++){
        if (nums[i] == 0){
            //primeCount ++;
            for (int j = i*i; j <= maxN; j += i){
                nums[j] = 1;
            }
        }
    }
    vector <int> primes;
    for (int i = 0; i <= maxN; i++){
        if (nums[i] == 0){
            primes.push_back(i);
        }
    }
    
    for (int i = 0; i < t; i++){
        long sum = 0;
        for (int j = 0; primes[j] <= n[i]; j++){
            sum += primes[j];
            if (j+1 == primes.size()){
                break;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
