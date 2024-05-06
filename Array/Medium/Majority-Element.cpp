// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-06
Time: 11:23:02
Problem: Moo's Voting Algorithm
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

int majorityElement(vector<int> v) {
    // Write your code here
    int cnt = 0, n = v.size(), ele = 0;

    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            ele = v[i];
        }
        if (v[i] == ele) {
            cnt++;
        }
        else {
            cnt--;
        }
    }

    d(ele) dl(cnt);

    int countMaj = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == ele) {
            countMaj++;
        }
    }

    if (countMaj > (n / 2)) {
        return ele;
    }
    return -1;
}

void solve() {
    int n; cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << majorityElement(arr) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}