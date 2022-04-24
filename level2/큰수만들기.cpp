#include <string>
#include <vector>
#include<stack>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> s;
    int count=0;
    int i=1;
    s.push(number[0]);
    while(1){
        if(count==k){
            s.push(number[i]);
        }
        else if(s.top()<number[i]){
            while(!s.empty() && s.top()<number[i] && count<k){
                count++;
                s.pop();
            }
            s.push(number[i]);
        }
        else s.push(number[i]);
        i++;
        if(i>=number.size()) break;
    }
    if(count<k){
        while(1){
            s.pop();
            count++;
            if(count==k) break;
        }
    }
    while(!s.empty()){
        answer=s.top()+answer;
        s.pop();
    }
    return answer;
}
