#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer += (n-lost.size());

    // 오름차순 정렬 
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // 여벌 체육복을 가져온 학생이 체육복을 도난당했을 경우 고려 
    for(int i=0;i<lost.size();i++){
        for(int j=0;j<reserve.size();j++){
            if(lost[i]==reserve[j]){
                answer++;
                reserve.erase(reserve.begin()+j);
                lost[i]=-1;
                break;
            }
        }
    }

    // 여벌 옷을 가진 학생이 도난당한 학생에게 체육복 빌려주기 
    for(int i=0;i<lost.size();i++){
        if(lost[i]!=-1){
            for(int j=0;j<reserve.size();j++){
                if(abs(lost[i]-reserve[j])==1){
                    answer++;
                    reserve.erase(reserve.begin()+j);
                    break;
                }
            }
        }

    }

    return answer;
}
