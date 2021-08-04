#include <string>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nums;
    for (int num : numbers) {
        nums.push_back(to_string(num));
    }

    sort(nums.begin(), nums.end(), cmp);
    if (nums[0] == "0") return "0"; //예외의 경우
    //if(stoi(answer) == 0) answer = "0";

    for (string n : nums)  answer += n;

    return answer;
}