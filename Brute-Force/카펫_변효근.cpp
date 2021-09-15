#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    int weight = total / 2;

    while (weight >=0)
    {
        if (total % weight == 0)
        {
            int height = total / weight;
            if ((height - 2) * (weight - 2) == yellow)
            {
                answer.push_back(height);
                answer.push_back(weight);
                break;
            }
        }
        weight--;
    }

    sort(answer.begin(), answer.end(), greater<>());

    return answer;
}
