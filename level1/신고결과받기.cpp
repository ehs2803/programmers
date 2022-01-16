// level1
// 성공. 구현, map
#include <string>
#include <vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    unordered_map<string, vector<string>> records;
    unordered_map<string, int> m;
    for(int i=0;i<id_list.size();i++){
        m.insert({id_list[i],0});
    }
    for(int i=0;i<report.size();i++){
        int index=report[i].find(' ');
        string sender = report[i].substr(0, index);
        string receiver = report[i].substr(index+1);
        if(records.find(sender)==records.end()){
            vector<string> temp;
            temp.push_back(receiver);
            records.insert({sender, temp});
            m[receiver]+=1;
        }
        else{
            vector<string> temp = records[sender];
            if(count(temp.begin(), temp.end(), receiver)==0){
                temp.push_back(receiver);
                m[receiver]+=1;
                records[sender]=temp;  
            }

        }
        
    }
    for(int i=0;i<id_list.size();i++){
        if(m[id_list[i]]>=k) m[id_list[i]]= 1;
        else m[id_list[i]]= -1;
        //cout<<id_list[i]<<' '<<m[id_list[i]]<<endl;
    }
    vector<int> answer;
    for(int i=0;i<id_list.size();i++){
        int cnt=0;
        if(records.find(id_list[i])==records.end()){
            answer.push_back(0);
        }
        else{
            vector<string> temp = records[id_list[i]];
            for(int j=0;j<temp.size();j++){
                if(m[temp[j]]==1) cnt++;
            }
            answer.push_back(cnt); 
        }
    }

    return answer;
}
/*
정확성  테스트
테스트 1 〉	통과 (0.03ms, 4.33MB)
테스트 2 〉	통과 (0.05ms, 4.27MB)
테스트 3 〉	통과 (590.06ms, 32.4MB)
테스트 4 〉	통과 (0.08ms, 4.27MB)
테스트 5 〉	통과 (0.05ms, 4.27MB)
테스트 6 〉	통과 (1.52ms, 4.21MB)
테스트 7 〉	통과 (3.83ms, 4.27MB)
테스트 8 〉	통과 (11.54ms, 4.52MB)
테스트 9 〉	통과 (267.08ms, 17.4MB)
테스트 10 〉	통과 (231.87ms, 17.1MB)
테스트 11 〉	통과 (577.80ms, 32.1MB)
테스트 12 〉	통과 (0.36ms, 4.32MB)
테스트 13 〉	통과 (0.25ms, 4.27MB)
테스트 14 〉	통과 (131.66ms, 17MB)
테스트 15 〉	통과 (289.20ms, 29.2MB)
테스트 16 〉	통과 (0.20ms, 4.33MB)
테스트 17 〉	통과 (0.40ms, 4.33MB)
테스트 18 〉	통과 (0.41ms, 4.32MB)
테스트 19 〉	통과 (0.71ms, 3.76MB)
테스트 20 〉	통과 (117.84ms, 17MB)
테스트 21 〉	통과 (303.99ms, 29.1MB)
테스트 22 〉	통과 (0.02ms, 4.32MB)
테스트 23 〉	통과 (0.02ms, 4.33MB)
테스트 24 〉	통과 (0.02ms, 3.75MB)
 */