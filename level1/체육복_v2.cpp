#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer += (n-lost.size());

    // �������� ���� 
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // ���� ü������ ������ �л��� ü������ ���������� ��� ��� 
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

    // ���� ���� ���� �л��� �������� �л����� ü���� �����ֱ� 
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
