#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int count=0;
    for(int i=0;i<=citations.size();i++){
        for(int j=0;j<citations.size();j++){
            if(i<=citations[j]){count++;}
        }//비교값보다 작으면 카운트추가
        if(count>=i){answer=i;}//카운트가 비교값보다 크거나 같으면 답은 비교값
        count=0;
    }
    return answer;
}
