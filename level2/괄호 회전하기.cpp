// level2
// 성공. 스택, string, 구현.
#include <string>
#include <vector>
#include<iostream>
#include<stack>
using namespace std;

bool IsRight(string s){
    stack<char> cs;
    for(int i=0;i<s.size();i++){
        if(cs.empty()){
            if(s[i]==')' || s[i]=='}' || s[i]==']') return false;
            cs.push(s[i]);
        }
        else{
            if(s[i]==')'){
                if(cs.top()!='('){
                    return false;
                }
                else{
                    cs.pop();
                }
            }
            else if(s[i]==']'){
                if(cs.top()!='['){
                    return false;
                }
                else{
                    cs.pop();
                }
            }
            else if(s[i]=='}'){
                if(cs.top()!='{'){
                    return false;
                }
                else{
                    cs.pop();
                }
            }
            else{
                cs.push(s[i]);
            }
        }
    }
    if(cs.empty()) return true;
    else return false;
}

int solution(string s) {
    int answer = 0;
    string str = s;
    for(int i=0;i<s.size();i++){
        str = str + str[0];
        str.erase(0,1);
        if(IsRight(str)) answer++;
    }

    return answer;
}