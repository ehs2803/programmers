#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string answer_str="";
    for(int i=0;i<s.size();){
        if('0'<=s[i] && s[i]<='9'){
            answer_str+=s[i];
            i++;
        }
        else if(s[i]=='z'){
            answer_str+='0';
            i+=4;
        }
        else if(s[i]=='o'){
            answer_str+='1';
            i+=3;
        }
        else if(s[i]=='t'){
            if(s[i+1]=='w'){
                answer_str+='2';
                i+=3;
            }
            else{
                answer_str+='3';
                i+=5;
            }
        }
        else if(s[i]=='f'){
            if(s[i+1]=='o'){
                answer_str+='4';
                i+=4;
            }
            else{
                answer_str+='5';
                i+=4;
            }
        }
        else if(s[i]=='s'){
            if(s[i+1]=='i'){
                answer_str+='6';
                i+=3;
            }
            else{
                answer_str+='7';
                i+=5;
            }
        }
        else if(s[i]=='e'){
            answer_str+='8';
            i+=5;
        }
        else if(s[i]=='n'){
            answer_str+='9';
            i+=4;
        }
    }
    
    
    int answer = stoi(answer_str);
    return answer;
}
