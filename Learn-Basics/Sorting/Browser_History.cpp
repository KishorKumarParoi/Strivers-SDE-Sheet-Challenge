// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-07-01
Time: 23:55:38
Problem: Browser History
Link: https://www.naukri.com/code360/problems/browser_2427908?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries
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

class Node {
public:
    string data;
    Node* next;
    Node* back;

    Node() {
        this->data = "";
        this->next = NULL;
        this->back = NULL;
    }

    Node(string x) {
        this->data = x;
        this->next = NULL;
        this->back = NULL;
    }

    Node(string x, Node* next1, Node* random) {
        this->data = x;
        this->next = next1;
        this->back = random;
    }

};

class Browser
{
    Node* currentPage;
public:

    Browser(string& homepage)
    {
        currentPage = new Node(homepage);
    }

    void visit(string& url)
    {
        Node* newPage = new Node(url);
        currentPage->next = newPage;
        newPage->back = currentPage;
        currentPage = currentPage->next;
    }

    string back(int steps)
    {
        while (steps) {
            if (currentPage->back) {
                currentPage = currentPage->back;
                steps--;
            }
            else {
                break;
            }
        }
        return currentPage->data;
    }

    string forward(int steps)
    {
        while (steps) {
            if (currentPage->next) {
                currentPage = currentPage->next;
                steps--;
            }
            else {
                break;
            }
        }

        return currentPage->data;
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