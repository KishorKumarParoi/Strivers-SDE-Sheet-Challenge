// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-05
Time: 17:08:57
Problem: Two Sum
Link: https://leetcode.com/problems/two-sum/submissions/1249949109/
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

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(!cin.tie(nullptr));
        unordered_map<int, int>mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (mp.find(target - nums[i]) != mp.end()) {
                return { mp[target - nums[i]], i };
            }
            mp[nums[i]] = i;
        }
        return { -1, -1 };
    }
};

void solve() {

}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}