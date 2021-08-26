#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;

    vector<pair<int, int>> camera; //pair로 카메라를 설치할 위치를 벡터에 저장.

     for (int i = 0; i < routes.size(); i++) {
        sort(routes[i].begin(), routes[i].end());
        // 이 문제서 특이하게 [15,-20] 같은 예제를 줌;
    }
    sort(routes.begin(), routes.end());
    // 이건 왜 해야하는 건지 모르겠지만 해야지만 문제가 풀림..

    for (int i = 0; i < routes.size(); i++) {
        if (i == 0) {
            camera.push_back(make_pair(routes[i][0], routes[i][1])); // 처음에 벡터에 값을 넣고 시작함.
        }
        continue;
        for (int j = 0; j < camera.size(); j++) {

            if (routes[i][0] <= camera[j].first && camera[j].second <= routes[i][1]) { // A가 B에 포함
                // ex) [-5,-3], [-20,15]
                break;
            }
            else if (camera[j].first <= routes[i][0] && routes[i][1] <= camera[j].second){// B가 A에 포함
                // ex) [-20,15] , [-5,-3]
                camera[j].first = routes[i][0];
                camera[j].second = routes[i][1];
                break;
            }

            else if (routes[i][0] <= camera[j].first && camera[j].first <= routes[i][1] && routes[i][1] <= camera[j].second) {
                // A와 B가 겹침.
                // ex) [-20,3] , [1,7]
                camera[j].second = routes[i][1];
                break;
            }
            else if (camera[j].first <= routes[i][0] && routes[i][0] <= camera[j].second && camera[j].second <= routes[i][1]) {
                // A와 B가 겹침.
                // ex) [3,10] , [1,7]
                camera[j].first = routes[i][0];
                break;
            }
            if(j==camera.size()-1) { // 겹치는 일이 없다면 그냥 하나 추가.
                camera.push_back(make_pair(routes[i][0], routes[i][1]));
            }
        }

    }

    return answer=camera.size();
}
