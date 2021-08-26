#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector <int> arr(n+1, 1); // 1로 배열 초기화. 1개씩 모든 아이들이 체육복을 갖고 있다고 함.
    for (int i = 0; i < lost.size(); i++) arr[lost[i]]--; //잃어버린 애들꺼 -1씩
    for (int i = 0; i < reserve.size(); i++) arr[reserve[i]]++; //추가로 갖고있는 친구들꺼 +1씩
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == 0  && i==1 && arr[i+1] > 1) { // 1번 아이의 경우
            arr[i + 1]--;
            arr[i]++;
        }
        else if ((i != 1 && i != arr.size() - 1) && arr[i] == 0 && (arr[i + 1] > 1 || arr[i - 1] > 1))
        { // 1번과 마지막이 아닌 아이들의 경우 우선 바로 앞 애부터 검사한다.
            if (arr[i - 1] > 1) {
                arr[i - 1]--;
                arr[i]++;
            }
            else if(arr[i+1]>1) {
                arr[i + 1]--;
                arr[i]++;
            }
        }
        else if (arr[i] == 0 && i == arr.size()-1 && arr[i - 1] > 1) { // 마지막 아이의 경우
            arr[i - 1]--;
            arr[i]++;
        }
    }
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] >= 1) answer++;
    }

    return answer;
}
