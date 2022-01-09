#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;   
    
    sort(times.begin(), times.end());

    long long start = 1;
    long long end = (long long) times[times.size()-1] * n;
    // 탐색 범위(시간) 기준
    long long mid;

    while(start <= end) {
        // 중앙값
        mid = (start + end) / 2;
        // mid 시간동안 심사 처리할 수 있는 모든 사람 수
        long long cnt = 0;

        for(int i = 0; i < times.size(); i++) {
            cnt += mid / times[i];
        }

        if(cnt < n) {
            start = mid + 1;
        }
        else {          
            answer = mid;
            end = mid - 1;
        }
    }
    return answer;
}
//20220109