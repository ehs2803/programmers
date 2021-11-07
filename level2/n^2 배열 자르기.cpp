// level2
// 성공. 규칙찾기
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; i++){
        int divisor = i / n;
        int mod = i % n;
        answer.push_back(divisor < mod ? mod + 1 : divisor + 1);
    }

    return answer;
}
/*
1 2 3
2 2 3
3 3 3

정확성  테스트
테스트 1 〉	통과 (25.49ms, 22.5MB)
테스트 2 〉	통과 (28.26ms, 24.5MB)
테스트 3 〉	통과 (29.79ms, 24.8MB)
테스트 4 〉	통과 (0.03ms, 4.27MB)
테스트 5 〉	통과 (0.02ms, 4.21MB)
테스트 6 〉	통과 (28.09ms, 23MB)
테스트 7 〉	통과 (31.43ms, 24.5MB)
테스트 8 〉	통과 (28.25ms, 22.4MB)
테스트 9 〉	통과 (27.23ms, 23.9MB)
테스트 10 〉	통과 (28.49ms, 23.6MB)
테스트 11 〉	통과 (25.95ms, 23.3MB)
테스트 12 〉	통과 (23.28ms, 20.3MB)
테스트 13 〉	통과 (25.14ms, 22.4MB)
테스트 14 〉	통과 (23.97ms, 21.9MB)
테스트 15 〉	통과 (25.37ms, 21.3MB)
테스트 16 〉	통과 (28.16ms, 22.3MB)
테스트 17 〉	통과 (24.89ms, 22.5MB)
테스트 18 〉	통과 (28.69ms, 24.4MB)
테스트 19 〉	통과 (37.58ms, 23MB)
테스트 20 〉	통과 (22.11ms, 20.7MB)
 */