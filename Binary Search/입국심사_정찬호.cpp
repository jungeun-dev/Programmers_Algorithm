#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdint.h>

using namespace std;


bool check(vector<int> times,int a){
    for(int i=0;i<times.size();i++){
       if(a%i==0){return true;}
    }
    return false;
}


long long solution(int n, vector<int> times) {
    long long answer=0;
    long long  num;
    long long count = 0;
    long long left = 0, right = 0, mid = 0;
    sort(times.begin(),times.end());
    left = 0;
    right = (long long)times[times.size()-1]*n;
    while (left<=right) {
        mid = (right + left) / 2;
        //cout << mid;
        for (int j = 0;j < times.size();j++) {
            count =count+ (mid / times[j]);
        }
        //cout << count;

        if (count < n) {
            left = mid + 1;
            //cout << 2;
        }
        else {
            if(mid<=right)
            answer=mid;
            //cout << 1;
            right=mid-1;
        }

        count = 0;
    }
    return answer;
}
