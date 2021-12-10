// level2
// 성공. 구현 - string
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    for(int i=1; i<=26;i++){
        char c = i+64;
        string str(1, c);
        m.insert({str,i});
    }
    int maxlen = 1;
    int index=0;
    int value = 27;
    while(1){
        for(int i=maxlen; i>=1; i--){
            if(m.find(msg.substr(index, i))!=m.end()){
                int temp = m[msg.substr(index,i)];
                answer.push_back(temp);
                if(index!=msg.size()-1){
                    string newstr = msg.substr(index, i+1);
                    m.insert({newstr, value});
                    maxlen++;
                    value++;
                }
                index = index + i;
                break;
            }
        }
        if(index>msg.size()-1) break;
    }
    return answer;
}
