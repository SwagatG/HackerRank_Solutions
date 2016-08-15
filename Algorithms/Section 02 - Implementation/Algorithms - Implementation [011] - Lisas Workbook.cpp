/*
PROBLEM:
Lisa just got a new math workbook. A workbook contains exercise problems, grouped into chapters.
	There are  chapters in Lisa's workbook, numbered from 1 to n.
	The -th chapter has ti problems, numbered from 1 to ti.
	Each page can hold up to k problems. There are no empty pages or unnecessary spaces, so only the last page of a chapter may contain fewer than k problems.
	Each new chapter starts on a new page, so a page will never contain problems from more than one chapter.
	The page number indexing starts at 1.
	
Lisa believes a problem to be special if its index (within a chapter) is the same as the page number where it's located. 
Given the details for Lisa's workbook, can you count its number of special problems?

Input Format
The first line contains two integers n and k — the number of chapters and the maximum number of problems per page respectively. 
The second line contains n integers t1, t2, ..., tn, where ti denotes the number of problems in the i-th chapter.

Constraints
1 <= n, k, ti <= 100

Output Format
Print the number of special problems in Lisa's workbook.

Sample Input
5 3  
4 2 6 1 10

Sample Output
4
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k, specCount = 0, currP = 0, currI = 0;
    cin >> n >> k;
    int t[n];
    for (int i = 0; i < n; i++){
        cin >> t[i];
    }
    for (int i = 0; i < n; i++){
        currP++;
        currI = 0;
        for (int j = 1; j <= t[i]; j++){
            currI ++;
            if (j == currP){
                specCount++;
            }
            if (currI == k && j != t[i]){
                currI = 0;
                currP++;
            }
        }
    }
    cout << specCount;
    return 0;
}
