#include <iostream>
using namespace std;

// 어떤 문자를 정확히 K개를 포함하는 가장 짧은 연속 문자열의 길이를 구한다.
// 문제 정의
// 같은 문자를 K개 포함하는 가장 짧은 연속된 문자열의 길이
// 문제 풀이
// 첫번째 문자부터 시작해서 해당 문자의 같은 문자가 K개가 될 때까지의 연속된 문자열의 길이를 구한다. 그중 가장 짧은 연속된 문자열의 길이를 구한다.

// 어떤 문자를 정확히 K개를 포함하고, 문자열의 첫 번째와 마지막 글자가 해당 문자로 같은 가장 긴 연속 문자열의 길이를 구한다.
// 문제 정의
// 같은 문자를 K개 포함하고 첫 번째와 마지막 글자가 해당 문자인 가장 긴 연속된 문자열의 길이
// 문제 풀이
// 첫번째 문자부터 시작해서 해당 문자의 같은 문자가 K개가 될 때까지의 연속된 문자열의 길이를 구한다. 그중 가장 긴 연속된 문자열의 길이를 구한다.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string w;
        int k;
        cin >> w >> k;

        int min_ans = 10000, max_ans = 0;
        int l = w.size();
        for(int i = 0; i < l; i++) {
            int cnt = 0;
            for(int j = i; j < l; j++) {
                if(w[i] == w[j]) cnt++;
                if(cnt == k) {
                    min_ans = min(min_ans, j-i+1);
                    max_ans = max(max_ans, j-i+1);
                    break;
                }
            }
        }
        if(max_ans) cout << min_ans << ' ' << max_ans << '\n';
        else cout << "-1\n";
    }
}