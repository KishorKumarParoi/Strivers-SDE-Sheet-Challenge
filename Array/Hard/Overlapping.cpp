// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-12
Time: 09:17:15
Problem: Overlapping
Link: https://leetcode.com/problems/merge-intervals/
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

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // (1,3) (2,6) (8,10) (15,18)
    // TC : O(nlogn) + o(n)
    // SC : O(n)
    g
    int n = intervals.size();
    int m = 2;
    sort(intervals.begin(), intervals.end());
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    vector<vector<int>>ans;

    for (int i = 0; i < n; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        if (ans.empty()) {
            ans.push_back({ start, end });
        }
        else {
            if (end <= ans.back()[1])
                continue;
            else {
                if (ans.back()[1] >= start) {
                    ans.back()[1] = end;
                }
                else {
                    ans.push_back({ start, end });
                }
            }
        }
    }

    return ans;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>>arr;

    for (int i = 0; i < n; i++) {
        vector<int>temp;
        int x, y; cin >> x >> y;
        temp.push_back(x);
        temp.push_back(y);
        arr.push_back(temp);
    }

    vector<vector<int>>ans = merge(arr);
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