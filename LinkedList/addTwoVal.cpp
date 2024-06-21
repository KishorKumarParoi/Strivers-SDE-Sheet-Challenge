// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-06-21
Time: 09:37:47
Problem: Add two val
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

void printDoublyLinkedList(Node<int>* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

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

Node<int>* addTwoNumbers(Node<int>* num1Head, Node<int>* num2Head) {
    printDoublyLinkedList(num1Head);
    printDoublyLinkedList(num2Head);

    Node<int>* dummyNode = new Node(-1LL);
    Node<int>* ansHead = dummyNode;
    Node<int>* temp1 = num1Head;
    Node<int>* temp2 = num2Head;
    int carry = 0;
    int sum = 0;

    while (temp1 and temp2) {
        sum = carry + temp1->data + temp2->data;
        dummyNode->next = new Node(sum % 10);
        carry = sum / 10;
        dummyNode = dummyNode->next;

        if (temp1->next == NULL) {
            temp1 = NULL;
            temp2 = temp2->next;
            break;
        }
        if (temp2->next == NULL) {
            temp2 = NULL;
            temp1 = temp1->next;
            break;
        }

        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    // dl(carry);
    // printDoublyLinkedList(ansHead->next);

    while (temp1) {
        sum = carry + temp1->data;
        dummyNode->next = new Node(sum % 10);
        carry = sum / 10;
        dummyNode = dummyNode->next;

        if (temp1->next == NULL)
            break;
        temp1 = temp1->next;
    }

    // printDoublyLinkedList(ansHead->next);

    while (temp2) {
        sum = carry + temp2->data;
        dummyNode->next = new Node(sum % 10);
        carry = sum / 10;
        dummyNode = dummyNode->next;

        if (temp2->next == NULL)
            break;
        temp2 = temp2->next;
    }

    // printDoublyLinkedList(ansHead->next);
    if (carry)
        dummyNode->next = new Node(carry);

    return ansHead->next;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int>arr(n), brr(m);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> brr[i];
    }

    Node<int>* num1Head = convertToDoublyLinkedList(arr, n);
    Node<int>* num2Head = convertToDoublyLinkedList(brr, m);

    Node<int>* sumHead = addTwoNumbers(num1Head, num2Head);
    printDoublyLinkedList(sumHead);
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}