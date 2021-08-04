#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool desc(string a, string b) { // 정렬의 방법을 설정
   return a+b>b+a;   // 두 문자열을 이어봤을 때 큰 숫자 순서로.
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;

    for (int i = 0; i < numbers.size(); i++) {
        str.push_back(to_string(numbers[i]));
    }

    sort(str.begin(), str.end(), desc); // 정렬.

    for (int i = 0; i < str.size(); i++) {
        answer+=str[i];
    }
    if (answer[0]=='0') answer = "0";
    return answer;
}
