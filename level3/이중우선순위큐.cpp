#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> v;
    
    for(int i=0;i<operations.size();i++){
        if(operations[i][0]=='I'){
            int num = stoi(operations[i].substr(2));
            v.push_back(num);
            sort(v.begin(), v.end());
        }
        else{ // D인 경우
            if(v.size()>0){
                if(operations[i][2]=='1'){ // 최댓값 삭제
                    v.erase(v.begin()+v.size()-1);
                }
                else{ // 최솟값 삭제
                    v.erase(v.begin());
                }
            }       
        }
    }
    vector<int> answer;
    if(v.size()==0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(v[v.size()-1]);
        answer.push_back(v[0]);
    }
    return answer;
}
//20220102