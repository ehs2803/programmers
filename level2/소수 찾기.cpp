// level2
// 성공. 조합, 에라토스테네스의 체.
#include <string>
#include <vector>
#include<cmath>
#include<algorithm>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    // 에라토스테네스의 체
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> nums;
    vector<int> unique_nums;

    for(int i=0;i<numbers.size();i++) nums.push_back(numbers[i]);
    sort(nums.begin(), nums.end());
    do {
        string temp = "";
        for (int i = 0; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            unique_nums.push_back(stoi(temp));
        }
    } while (next_permutation(nums.begin(), nums.end()));

    sort(unique_nums.begin(), unique_nums.end());
    unique_nums.erase(unique(unique_nums.begin(), unique_nums.end()), unique_nums.end());
    for (int i = 0; i < unique_nums.size(); i++) if (isPrime(unique_nums[i])) answer++;

    return answer;
}