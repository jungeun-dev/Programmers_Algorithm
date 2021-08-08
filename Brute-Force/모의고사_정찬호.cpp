#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int k=0, count=0, max = 0;
    vector<int> first = { 1,2,3,4,5 };
    vector<int> second = { 2,1,2,3,2,4,2,5 };
    vector<int> third = { 3,3,1,1,2,2,4,4,5,5 };


    for (int i = 0;i < answers.size();i++) {
        if (first[(k++) % first.size() % answers.size()] == answers[i]) {count++;}
    }
    if (count >= max && count != 0) {max = count;}
    count = 0;
    k = 0;

    for (int i = 0;i < answers.size();i++) {
        if (second[(k++) % second.size() % answers.size()] == answers[i]) {count++;}
    }
    if (count >= max && count != 0) {max = count;}
    count = 0;
    k = 0;

    for (int i = 0;i < answers.size();i++) {
        if (third[(k++) % third.size() % answers.size()] == answers[i]) {count++;}
    }
    if (count >= max && count != 0) { max = count;}
    count = 0;
    k = 0;

    //------------------------------------------------------------------
    for (int i = 0;i < answers.size();i++) {
        if (first[(k++) % first.size() % answers.size()] == answers[i]) { count++; }
    }
    if (count == max && count != 0) {answer.push_back(1);}
    count = 0;
    k = 0;

    for (int i = 0;i < answers.size();i++) {
        if (second[(k++) % second.size() % answers.size()] == answers[i]) { count++; }
    }
    if (count == max && count != 0) { answer.push_back(2); }
    count = 0;
    k = 0;

    for (int i = 0;i < answers.size();i++) {
        if (third[(k++) % third.size() % answers.size()] == answers[i]) { count++; }
    }
    if (count == max && count != 0) { answer.push_back(3); }
    count = 0;
    k = 0;


    return answer;
}
