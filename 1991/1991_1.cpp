// https://www.acmicpc.net/problem/1991
#include <bits/stdc++.h>
using namespace std;

const int MX = 26;
int lc[MX];
int rc[MX];

void preorder(int cur) {
	cout << (char)(cur+'A');
	if(lc[cur]) preorder(lc[cur]);
	if(rc[cur]) preorder(rc[cur]);
}
void inorder(int cur) {
	if(lc[cur]) inorder(lc[cur]);
	cout << (char)(cur+'A');
	if(rc[cur]) inorder(rc[cur]);
}
void postorder(int cur) {
	if(lc[cur]) postorder(lc[cur]);
	if(rc[cur]) postorder(rc[cur]);
	cout << (char)(cur+'A');
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++) {
        char p, l, r;
        cin >> p >> l >> r;
        if(l != '.') lc[p-'A'] = l-'A';
        if(r != '.') rc[p-'A'] = r-'A';
    }

    preorder(0); cout << '\n';
    inorder(0); cout << '\n';
    postorder(0);
}