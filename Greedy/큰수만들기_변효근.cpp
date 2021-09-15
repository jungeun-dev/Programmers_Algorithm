#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    for (int i = 0; i < number.size() - k; ++i) {
        auto iter = std::max_element(number.begin() + i, number.begin() + i + k + 1); // i부터 i+k 중 가장 큰 수를 iter에 저장.
        if (iter != number.begin() + i) {
            k = k - std::distance(number.begin() + i, iter); //k까지의 인덱스를 k에 저장 -> 그만큼 지울거니까
            number.erase(number.begin() + i, iter);          //k까지 다 지움.
        }
    }
    number.erase(number.end() - k, number.end());
    return number;
}
