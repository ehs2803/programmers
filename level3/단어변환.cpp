#include <string>
#include <vector>

using namespace std;
int answer = 100;
bool check[51];

void dfs(string begin, string target, vector<string> & words, int cnt){
    if(begin==target){
        answer = min(answer, cnt);
        return;
    }
    
    for(int i=0;i<words.size();i++){
       if(check[i]==false){
            int dcount=0;
            for(int j=0;j<words[i].size();j++){
                if(words[i][j]!=begin[j]) dcount++;
                if(dcount==2) break;
            }
            if(dcount==1){
                if(check[i]==false){
                    check[i]=true;
                    dfs(words[i], target, words, cnt+1);
                    check[i]=false;
                }
               
            }
        }
    }
    
}


int solution(string begin, string target, vector<string> words) {
    fill(check, check+50, false);
    
    dfs(begin, target, words, 0);
    
    if(answer==100) answer=0;
    return answer;
}
//20220108