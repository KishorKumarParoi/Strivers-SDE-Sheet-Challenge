// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-09
Time: 22:45:36
Problem: Three Sum
Link: https://leetcode.com/problems/3sum/
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

vector<vector<int>> threeSum(vector<int>& nums) {
    ios_base::sync_with_stdio(!cin.tie(nullptr));
    vector<vector<int>>res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    // print(nums);

    // nums[i] + nums[j] + nums[k] = 0
    // -2 -2 -2 -1 -1 0 0 1 1 2 2
    //  i  j                    k
    //  i       j               k
    //  i                   j   k
    //  i                   j k
    //  i                   j/k

    for (int i = 0; i < n; i++) {
        // removing duplicates
        if (i != 0 and nums[i] == nums[i - 1])
            continue;

        int j = i + 1, k = n - 1;

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int>temp = { nums[i], nums[j], nums[k] };
                res.push_back(temp);
                j++;
                k--;

                // skip the duplicates
                while (j < k and nums[j] == nums[j - 1]) {
                    j++;
                }
                while (j < k and nums[k] == nums[k + 1]) {
                    k--;
                }
            }

        }
    }

    return res;
}

void solve() {
    int n; cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>>ans = threeSum(arr);
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