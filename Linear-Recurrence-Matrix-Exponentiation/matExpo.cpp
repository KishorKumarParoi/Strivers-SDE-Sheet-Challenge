// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-07-11
Time: 07:17:11
Problem: Matrix Exponentiation
Link:
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

const int mod = 1e9 + 7;
const int sz = 3;

struct Mat {
    int m[sz][sz];

    Mat() {
        memset(m, 0, sizeof(m));
    }

    void identity() {
        for (int i = 0; i < sz; i++) {
            m[i][i] = 1;
        }
    }

    Mat operator* (Mat a) {
        Mat res;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                for (int k = 0; k < sz; k++) {
                    res.m[i][j] += m[i][k] * a.m[k][j];
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }

};

int Fibosum(int n) {
    // base case
    if (n == -1) return 0;
    if (n == 0) return 0;
    if (n == 1) return 1;

    Mat res;
    res.identity();
    Mat T;
    T.m[0][0] = T.m[0][1] = T.m[0][2] = 1;
    T.m[1][1] = T.m[1][2] = 1;
    T.m[2][1] = 1;

    // n >= 2
    n -= 1;

    // log(n)
    while (n) {
        if (n & 1) res = res * T;
        T = T * T;
        n /= 2;
    }

    return (res.m[0][0] + res.m[0][1]) % mod;
}

void solve() {
    int n, m;
    cin >> n >> m;
    cout << (Fibosum(m) - Fibosum(n - 1) + mod) % mod << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    TEST
        solve();

    return 0;
}