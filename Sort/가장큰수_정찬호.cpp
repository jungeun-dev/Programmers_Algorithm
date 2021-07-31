#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare (int a, int b){
    string first = to_string(a); // 숫자를 문자로변환
    string second = to_string(b);// 숫자를 문자로변환
    string sum1 = first;
    sum1.append(second); //처음것에 두번째 붙히기
    string sum2 = second;
    sum2.append(first); // 두번째에 첫번째 붙히기
    if(atoi(sum1.c_str()) > atoi(sum2.c_str())){return true;} //문자열을 숫자로 변환한다음에 비교값보다 크면 그대로 출력
    if(atoi(sum1.c_str()) < atoi(sum2.c_str())){return false;}  //아님말고
}
string solution(vector<int> numbers) {
    string answer = "";
    int count=0;
    for(int i=0;i<numbers.size();i++){if(numbers[i]==0){count++;}}
    if(count==numbers.size()){answer.append("0"); return answer;} // 예외경우) 테스트케이스11 모든값이 0일때 00... 이아닌 0값 출력
    sort(numbers.begin(),numbers.end(),compare);//정렬
    for(int i=0;i<numbers.size();i++){answer.append(to_string(numbers[i]));}
    return answer;
}
