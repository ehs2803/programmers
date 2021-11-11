// level2
// 성공. 구현.
#include <string>
#include <vector>
using namespace std;

bool check[1000][1000];
int map[1000][1000];
int dirx[] ={-1,0,1};
int diry[] ={-1,1,0};

vector<int> solution(int n) {
    vector<int> answer;
    int num=0; // 숫자

    // 초기 설정 (ㄴ)
    for(int i=0;i<n;i++){
        num++;
        map[0][i]=num;
        check[0][i]= true;
    }
    for (int i = 0; i < n-1; ++i) {
        num++;
        map[i+1][n-1]=num;
        check[i+1][n-1]=num;
    }

    int direction = 1;
    int cx = n-1, cy=n-1;
    int cnt_fail=0;
    while(1){
        // 범위를 벗어나는 경우 break
        if(direction==1){
            if(cx-1<0 || cy-1<0) break;
        }
        else if(direction==2){
            if(cy+1>=n) break;
        }
        else if(direction==3){
            if(cx+1>=n) break;
        }

        // 이미 입력된 배열이라면 방향바꾸기
        if(check[cx+dirx[direction-1]][cy+diry[direction-1]]){
            if(direction==3) direction=1;
            else direction++;

            // 실패횟수가 3이면 break
            cnt_fail++;
            if(cnt_fail==3) break;
        }
        else{ // 배열에 값 입력
            cx=cx+dirx[direction-1];
            cy=cy+diry[direction-1];
            cnt_fail=0;
            num++;
            map[cx][cy]=num;
            check[cx][cy]= true;
        }
    }

    // 정답 number 저장
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            answer.push_back(map[j][i]);
        }
    }
    return answer;
}
/*
정확성  테스트
테스트 1 〉	통과 (0.01ms, 4.26MB)
테스트 2 〉	통과 (0.02ms, 4.34MB)
테스트 3 〉	통과 (0.02ms, 4.32MB)
테스트 4 〉	통과 (1.38ms, 5.27MB)
테스트 5 〉	통과 (1.43ms, 5.21MB)
테스트 6 〉	통과 (1.50ms, 5.16MB)
테스트 7 〉	통과 (170.35ms, 113MB)
테스트 8 〉	통과 (175.84ms, 114MB)
테스트 9 〉	통과 (161.29ms, 114MB)
 */