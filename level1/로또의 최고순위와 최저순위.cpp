#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int low=0, high=0;
    
    for(int i=0;i<lottos.size();i++){
        if(lottos[i]!=0){
            for(int j=0;j<win_nums.size();j++){
                if(lottos[i]==win_nums[j]){
                    low++;
                    break;
                }
            }
        }
        else{
            high++;
        }
    }
    
    high += low;
    
    vector<int> answer;
    
    if(high==6) answer.push_back(1);
    else if(high==5) answer.push_back(2);
    else if(high==4) answer.push_back(3);
    else if(high==3) answer.push_back(4);
    else if(high==2) answer.push_back(5);
    else answer.push_back(6);
    
    if(low==6) answer.push_back(1);
    else if(low==5) answer.push_back(2);
    else if(low==4) answer.push_back(3);
    else if(low==3) answer.push_back(4);
    else if(low==2) answer.push_back(5);
    else answer.push_back(6);
    
    
    
    return answer;
}
