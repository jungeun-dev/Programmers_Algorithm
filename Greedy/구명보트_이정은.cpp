#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int start = 0, end = people.size() - 1;

    sort(people.begin(), people.end()); // �⺻ �������� ����

    while (start <= end) {

        if (people[start] + people[end] <= limit) {
            start++;
            end--;
            answer++;
        }
        else {
            end--;
            answer++;
        }
    }
    return answer;
}

//ȿ���� 1,3 ����
// int solution(vector<int> people, int limit) {
//     int answer = 0;

//     sort(people.begin(), people.end()); // �⺻ �������� ����

//     while(people.size() > 1){
//         if(people[people.size() -1] <= limit / 2) {
//             answer += (people.size() + 1) /2;
//             return answer;
//         }
//         if(people[0] + people[people.size() -1] <= limit){
//             people.erase(people.begin() + people.size() - 1);
//             people.erase(people.begin());
//             answer++;
//         }
//         else {
//             people.erase(people.begin() + people.size() - 1);
//             answer++;
//         }
//     }
//     answer += people.size();
//     return answer;
// }

//ȿ���� 1,2,3���� �ڵ�
// int solution(vector<int> people, int limit) {
//     int answer = 0;
//     int two = 0;

//     sort(people.begin(), people.end()); // �⺻ �������� ����

//     while(people.size() > 0){
//         two = 0;
//         for(int i = people.size() - 1 ; i > 0; i--){
//             if(people[i] + people[0] <= limit) {
//                 two = i;
//                 break;
//             }
//         }
//         if(two == 0) {
//             answer += people.size();
//             break;
//         }
//         else{
//             people.erase(people.begin()+two); // ���� ���� �� ����
//             people.erase(people.begin());            
//             answer++;
//         }
//     }
//     return answer;
// }