// level1
// 성공
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    // 더 긴 쪽을 가로로...
    for(int i=0;i<sizes.size();i++){
        if(sizes[i][0]<sizes[i][1]) {
            int temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
    }

    // 가로 최대값 구하기
    int hmax=-1;
    for(int i=0;i<sizes.size();i++){
        if(hmax<sizes[i][0]) hmax = sizes[i][0];
    }

    // 세로 최대값 구하기
    int vmax=-1;
    for(int i=0;i<sizes.size();i++){
        if(vmax<sizes[i][1]) vmax = sizes[i][1];
    }

    int answer = hmax*vmax;
    return answer;
}
/*
테스트 1 〉	통과 (0.01ms, 4.26MB)
테스트 2 〉	통과 (0.01ms, 4.32MB)
테스트 3 〉	통과 (0.01ms, 3.72MB)
테스트 4 〉	통과 (0.01ms, 4.27MB)
테스트 5 〉	통과 (0.01ms, 4.27MB)
테스트 6 〉	통과 (0.01ms, 4.27MB)
테스트 7 〉	통과 (0.01ms, 4.32MB)
테스트 8 〉	통과 (0.01ms, 4.32MB)
테스트 9 〉	통과 (0.01ms, 4.33MB)
테스트 10 〉	통과 (0.02ms, 4.27MB)
테스트 11 〉	통과 (0.02ms, 4.34MB)
테스트 12 〉	통과 (0.03ms, 4.27MB)
테스트 13 〉	통과 (0.07ms, 4.27MB)
테스트 14 〉	통과 (0.22ms, 4.33MB)
테스트 15 〉	통과 (0.24ms, 4.33MB)
테스트 16 〉	통과 (0.34ms, 4.32MB)
테스트 17 〉	통과 (0.50ms, 4.58MB)
테스트 18 〉	통과 (0.58ms, 4.75MB)
테스트 19 〉	통과 (0.59ms, 5MB)
테스트 20 〉	통과 (0.68ms, 5.08MB)
 */