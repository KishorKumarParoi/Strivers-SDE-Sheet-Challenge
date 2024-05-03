// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-03
Time: 16:47:18
Problem: Second Largest Smallest Finding
Link: https://www.naukri.com/code360/problems/ninja-and-the-second-order-elements_6581960?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
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

vector<int> getSecondOrderElements(int n, vector<int> arr) {
    int ssmallest = INT_MAX;
    int slargest = INT_MIN;
    int largest = INT_MIN;
    int smallest = INT_MAX;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > largest) {
            slargest = largest;
            largest = arr[i];
        }
        if (arr[i] > slargest && arr[i] != largest) {
            slargest = arr[i];
        }

        if (arr[i] < smallest) {
            ssmallest = smallest;
            smallest = arr[i];
        }
        if (arr[i] < ssmallest && arr[i] != smallest) {
            ssmallest = arr[i];
        }

        d(largest) d(slargest) d(smallest) dl(ssmallest)
    }

    return { slargest, ssmallest };
}

void solve() {
    int n; cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int>res = getSecondOrderElements(n, arr);
    print(res);
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}