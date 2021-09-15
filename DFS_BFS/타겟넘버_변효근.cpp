#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iostream>


using namespace std;

int a = 0;

queue<int> bfs(queue<int> total, vector<int> numbers) {

    total.push(numbers[0]);             // 첫번째 값만 넣어둠.
    total.push(numbers[0] * -1);        // 음수값도 같이 넣음.

    for (int idx = 1; idx < numbers.size(); idx++)
    {
        for (int i = 0; i < pow(2, idx); i++)
        {
            int t = total.front();          // queue 안의 값을 빼서
            total.pop();
            total.push(t + numbers[idx]);   // 양수값 다시넣기.
            total.push(t - numbers[idx]);   // 음수값 다시 넣기.

        }
    }

    return total;
}

void dfs(vector<int> numbers,int sum, int idx,int target) {
    if (idx == numbers.size()) {
        if (sum == target) a++;
        return;
    }

    dfs(numbers, sum + numbers[idx], idx+1, target);      // sum을 통해 값을 넣음.
    dfs(numbers, sum - numbers[idx], idx+1, target);

}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    /*
    queue <int> total;

    total = bfs(total, numbers);

    while (!total.empty())
    {
        int t = total.front();
        total.pop();
        if(t == target) answer++;
    }
    */
    dfs(numbers, 0, 0, target);

    return answer = a;
}
