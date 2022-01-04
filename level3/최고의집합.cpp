#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int div = s/n;
    int rest = s%n;
    if(div==0) answer.push_back(-1);
    else{
        if(rest>0){
            for(int i=0;i<n-rest;i++) answer.push_back(div);
            for(int i=0;i<rest;i++) answer.push_back(div+1);
        }
        else if(rest==0){
            for(int i=0;i<n;i++) answer.push_back(div);
        }
    }
    return answer;
}
//20220103