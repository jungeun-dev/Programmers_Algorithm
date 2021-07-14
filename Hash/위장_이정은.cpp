#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0;
	map<string, int> wear;

	for (int i = 0; i < clothes.size(); i++) {
		wear[clothes[i][1]]++;
	}
	answer = 1;
	for (auto it = wear.begin(); it != wear.end(); it++)
		answer *= it->second + 1;

	return answer - 1;
}