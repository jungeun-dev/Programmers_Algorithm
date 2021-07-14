#include <string>
#include <vector>
#include <set>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    multiset<string> s;


    for (int i = 0; i < participant.size(); i++) {
        s.insert(participant[i]);
    }
    for (int i = 0; i < completion.size(); i++)
    {
        s.erase(s.find(completion[i]));
    }

    answer = *s.begin();
    return answer;
}