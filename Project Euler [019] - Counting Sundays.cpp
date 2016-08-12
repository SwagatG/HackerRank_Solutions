/*
PROBLEM:
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September, 
April, June and November. All the rest have thirty-one, 
Saving February alone, 
Which has twenty-eight, rain or shine. And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month between two dates(both inclusive)?

Input Format 
The first line contains an integer T , i.e., number of test cases. 
Each testcase will contain two lines 
Y1 M1 D1 on first line denoting starting date 
Y2 M2 D2 on second line denoting ending date.

Output Format 
Print the values corresponding to each test case.

Constraints 
1 <= 100 <= T
1900 <= Y1 <= 10^16
Y1 <= Y2 <= (Y1 + 1000)
1 <= M1, M2 <= 12
1 <= D1, D2 <= 31

Sample Input
2
1900 1 1
1910 1 1
2000 1 1
2020 1 1

Sample Output
18
35
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//                      J,   F,  M,  A,  M,  J,  J,  A,  S,  O,  N,  D 
const int monthCode[12] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
//For Yr % 28
const int yrCode[28] = {0, 1, 2, 3, 5, 6, 0, 1, 3, 4, 5, 6, 1, 2, 3, 4, 6, 0, 1, 2, 4, 5, 6, 0, 2, 3, 4, 5};
//For Century % 4
const int cCode[4] = {0, 5, 3, 1};

bool checkLeap (long yr){
    bool result = false;
    if (yr % 400 == 0 || (yr % 4 == 0 && yr % 100 != 0)){
        result = true;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        long y1, y2, m1, m2, d1, d2;
        long yc, mc, dc;
        int day, sCount = 0; //day is 0 for Sunday.
        long yt, mt, dt, ct;
        bool isLeap;
        
        cin >> y1 >> m1 >> d1;
        cin >> y2 >> m2 >> d2;
        
        dt = d1;
        mt = monthCode[m1 - 1];
        
        if (m1 < 3){
            yt = y1 - 1;
        } else {
            yt = y1;
        }
        ct = yt / 100;
        yt %= 100;
        ct = cCode[ct%4];
        yt = yrCode[yt%28];
        
        day = (dt + mt + yt + ct) % 7;
        
        yc = y1;
        mc = m1;
        dc = d1;
        isLeap = checkLeap(yc);
        
        while (!(yc > y2 || (yc >= y2 && mc > m2) || (yc >= y2 && mc >= m2 && dc > d2))){
            if (dc == 1){
                if (day == 0){
                    sCount ++;
                }
                if (mc == 2 && isLeap == true){
                    day += 29;
                    day %= 7;
                } else {
                    day += months[mc-1];
                    day %= 7;
                }
            } else {
                 if (mc == 2 && isLeap == true){
                    day += 30 - dc;
                    day %= 7;
                    dc = 1;
                } else {
                    day += months[mc-1] + 1 - dc;
                    day %= 7;
                    dc = 1;
                }
            }
            mc ++;
            if (mc > 12){
                yc ++;
                mc = 1;
                isLeap = checkLeap(yc);
            }
        }
        cout << sCount << endl;
    }
    return 0;
}
