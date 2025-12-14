// https://www.acmicpc.net/problem/13168
// 내일로 티켓을 사면, 며칠 동안 무궁화호, ITX-새마을, ITX-청춘은 무료로 이용할 수 있으며, S-Train과 V-Train은 50% 할인
#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int n, r, m, k;

vector<string> city_names;
unordered_map<string,int> city_ids;

vector<string> travel_city_names;

int adj1[102][102];
int adj2[102][102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r;
    r *= 2;
    for(int i = 0; i < n; i++) {
        string city_name;
        cin >> city_name;
        city_names.push_back(city_name);
        city_ids[city_name] = i;
    }
    for(int i = 0; i < n; i++) {
        fill(adj1[i],adj1[i]+n,INF);
        adj1[i][i] = 0;
        fill(adj2[i],adj2[i]+n,INF);
        adj2[i][i] = 0;
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        string city_name;
        cin >> city_name;
        travel_city_names.push_back(city_name);
    }

    cin >> k;    
    for(int i = 0; i < k; i++) {
        string type, s, e;
        int cost;
        cin >> type >> s >> e >> cost;
        int u = city_ids[s], v = city_ids[e];
        cost *= 2;

        adj1[v][u] = adj1[u][v] = min(adj1[u][v], cost);

        if(type == "S-Train" || type == "V-Train") 
            cost /= 2;
        else if(type == "Mugunghwa" || type == "ITX-Saemaeul" || type == "ITX-Cheongchun") 
            cost = 0;
        adj2[v][u] = adj2[u][v] = min(adj2[u][v], cost);
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                adj1[i][j] = min(adj1[i][j], adj1[i][k]+adj1[k][j]);
                adj2[i][j] = min(adj2[i][j], adj2[i][k]+adj2[k][j]);
            }
        }
    }

    int tot1 = 0, tot2 = r;
    int u = city_ids[travel_city_names[0]];
    for(string travel_city_name : travel_city_names) {
        int v = city_ids[travel_city_name];
        tot1 += adj1[u][v];
        tot2 += adj2[u][v];
        u = v;
    }

    cout << (tot1 > tot2 ? "Yes" : "No");
}