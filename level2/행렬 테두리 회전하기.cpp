// level2
// 성공. 구현
#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    int **mat = new int*[rows];
    for(int i=0;i<rows;i++){
        mat[i] = new int[columns];
    }
    int n=1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            mat[i][j]=n;
            n++;
        }
    }

    vector<int> answer;
    for(int i=0;i<queries.size();i++){
        int min=999999;

        int sx=queries[i][0]-1;
        int sy=queries[i][1]-1;
        int ex=queries[i][2]-1;
        int ey=queries[i][3]-1;

        vector<int> arr;
        for(int j=sy;j<=ey;j++) arr.push_back(mat[sx][j]);
        for(int j=sx+1;j<=ex;j++) arr.push_back(mat[j][ey]);
        for(int j=ey-1;j>=sy;j--) arr.push_back(mat[ex][j]);
        for(int j=ex-1;j>=sx+1;j--) arr.push_back(mat[j][sy]);

        //for(int j=0;j<arr.size();j++) cout<<arr[j]<<' ';
        arr.insert(arr.begin(),arr[arr.size()-1]);

        int k=0;
        for(int j=sy;j<=ey;j++) mat[sx][j]=arr[k++];
        for(int j=sx+1;j<=ex;j++) mat[j][ey]=arr[k++];
        for(int j=ey-1;j>=sy;j--) mat[ex][j]=arr[k++];
        for(int j=ex-1;j>=sx+1;j--) mat[j][sy]=arr[k++];


        // 최솟값 찾기
        for(int j=sx;j<=ex;j++){
            if(mat[j][sy]<min) min=mat[j][sy];
            if(mat[j][ey]<min) min=mat[j][ey];
        }
        for(int j=sy;j<=ey;j++){
            if(mat[sx][j]<min) min=mat[sx][j];
            if(mat[ex][j]<min) min=mat[ex][j];
        }

        answer.push_back(min);
    }

    return answer;
}
