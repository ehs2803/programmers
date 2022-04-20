#include <string>
#include <vector>
#include<unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    for(int i=0;i<participant.size();i++){
        if(m.find(participant[i])!=m.end()){
            m[participant[i]]+=1;
        }
        else{
            m[participant[i]]=1;
        }
    }

    for(int i=0;i<completion.size();i++){
        if(m.find(completion[i])!=m.end()){
            m[completion[i]]-=1;
            if(m[completion[i]]==0){
                m.erase(completion[i]);
            }
        }
    }

    string answer = "";
    for (auto iter = m.begin() ; iter != m.end(); iter++) { 
        if(iter->second==1){
            answer = iter->first;
        } 
    } 

    return answer;
}
