#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    int print, tmp;

    while (1) {
        print = 0;
        tmp = priorities[0];
        for (int i = 1; i < priorities.size(); i++)
        {
            if (priorities[i] > tmp) {
                tmp = priorities[i];
                print = i;
            }
        }

        if (print == location) break;
        if (print == 0) {
            location--;
            priorities.erase(priorities.begin());
            answer++;
        }
        else {
            for (int i = 0; i < print; i++) {
                tmp = priorities[0];
                priorities.erase(priorities.begin());
                priorities.push_back(tmp);
                location--;
                if (location == -1) location = priorities.size() - 1;
            }
        }
    }
    return answer;
}