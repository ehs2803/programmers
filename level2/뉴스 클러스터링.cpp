// level2
// 성공. 정수끼리 나눌 때 소수점 얻으려면 (double)해야함, set 자료형, 합집합, 교집합 연산
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    set<string> s1, s2;
    vector<string> v1, v2;
    for(int i=0; i<str1.size()-1;i++){
        string temp = str1.substr(i,2);
        int c1 = int(temp[0]);
        int c2 = int(temp[1]);
        if(65<=c1&&c1<=90 || 97<=c1&&c1<=122){
            if(97<=c1&&c1<=122) temp[0]-=32;
        }
        else continue;
        if(65<=c2&&c2<=90 || 97<=c2&&c2<=122){
            if(97<=c2&&c2<=122) temp[1]-=32;
        }
        else continue;

        s1.insert(temp);
        v1.push_back(temp);
    }

    for(int i=0; i<str2.size()-1;i++){
        string temp = str2.substr(i,2);
        int c1 = int(temp[0]);
        int c2 = int(temp[1]);
        if(65<=c1&&c1<=90 || 97<=c1&&c1<=122){
            if(97<=c1&&c1<=122) temp[0]-=32;
        }
        else continue;
        if(65<=c2&&c2<=90 || 97<=c2&&c2<=122){
            if(97<=c2&&c2<=122) temp[1]-=32;
        }
        else continue;

        s2.insert(temp);
        v2.push_back(temp);
    }

    /*
    for (auto e = s1.begin(); e != s1.end(); e++) { cout << *e << " "; }
    cout<<endl;
    for (auto e = s2.begin(); e != s2.end(); e++) { cout << *e << " "; }
    cout<<endl;
    */
    if(s1.size()==0 && s2.size()==0){
        return 65536;
    }

    vector<string> buffer_union(s1.size()+s2.size());
    auto iter = set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), buffer_union.begin());
    buffer_union.erase(iter, buffer_union.end());

    vector<string> buffer_intersect(s1.size()+s2.size());
    iter = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), buffer_intersect.begin());
    buffer_intersect.erase(iter, buffer_intersect.end());

    int buffer_union_size = buffer_union.size();
    int buffer_intersect_size = buffer_intersect.size();

    for(int i=0;i<buffer_union.size();i++){
        int cnt = max(count(v1.begin(),v1.end(),buffer_union[i]),
                      count(v2.begin(),v2.end(),buffer_union[i]));
        if(cnt!=1){
            buffer_union_size+=(cnt-1);
        }
    }
    for(int i=0;i<buffer_intersect.size();i++){
        int cnt = min(count(v1.begin(),v1.end(),buffer_intersect[i]),
                      count(v2.begin(),v2.end(),buffer_intersect[i]));
        if(cnt!=1){
            buffer_intersect_size+=(cnt-1);
        }
    }
    //cout<<buffer_union_size<<' '<<buffer_intersect_size<<endl;

    double temp = (double)buffer_intersect_size/buffer_union_size;
    //cout<<temp;
    double answer = floor(temp*65536);

    return answer;
}
