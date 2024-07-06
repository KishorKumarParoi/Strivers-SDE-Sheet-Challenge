// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-07-06
Time: 13:44:59
Problem: Combination Sum I
Link: https://leetcode.com/problems/combination-sum/description/
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

void printK(int index, int sum, int K, int n, vector<vector<int>>& res, vector<int>& ans, vector<int>& arr) {
    // if sum > K break the code
    if (sum > K)
        return;
    // if index geos bigger than n then return
    if (index > n)
        return;

    // if index == n then maybe sum equal to target(K) value
    if (index == n) {
        if (sum == K) {
            res.push_back(ans);
        }
        return;
    }

    // pick same element
    sum += arr[index];
    ans.push_back(arr[index]);
    printK(index, sum, K, n, res, ans, arr);

    // not pick same element and move to next element
    sum -= arr[index];
    ans.pop_back();
    printK(index + 1, sum, K, n, res, ans, arr);

    // if none found return
    return;
}

// TC : 2^(t) * K (t is greater than n as same element can be picked or not picked many times)
// K -> Array size for operation 
// SC : K * X (size of combination) hypothetical

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int>ans;
    vector<vector<int>>res;
    printK(0, 0, target, candidates.size(), res, ans, candidates);
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>>res = combinationSum(arr, 7);
    // printK(0, 0, 7, n, res, ans, arr);
    cout << "Ans : " << res.size() << endl;

    for (auto x : res) {
        print(x);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}