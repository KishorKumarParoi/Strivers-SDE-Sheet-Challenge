// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-07-06
Time: 10:38:35
Problem: All Kind of Pattern in Recursion
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

int printK(int index, int K, int n, vector<int>& ans, vector<int>& arr) {
    if (index > n) {
        return 0;
    }

    int cnt = 0;

    if (index == n) {
        if (ans.empty())
            cout << "{}" << endl;
        else {
            int sum = 0;
            for (int x : ans) {
                sum += x;
                cout << x << " ";
            }
            cout << endl;

            if (sum == K)
                cnt++;
        }
        return cnt;
    }

    ans.push_back(arr[index]);
    cnt += printK(index + 1, K, n, ans, arr);
    ans.pop_back();
    cnt += printK(index + 1, K, n, ans, arr);

    return cnt;
}

int sumEqualsToK(int ind, int sum, int target, vector<int>& arr) {
    // sum > target : break
    // only for positive array elements
    if (sum > target)
        return 0;

    int n = arr.size();
    if (ind > n) {
        return 0;
    }

    // ind reach last element
    if (ind == n) {
        if (sum == target)
            return 1;
        return 0;
    }

    sum += arr[ind];
    // pick next element
    int l = sumEqualsToK(ind + 1, sum, target, arr);

    // removed previous inserted value
    sum -= arr[ind];
    // not pick next element
    int r = sumEqualsToK(ind + 1, sum, target, arr);

    return l + r;
}

void solve() {
    int n; cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int>ans;
    // cout << printK(0, 1, n, ans, arr) << endl;
    cout << sumEqualsToK(0, 0, 1, arr) << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}