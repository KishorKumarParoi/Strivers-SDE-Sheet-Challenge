// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-07
Time: 22:19:34
Problem: Set Matrix Zeroes
Link: https://leetcode.com/problems/set-matrix-zeroes/description/
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

vector<vector<int>> setZeroes(vector<vector<int>>& mat) {
    int row = mat.size();
    int col = mat[0].size();

    int col0 = 1;

    d(row) dl(col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] == 0) {
                if (j == 0) {
                    col0 = 0;
                }
                else {
                    mat[0][j] = 0;
                    mat[i][0] = 0;
                }
            }
        }
    }

    // outer portion
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (mat[0][j] == 0 || mat[i][0] == 0) {
                mat[i][j] = 0;
            }
        }
    }

    // first row from left side for corner case
    for (int i = col - 1; i >= 0; i--) {
        if (mat[0][0] == 0) {
            mat[0][i] = 0;
        }
    }

    // first col 

    for (int i = 0; i < row; i++) {
        if (col0 == 0) {
            mat[i][0] = 0;
        }
    }

    return mat;
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

    vector<vector<int>>ans = setZeroes(mat);

    for (auto x : ans) {
        print(x);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}