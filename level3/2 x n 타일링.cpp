#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> dp(n+1);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        int temp = dp[i-1]+dp[i-2];
        dp[i] = temp%1000000007;
    }
    answer = dp[n];
    return answer;
}
//20220101