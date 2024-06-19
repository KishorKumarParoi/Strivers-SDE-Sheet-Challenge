// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-06-19
Time: 23:54:47
Problem: Doubly Linked List
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

template <typename T>

class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

public:
    Node(T data1, Node<T>* next1, Node<T>* prev1) {
        this->data = data1;
        this->next = next1;
        this->prev = prev1;
    }
    Node(T data1, Node<T>* next1) {
        this->data = data1;
        this->next = next1;
        this->prev = nullptr;
    }
    Node(T data1, nullptr_t, Node<T>* prev1) {
        this->data = data1;
        this->next = nullptr;
        this->prev = prev1;
    }
    Node(T data1) {
        this->data = data1;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node() {
        this->data = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }

};

Node<int>* convertToDoublyLinkedList(vector<int>& arr, int n) {
    Node<int>* head = new Node(arr[0]);
    Node<int>* prev = head;

    for (int i = 1; i < n; i++) {
        Node<int>* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void printDoublyLinkedList(Node<int>* head) {
    cout << head->data << " " << head->next << endl;

    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void solve() {
    int n; cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node<int>* head = convertToDoublyLinkedList(arr, n);
    printDoublyLinkedList(head);
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}