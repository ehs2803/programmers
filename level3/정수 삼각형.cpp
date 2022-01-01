#include <string>
#include <vector>
using namespace std;
int dp[500][500];

int solution(vector<vector<int>> triangle) {
    dp[0][0] = triangle[0][0];
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            if(j==0){
                dp[i][j]=triangle[i][j]+dp[i-1][0];
            }
            else if(j==triangle[i].size()-1){
                dp[i][j] = triangle[i][j]+dp[i-1][j-1];
            }
            else{
                dp[i][j] = triangle[i][j]+max(dp[i-1][j-1],dp[i-1][j]);
            }
        }
    }
    int answer = 0;
    for(int i=0;i<triangle[triangle.size()-1].size();i++){
        answer = max(answer, dp[triangle.size()-1][i]);
    }
    return answer;
}
//20220101