// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-04
Time: 20:45:31
Problem: Intersection of Two Sorted Arrays
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

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

vector<int>Intersection(vector<int>a, vector<int>b) {
    // Write your code here
    int n = a.size(), m = b.size(), i = 0, j = 0;
    vector<int>intersectionArr;

    while (i < n && j < m) {
        if (a[i] == b[j]) {
            // if (intersectionArr.size() == 0 || intersectionArr.back() != a[i]) {
            intersectionArr.emplace_back(a[i]);
            // }
            i++;
            j++;
        }
        else if (a[i] > b[j]) {
            j++;
        }
        else {
            i++;
        }

    }

    return intersectionArr;
}


void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    vector<int>res = Intersection(a, b);
    print(res);
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}