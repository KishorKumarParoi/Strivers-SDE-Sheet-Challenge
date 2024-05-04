// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-04
Time: 18:20:50
Problem: Union Of Two Sorted Arrays
Link: https://www.naukri.com/code360/problems/sorted-array_6613259?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
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

vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    int n = a.size(), m = b.size(), i = 0, j = 0;
    vector<int>unionArr;

    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            if (unionArr.size() == 0 || unionArr.back() != a[i]) {
                unionArr.emplace_back(a[i]);
            }
            i++;
        }
        else {
            if (unionArr.size() == 0 || unionArr.back() != b[j]) {
                unionArr.emplace_back(b[j]);
            }
            j++;
        }
    }

    while (i < n) {
        if (unionArr.size() == 0 || unionArr.back() != a[i]) {
            unionArr.emplace_back(a[i]);
        }
        i++;
    }

    while (j < m) {
        if (unionArr.size() == 0 || unionArr.back() != b[j]) {
            unionArr.emplace_back(b[j]);
        }
        j++;
    }

    // print(unionArr);

    return unionArr;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int>arr(n);
    vector<int>brr(m);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> brr[i];
    }

    cout << "Union of two arrays: ";

    vector<int>ans = sortedArray(arr, brr);
    print(ans);
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}