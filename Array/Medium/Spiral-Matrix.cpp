// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-08
Time: 18:26:29
Problem: Spiral Way Printing
Link: https://leetcode.com/problems/spiral-matrix/description/
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

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    ios_base::sync_with_stdio(!cin.tie(nullptr));
    int n = matrix.size();
    int m = matrix[0].size();

    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;

    vector<int>ans;

    while (left <= right && top <= bottom) {
        // left to right
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        ++top;

        // top to bottom
        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        --right;


        // right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
        }
        --bottom;

        // bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
        }
        ++left;
    }

    return ans;
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

    vector<int>ans = spiralOrder(mat);

    print(ans);
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}