#include <string>
#include <vector>
#include<stdlib.h>
#include<stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool check(int a) {
    int i;
    for( i = 2;i * i <= a;i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> container;
    vector<int> boxcontainer;
    vector<int> thenewcontainer;
    vector<int> dummy;
    int temp = 0, p = 0, j = 0, tmp, max = 0, size = 0, count = 0;
    int box1, renewcount = 0, box2, cnt = 0,yy;

    temp = atoi(numbers.c_str());// string형을 int형으로 변환
    yy = numbers.length();
    while (yy > 0) {
        tmp = temp % 10;
        temp = temp / 10;
        container.push_back(tmp);
        yy--;
    }//배열에 원소 넣어주기

    sort(container.begin(), container.end(), greater<int>());//vector를 내림차순으로 정렬
    size = container.size();
    
    while (size > 0) {
        max = max * 10;
        max = max + container[j++];
        size--;
    }//숫자로 만들수 있는 최대의 숫자 만들기

    for (int i = 2;i <= max;i++) {
        box2 = i;
        thenewcontainer = container;//최고 숫자가 들어간 벡터
        if (check(i) == true) {
            while (box2 > 0) {
                boxcontainer.push_back(box2 % 10);
                cnt = thenewcontainer.size();
                box2 = box2 / 10;
            }// 비교할 소수를 새로운 컨테이너에 넣기
            for (int k = 0;k < boxcontainer.size();k++) {
                for (int p = 0;p < thenewcontainer.size();p++) {
                    if (boxcontainer[k] == thenewcontainer[p]) {

                        thenewcontainer.erase(thenewcontainer.begin() + p);

                        break;
                    }
                }
            }// 똑같은거 없애는 과정
            if (boxcontainer.size()==cnt-thenewcontainer.size()) {

                answer++;
            }//소수가들어간 벡터가 비어있다면 = 소수의 요소가 전부 있다면
            boxcontainer.clear();
            cnt = 0;
        }
        thenewcontainer.clear();
        count = 0;
    }

    return answer;
}
