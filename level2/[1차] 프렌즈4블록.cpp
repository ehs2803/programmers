// level2
// 성공. 구현
#include <string>
#include <vector>
using namespace std;

void setFalse(bool **check, int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            check[i][j]= false;
        }
    }
}

bool IsErase(vector<string> &board, bool **check, int m, int n){
    char sc = board[m][n];
    if(sc=='z') return false;
    if(sc==board[m-1][n] && sc==board[m-1][n+1] &&
        sc==board[m][n+1]){
        check[m-1][n]= true;
        check[m-1][n+1]= true;
        check[m][n+1]= true;
        check[m][n]= true;
        return true;
    }
    else return false;
}

int erase(vector<string> &board, bool **check, int m , int n){
    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(check[i][j]) {
                board[i][j]='z';
                cnt++;
            }
        }
    }
    return cnt;
}

void downBlock(vector<string> &board, int m, int n){
    vector<char> v;
    for(int i=0;i<n;i++){
        for(int j=m-1;j>=0;j--){
            if(board[j][i]!='z'){
                v.push_back(board[j][i]);
            }
        }
        if(v.size()!=0){
            int cnt=m-1;
            for(int j=0;j<v.size();j++){
                board[cnt--][i]=v[j];
            }
            for(int j=cnt; j>=0; j--){
                board[j][i]='z';
            }
        }
        v.clear();
    }
}

int solution(int m, int n, vector<string> board) {
    bool **check = new bool*[m];
    for(int i=0;i<m;i++) check[i] = new bool[n];

    int answer = 0;

    while(1){
        bool checking= false;
        setFalse(check,m,n);
        for(int i=m-1;i>=1;i--){
            for(int j=0;j<n-1;j++){
                bool ch = IsErase(board, check, i, j);
                if(ch== true) checking= true;
            }
        }

        if(checking== false) break;
        answer += erase(board,check,m,n);
        downBlock(board,m,n);
    }
    return answer;
}
