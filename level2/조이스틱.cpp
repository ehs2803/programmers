// level2
// 성공. 구현. "ABAAAAAAAAABB" - 7 인 예외상황(양방향 이동)
#include <string>
using namespace std;

int solution(string name) {
    int answer=0;
    string initStr="";
    // 위, 아래
    for(int i=0;i<name.size();i++) initStr+="A";
    for(int i=0;i<name.size();i++){
        if(name[i]!=initStr[i]){
            int source=65;
            int dest=int(name[i]);
            answer+=min(dest-source,90-dest+1);
        }
    }
    // 오른쪽, 왼쪽
    if(name[1]=='A'){
        int cnt=0;
        for(int i=1;i<name.size();i++){
            if(name[i]=='A') cnt++;
            else break;
        }
        answer+=(name.size()-1-cnt);
    }
    else{
        if(name[name.size()-1]=='A'){
            int cnt=0;
            for(int i=name.size()-1; i>=1;i--){
                if(name[i]=='A') cnt++;
                else break;
            }
            answer+=(name.size()-1-cnt);
        }
        else{
            int temp1 = (name.size()-1);
            int start_index;
            for(int i=1;i<name.size();i++){
                if(name[i]=='A'){
                    start_index=i;
                    break;
                }
            }
            int cnt=0;
            for(int i=start_index;i<name.size();i++){
                if(name[i]=='A') cnt++;
                else break;
            }
            int temp2 = 2*(start_index-1) + (name.size()-cnt-start_index);
            answer += min(temp1, temp2);
        }
    }

    return answer;
}
/*
정확성  테스트
테스트 1 〉	통과 (0.01ms, 4.26MB)
테스트 2 〉	통과 (0.01ms, 3.68MB)
테스트 3 〉	통과 (0.01ms, 4.24MB)
테스트 4 〉	통과 (0.01ms, 4.33MB)
테스트 5 〉	통과 (0.01ms, 4.31MB)
테스트 6 〉	통과 (0.01ms, 4.25MB)
테스트 7 〉	통과 (0.01ms, 4.25MB)
테스트 8 〉	통과 (0.01ms, 4.32MB)
테스트 9 〉	통과 (0.01ms, 4.32MB)
테스트 10 〉	통과 (0.01ms, 3.68MB)
테스트 11 〉	통과 (0.01ms, 4.26MB)
 */