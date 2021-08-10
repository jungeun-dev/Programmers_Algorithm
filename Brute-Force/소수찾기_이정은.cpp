#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(string num, string deci) { // �ش� �Ҽ�(deci)�� num�� ����ִ� ���ڷ� �����Ǿ��ִ��� Ȯ��
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
    sort(nums.begin(), nums.end(), greater<int>()); //��������
    for (int i = 0; i < nums.size(); i++) max += nums[i]; // ���� �� �ִ� ���� ū ���� string ��

    //�Ҽ� �ֱ� (2 ~ max ���� �Ҽ��� ���� decimal�� �ֱ�)
    for (int i = 2; i <= stoi(max); i++) {
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) break;
        }
        if (j * j >= i + 1) decimals.push_back(to_string(i));

    }
    //����� �־��� ���� Ȯ��
    for (int i = 0; i < decimals.size(); i++) {
        if (cmp(numbers, decimals[i])) answer++;
    }

    return answer;
}