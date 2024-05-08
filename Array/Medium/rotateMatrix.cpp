// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-08
Time: 17:00:17
Problem: Rotate Matrix
Link: https://leetcode.com/problems/rotate-image/
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define endl "\n"
#define int long long
#define sz(s) (int)s.size()
#define all(v)                            v.begin(),v.end()
#define TEST                              int tc;cin>>tc; while(tc--)
// Debug
#define d(a)                              cout << #a << " : " << a << " ";
#define dl(a)                             cout << #a <<" : " << a << endl;
#define print(v)  for(auto x : v)         {cout<<x<<" ";   }  cout<<endl;
#define PRINT(v)  for(auto x : v)         {cout<<x.first<<" "<<x.second<<endl;}
#define printArr(a,b,arr)                 for(int i=a;i<=b;++i) { cout<<arr[i]<< " ";} cout<<endl;

using namespace std;

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < m; j++) {
            // cout << j << " " << m - i - 1 << " " << matrix[i][j] << endl;
            // ans[j][m - i - 1] = matrix[i][j];
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    cout << "after transpose: " << endl;
    for (auto x : matrix) {
        print(x);
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    for (auto x : matrix) {
        print(x);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>>mat;

    for (int i = 0; i < n; i++) {
        vector<int>v;
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            v.push_back(x);
        }
        mat.push_back(v);
    }

    rotate(mat);
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}