/*
PROBLEM:
Given a time in AM/PM format, convert it to military (24-hour) time.


Input Format

A single string containing a time in 12-hour clock format (i.e. hh:mm:ssAM  or hh:mm:ssPM), where 01 <= hh <= 12.

Output Format
Convert and print the given time in 24-hour format, where 00 <= hh <= 23.

Sample Input
07:05:45PM

Sample Output
19:05:45
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int hr, min, sec;
    char type;
    scanf("%d:%d:%d%cM", &hr, &min, &sec, &type);
    if (type == 'P'){
        if (hr == 12){
            hr = 12;
        } else {
            hr += 12;
        }
    } else {
        if (hr == 12){
            hr = 0;
        }
    }
    if (hr < 10){
        cout << "0";
    }
    cout << hr << ":";
    if (min < 10){
        cout << "0";
    }
    cout << min << ":";
    if (sec < 10){
        cout << "0";
    }
    cout << sec;
    return 0;
}
