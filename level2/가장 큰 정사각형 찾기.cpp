// level2
// 성공. 
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    // row, column size 저장
    int row = board.size();
    int column = board[0].size();

    for(int i=0;i<row-1;i++){
        for(int j=0;j<column-1;j++){
            if(board[i][j]!=0){
                if(board[i][j+1]!=0&&board[i+1][j]!=0&&
                board[i+1][j+1]!=0){
                    board[i+1][j+1]=1+min({board[i][j+1],board[i+1][j],board[i][j]});
                }
            }
        }
    }
/*
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<endl;
    }
    */
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(board[i][j]>answer) answer=board[i][j];
        }
    }

    return answer*answer;
}
/*
정확성  테스트
테스트 1 〉	통과 (0.01ms, 3.67MB)
테스트 2 〉	통과 (0.01ms, 4.33MB)
테스트 3 〉	통과 (0.01ms, 3.69MB)
테스트 4 〉	통과 (0.01ms, 4.26MB)
테스트 5 〉	통과 (0.01ms, 4.27MB)
테스트 6 〉	통과 (0.01ms, 4.26MB)
테스트 7 〉	통과 (0.01ms, 4.33MB)
테스트 8 〉	통과 (0.01ms, 4.33MB)
테스트 9 〉	통과 (0.01ms, 4.26MB)
테스트 10 〉	통과 (0.01ms, 4.32MB)
테스트 11 〉	통과 (0.01ms, 3.68MB)
테스트 12 〉	통과 (0.01ms, 4.28MB)
테스트 13 〉	통과 (0.01ms, 4.33MB)
테스트 14 〉	통과 (0.01ms, 4.34MB)
테스트 15 〉	통과 (0.01ms, 4.34MB)
테스트 16 〉	통과 (0.01ms, 4.26MB)
테스트 17 〉	통과 (0.01ms, 3.62MB)
테스트 18 〉	통과 (0.02ms, 4.33MB)
테스트 19 〉	통과 (0.02ms, 4.31MB)
효율성  테스트
테스트 1 〉	통과 (4.87ms, 38.8MB)
테스트 2 〉	통과 (4.83ms, 38.7MB)
테스트 3 〉	통과 (5.00ms, 38.7MB)
 */
/* 21 11 12 code
#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    // row, column size 저장
    int row = board.size();
    int column = board[0].size();

    // 만들 수 있는 가장 큰 정사각형 길이
    int len = min(row, column);

    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(board[i][j]==1){
                for(int k=len; k>=1; k--){
                    if(i+k-1>=column || j+k-1>=row){
                        continue;
                    }
                    bool check = true;
                    for(int m=i;m<i+k-1;m++){
                        for(int n=j;n<j+k-1;n++){
                            if(board[m][n]==0){
                                check= false;
                                break;
                            }
                        }
                        if(check== false) break;
                    }
                    if(check){
                        if(answer<k) answer=k;
                    }
                }
            }
        }
    }

    return answer*answer;
}
*/

/* 이전코드
#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int row=board.size();
    int col=board[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]==1){
                int count=1;
                int ori_j=j;
                int temp_j=j+1;
                while(1){
                    if(board[i][temp_j]==1){
                        temp_j++;
                        count++;
                    }
                    else break;
                    if(temp_j>=col) break;
                }
                bool check=true;
                for(int k=i;k<i+count-1;k++){
                    for(int m=j;m<j+count-1;m++){
                        if(board[k][m]!=1) {
                            check=false;
                            break;
                        }
                    }
                }
                if(check==true) answer++;
            }
        }
    }

    return answer;
}
 */
