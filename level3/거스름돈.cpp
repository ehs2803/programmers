#include<vector>
using namespace std;

long long dp[100001];

int solution(int n, vector<int> money) {
    int answer = 0;
    
    dp[0]=1;//0원을 만드는 경우 1개
    
    for(int i=money[0];i<=n;i+=money[0])// 가장 작은 돈만 써서 만드는 경우들 기본 셋팅
    {
        dp[i]=1;
    }
    
    for(int i=1;i<money.size();i++)//쓰고 싶은 돈
    {
        for(int j=0;j<=n;j++)
        {
            if(j>=money[i]) dp[j] += dp[j-money[i]] % 1000000007;
        }
    }
    answer = dp[n];
    return answer;
}
//20220113