// level2
// 성공. 모든 경우의 수 - 순열
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 최소피로도, 소모피로도
int solution(int k, vector<vector<int>> dungeons) {
    vector<int> v;
    for (int i = 0; i <dungeons.size(); i++) v.push_back(i);

    int maxCnt= 0;

    do {
        int remainK = k;
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            int demandHealth = dungeons[v[i]][0];
            int usedHealth = dungeons[v[i]][1];
            if (demandHealth > remainK) continue;
            remainK -= usedHealth;
            cnt++;
        }
        maxCnt = max(maxCnt, cnt);
    } while (next_permutation(v.begin(), v.end()));
    return maxCnt;
}
/*
정확성  테스트
테스트 1 〉	통과 (0.01ms, 4.27MB)
테스트 2 〉	통과 (0.01ms, 3.77MB)
테스트 3 〉	통과 (0.01ms, 4.33MB)
테스트 4 〉	통과 (0.01ms, 4.33MB)
테스트 5 〉	통과 (0.02ms, 4.33MB)
테스트 6 〉	통과 (0.05ms, 4.26MB)
테스트 7 〉	통과 (0.42ms, 4.33MB)
테스트 8 〉	통과 (0.43ms, 4.26MB)
테스트 9 〉	통과 (0.01ms, 3.73MB)
테스트 10 〉	통과 (0.05ms, 4.33MB)
테스트 11 〉	통과 (0.01ms, 4.32MB)
테스트 12 〉	통과 (0.59ms, 3.62MB)
테스트 13 〉	통과 (0.66ms, 4.26MB)
테스트 14 〉	통과 (0.57ms, 4.32MB)
테스트 15 〉	통과 (0.37ms, 4.32MB)
테스트 16 〉	통과 (0.06ms, 3.66MB)
테스트 17 〉	통과 (0.63ms, 4.27MB)
 */
