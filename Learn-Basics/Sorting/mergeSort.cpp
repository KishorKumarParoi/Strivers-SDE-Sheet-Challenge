// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-05-03
Time: 00:07:58
Problem: Merge Sort
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

void merge(vector<int>& arr, int low, int mid, int high) {
    int left = low, right = mid + 1;
    vector<int>temp;

    while (left <= mid and right <= high) {
        if (arr[left] > arr[right]) {
            temp.emplace_back(arr[right]);
            right++;
        }
        else {
            temp.emplace_back(arr[left]);
            left++;
        }
    }

    while (left <= mid) {
        temp.emplace_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.emplace_back(arr[right]);
        right++;
    }

    // updating array

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void ms(vector<int>& arr, int low, int high) {
    int mid = (low + high) / 2;

    if (low == high) return;
    ms(arr, low, mid);
    ms(arr, mid + 1, high);
    merge(arr, low, mid, high);

}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ms(arr, 0, n - 1);
    print(arr);
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}