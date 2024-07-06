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

// class Solution {
//     void combination(vector<int>& candidates, int target, vector<int> currComb,
//         int currSum, int currIndex, vector<vector<int>>& ans) {

//         if (currSum > target) return; //backtrack
//         if (currSum == target) {
//             ans.push_back(currComb); //store the solution and backtrack
//             return;
//         }

//         for (int i = currIndex; i < candidates.size(); i++) { //try all possible options for the next level
//             currComb.push_back(candidates[i]); //put 1 option into the combination
//             currSum += candidates[i];
//             combination(candidates, target, currComb, currSum, i, ans); //try with this combination, whether it gives a solution or not.
//             currComb.pop_back(); //when this option backtrack to here, remove this and go on to the next option.
//             currSum -= candidates[i];
//         }

//     }
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> ans;
//         vector<int> currComb;
//         combination(candidates, target, currComb, 0, 0, ans);
//         return ans;
//     }
// };

vector<vector<int>> printK(int index, int sum, int K, int n, vector<vector<int>>& res, vector<int>& ans, vector<int>& arr) {

    if (sum > K)
        return res;

    if (index > n)
        return res;

    if (index == n) {
        if (sum == K) {
            res.push_back(ans);
        }
        return res;
    }


    sum += arr[index];
    ans.push_back(arr[index]);
    printK(index, sum, K, n, res, ans, arr);

    sum -= arr[index];
    ans.pop_back();
    printK(index + 1, sum, K, n, res, ans, arr);

    return res;
}


void solve() {
    int n; cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int>ans;
    vector<vector<int>>res;
    printK(0, 0, 7, n, res, ans, arr);
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