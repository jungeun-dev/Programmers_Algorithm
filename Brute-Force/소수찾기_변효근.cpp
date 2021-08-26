#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

vector <int> prime_number(string numbers) { //에라토스테네스의 체 방식을 이용.
    int num = pow(10,numbers.size()+1);
    vector <int> prime;
    vector <bool> visit;
    visit.assign(num, false);
    for (int i = 2; i < num; i++) {
        if (visit[i] == false) {
            prime.push_back(i);
            for (int j = i * 2; j < num; j += i) {
                visit[j] = true;
            }
        }
    }
    return prime;
}

int solution(string numbers) {
    int answer = 0;
    vector <int> prime = prime_number(numbers);
    for (int p : prime) {
        map<int, int> n;
        for (int i = 0; i < numbers.size(); i++) {
            int num = numbers[i] - '0';
            n[num]++;
        }
        while (p!=0) {
            n[p % 10]--;
            p /= 10;
        }
        for (auto it = n.begin(); it != n.end(); it++){
          if (it->second < 0) {
              answer--;
              break;
          }
        }

        answer++;
    }
    return answer;
}
