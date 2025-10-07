#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> nums; 
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // brute를 2진수로 나타냈을 때의 값을 가지고 임의의 부분집합을 얻어내고
    // 대응되는 감소하는 수를 nums에 추가
    for(int i = 1; i < 1024; i++){
        int brute = i;
        ll num = 0;
        for(int j = 9; j >= 0; j--){
            if(brute % 2 == 1) 
                num = 10*num + j;
            brute /= 2;
        }
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    int n;
    cin >> n;
    if(n > 1022) cout << -1;
    else cout << nums[n];
}