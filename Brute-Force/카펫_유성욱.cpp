#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int num = (brown - 4)/2;
    for (int i = 1 ; i < num ; i++)
    {
        int x = num-i;
        int y = i;
        if (x * y == yellow)
        {
            answer.push_back(x + 2);
            answer.push_back(y + 2);
            break;
        }
    }
    return answer;
}
