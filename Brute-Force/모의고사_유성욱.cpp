#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    //1번 수포자 주기 5
    //2번 수포자 주기 8
    //3번 수포자 주기 10
    vector<vector<int>> student{{1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5}};
    int count1 = 0, count2 = 0, count3 = 0;

    for (int i = 0 ; i < answers.size() ; i++)
    {
        int a = i % 5;
        int b = i % 8;
        int c = i % 10;

        if (answers[i] == student[0][a])
        {
            count1++;
        }
        if (answers[i] == student[1][b])
        {
            count2++;
        }
        if (answers[i] == student[2][c])
        {
            count3++;
        }
    }

    int maxc = max(count1, count2);
    maxc = max(maxc, count3);

    if (maxc == count1)
    {
        answer.push_back(1);
    }
    if (maxc == count2)
    {
        answer.push_back(2);
    }
    if (maxc == count3)
    {
        answer.push_back(3);
    }
    return answer;
}
