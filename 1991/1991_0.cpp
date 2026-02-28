#include <bits/stdc++.h>
using namespace std;
int n;
int lc[27];
int rc[27];

void preorder(int cur) {
    cout << (char)(cur-1+'A');
    if(lc[cur])preorder(lc[cur]);
    if(rc[cur])preorder(rc[cur]);
}
void inorder(int cur) {
    if(lc[cur])inorder(lc[cur]);
    cout << (char)(cur-1+'A');
    if(rc[cur])inorder(rc[cur]);
}
void postorder(int cur) {
    if(lc[cur])postorder(lc[cur]);
    if(rc[cur])postorder(rc[cur]);
    cout << (char)(cur-1+'A');
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i = 0; i < n-1; i++) {
        char p,l,r;
        cin >> p >> l >> r;
        if(l != '.')lc[p-'A'+1] = l-'A'+1;
        if(r != '.')rc[p-'A'+1] = r-'A'+1;
    }

    preorder(1); cout << '\n';
    inorder(1); cout << '\n';
    postorder(1); cout << '\n';
}