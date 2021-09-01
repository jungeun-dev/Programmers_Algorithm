#include <string>
#include <vector>

using namespace std;


// N을 1번 쓴 경우  1
// N을 2번 쓴 경우  2 1-1
// N을 3번 쓴 경우  3 2-1
// N을 4번 쓴 경우  4 3-1 2-2
// N을 5번 쓴 경우  5 4-1 3-2
int Digit(int i, int N) {  // 5 , 55 , 555 , 5555와 같은 수들을 만들기 위한 함수.
    int number = N;
    for (int j = 0; j < i-1; j++) {
        number = number * 10 + N;
    }
    return number;
}

int solution(int N, int number) {
    int answer = 0;
    vector <vector<int>> n;   // 모든 Digit에 벡터를 저장하는 벡터.
    n.push_back({}); // index맞출라고 하나 그냥 넣음.

    int i = 1; // i는 Digit을 의미. 즉 i =2 일 경우 55, 0 , 10 등의 연산을 할 것임.

    while (i<9) { // 9이상일 경우 -1을 return하기에

        vector <int> v;                               // 이 벡터는 그 해당 Digit에 값을 저장할 벡터.
        if (Digit(i, N) == number) return answer = i; // 만약 55와 같은 숫자일 경우 바로 리턴.
        else v.push_back(Digit(i, N));                // 아닐 경우 벡터에 넣음.

        for (int j = 1; j < i; j++) {
            vector<int> pivot = n[j];
            // 값들을 빼줄 벡터.
            // i가 5일 경우  N을 5번 쓴 것, 4번 쓴 것과 1번 쓴 것을 사칙연산, 3번 쓴 것과 2번 쓴 것을 사칙연산이 모두 포함되므로
            // 사칙연산하는 벡터를 pivot벡터에 복사함.
            for (int k = 0; k < n[i-j].size(); k++) {
                for (int x = 0; x < pivot.size(); x++) {
                    if (n[i - j][k] + pivot[x] == number) return answer = i;               // 찾는 값이 있으면 바로 리턴.
                    if (n[i - j][k] + pivot[x] > 0) v.push_back(n[i - j][k] + pivot[x]);   // 찾는 값이 없으면 벡터에 넣음.

                    if (n[i - j][k] - pivot[x] == number) return answer = i;
                    if (n[i - j][k] - pivot[x] > 0) v.push_back(n[i - j][k] - pivot[x]);

                    if (n[i - j][k] * pivot[x] == number) return answer = i;
                    if (n[i - j][k] * pivot[x] > 0) v.push_back(n[i - j][k] * pivot[x]);

                    if (n[i - j][k] / pivot[x] == number) return answer = i;
                    if (n[i - j][k] / pivot[x] > 0) v.push_back(n[i - j][k] / pivot[x]);
                }

            }
        }
        n.push_back(v);       // n에 저장함.
        i++;
    }
    return answer=-1;
}
