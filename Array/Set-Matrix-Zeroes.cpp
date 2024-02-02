// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-01-29
Time: 21:37:04
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

void OptimizedSetZeroes(vector<vector<int>>& mat) {
    int row = mat.size();
    int col = mat[0].size();
    int col0 = 1;

    // int COL[col] = {0}; mat[0][...]
    // int ROW[row] = {0}; mat[...][0]

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (mat[i][j] == 0) {
                if (j == 0)
                    col0 = 0;
                else
                    mat[0][j] = 0;
                mat[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            if (mat[0][j] == 0 || mat[i][0] == 0) {
                mat[i][j] = 0;
            }
        }
    }

    if (mat[0][0] == 0) {
        for (int j = 0; j < col; ++j) {
            mat[0][j] = 0;
        }
    }

    if (col0 == 0) {
        for (int i = 0; i < row; ++i) {
            mat[i][0] = 0;
        }
    }
}

void setZeroes(vector<vector<int>>& mat) {
    vector<int>rowZero;
    vector<int>colZero;

    int col0 = 1;

    int row = mat.size();
    int col = mat[0].size();

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (mat[i][j] == 0) {
                mat[i][j] = INT_MIN;
                rowZero.push_back(i);
                colZero.push_back(j);
            }
        }
    }

    int rowZeroSize = rowZero.size();
    int colZeroSize = colZero.size();

    // print(rowZero);
    // print(colZero);

    int index = 0;
    while (index < rowZeroSize) {
        for (int i = 0; i < col; ++i) {
            mat[rowZero[index]][i] = 0;
        }
        index++;
    }

    index = 0;
    while (index < colZeroSize) {
        for (int i = 0; i < row; ++i) {
            mat[i][colZero[index]] = 0;
        }
        index++;
    }

    for (int i = 0;i < row;++i) {
        for (int j = 0;j < col;++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    int row, col;
    cin >> row >> col;

    vector<vector<int>>mat(row, vector<int>(col));

    for (int i = 0;i < row;++i) {
        for (int j = 0;j < col;++j) {
            cin >> mat[i][j];
        }
    }

    setZeroes(mat);
}


int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}