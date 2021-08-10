#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(string num, string deci) { // 해당 소수(deci)가 num에 들어있는 숫자로 구성되어있는지 확인
    int pos, i;
    for (i = 0; i < deci.size(); i++) {
        if ((pos = num.find(deci[i])) != string::npos) {
            num.erase(pos, 1);
        }
        else break;
    }
    return (i == deci.size());
}
int solution(string numbers) {
    int answer = 0;
    vector<char> nums;
    vector<string> decimals;
    string max;
    int j;

    for (int i = 0; i < numbers.size(); i++) {
        nums.push_back(numbers[i]);
    }
    sort(nums.begin(), nums.end(), greater<int>()); //내림차순
    for (int i = 0; i < nums.size(); i++) max += nums[i]; // 만들 수 있는 가장 큰 숫자 string 형

    //소수 넣기 (2 ~ max 에서 소수인 숫자 decimal에 넣기)
    for (int i = 2; i <= stoi(max); i++) {
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) break;
        }
        if (j * j >= i + 1) decimals.push_back(to_string(i));

    }
    //만들수 있었던 건지 확인
    for (int i = 0; i < decimals.size(); i++) {
        if (cmp(numbers, decimals[i])) answer++;
    }

    return answer;
}