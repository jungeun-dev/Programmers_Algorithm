#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<string> tmp = {"D 1", "D -1"};
    priority_queue<int,vector<int>,less<int>> q_less;
    //내림차순배열로 큐 선언
    priority_queue<int,vector<int>,less<int>> q_greater;
    //내림차순배열로 큐 선언
    int num;
    int count=0;
    int temp,start;

    for(int i=0;i<operations.size();i++){
        string s=operations[i];
        if(s==tmp[0]){
            if(count==0){
                continue;
            }
            q_less.pop();
            count--;
        }
        else if(s==tmp[1]){
            int cnt=count;
            int cnt2=count-1;
            if(count==0){
                continue;
            }
            while(cnt>1){
                q_greater.push(q_less.top());
                q_less.pop();
                cnt--;
            }
            q_less.pop();
            while(cnt2>0){
                q_less.push(q_greater.top());
                q_greater.pop();
                cnt2--;
            }
            count--;
        }

       else if(s[0]=='I'){
            s.erase(0,2);
            if(s[0]=='-'){
               s.erase(0,1);
                num=stoi(s) * -1;
                q_less.push(num);
                count++;
            }
            else{
                num=stoi(s);
                q_less.push(num);
                count++;
            }
        }
        else{

        }
    }
    if(count==0){
        return {0,0};
    }
    else if(count==1){
        return {q_less.top(),q_less.top()};
    }
    else{
        start=q_less.top();
        while(!q_less.empty()){
            temp=q_less.top();
            q_less.pop();
        }
        return {start,temp};
    }


}
