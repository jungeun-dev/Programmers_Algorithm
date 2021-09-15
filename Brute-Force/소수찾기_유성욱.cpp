#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//1.문자열을 하나씩 쪼개서 int형으로 변환하기
//2.변환한 int형 숫자들로 만들 수 있는 모든 숫자들을 담을 배열 만들기
//3.배열의 값 중에 소수가 몇개인지 판단하기
int solution(string numbers) {
    int answer = 0;
    vector<int> num;
    vector<char> str;

    //1
    //answer = stoi(numbers);
    //0을 보존
    for (int i = 0 ; i < numbers.size() ; i++)
    {
        str.push_back(numbers[i]);
    }
    sort(str.begin(), str.end());
    //[1,7]

    //1,2
    //1, 17, 7, 71
    do {
        string str2;
        for (int i = 0 ; i < str.size() ; i++)
        {
            str2.push_back(str[i]);
            num.push_back(stoi(str2));
        }
    } while (next_permutation(str.begin(), str.end()));

    //num = [1, 17, 7, 71]
    sort(num.begin(), num.end());
    //num[1,7,17,71]

    //case2 중복되는 값 삭제
    for (int i = 0 ; i < num.size() - 1 ; i++)
    {
        for (int j = i + 1 ; j < num.size() ; j++)
        {
            if (num[i] == num[j])
            {
                num[i] = 1;
            }
        }
    }

    //3
    for (int i = 0 ; i < num.size() ; i++)
    {
        int count = 0;
        for (int j = 1 ; j <= num[i] ; j++)
        {
            if (num[i] % j == 0)
            {
                count++;
            }
        }
        if (count == 2)
        {
            answer++;
        }
    }

    return answer;
}
