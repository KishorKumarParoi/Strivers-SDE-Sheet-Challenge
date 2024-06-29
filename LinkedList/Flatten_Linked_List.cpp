// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-06-29
Time: 12:20:55
Problem: Flatten A Linked List
Link: https://www.naukri.com/code360/problems/flatten-a-linked-list_1112655?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries
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

template<typename T>

class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* child;

    Node(T data1, Node<T>* child1, Node<T>* next1) {
        this->data = data1;
        this->child = child1;
        this->next = next1;
    }
    Node(T data1) {
        this->data = data1;
        this->child = NULL;
        this->next = NULL;
    }
    Node() {
        this->data = 0;
        this->child = NULL;
        this->next = NULL;
    }
};


Node<int>* LinkedListTraversalFromArray(vector<int>& arr, int n) {
    Node<int>* head = new Node(arr[0]);
    Node<int>* mover = head;

    for (int i = 1; i < n; i++) {
        Node<int>* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
Node<int>* VerticalLinkedListTraversalFromArray(vector<int>& arr, int n) {
    Node<int>* head = new Node(arr[0]);
    Node<int>* mover = head;

    for (int i = 1; i < n; i++) {
        Node<int>* temp = new Node(arr[i]);
        mover->child = temp;
        mover->next = NULL;
        mover = temp;
    }
    return head;
}

void printLinkedListChild(Node<int>* head) {
    if (head == NULL) {
        return;
    }

    Node<int>* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->child;
    }
    cout << endl;
}

void printLinkedList(Node<int>* head) {
    if (head == NULL) {
        return;
    }

    Node<int>* temp = head;
    while (temp) {
        cout << temp->data << " : ";
        printLinkedListChild(temp);
        temp = temp->next;
    }
    cout << endl;
}

Node<int>* mergeTwoLists(Node<int>* first, Node<int>* second) {
    Node<int>* temp = new Node<int>(-1LL);
    Node<int>* head = temp;

    while (first and second) {
        if (first->data < second->data) {
            temp->next = first;
            first = first->child;
        }
        else {
            temp->next = second;
            second = second->child;
        }

        temp = temp->next;
    }

    while (first) {
        temp->next = first;
        first = first->child;
        temp = temp->next;
    }

    while (second) {
        temp->next = second;
        second = second->child;
        temp = temp->next;
    }

    return head->next;
}

Node<int>* verticalMergeTwoLists(Node<int>* first, Node<int>* second) {
    Node<int>* temp = new Node(-1LL);
    Node<int>* head = temp;

    while (first and second) {
        if (first->data < second->data) {
            temp->child = first;
            first = first->child;
        }
        else {
            temp->child = second;
            second = second->child;
        }

        temp = temp->child;
        temp->next = nullptr;
    }

    if (first) {
        temp->child = first;
        // first = first->next;
        // temp = temp->next;
    }

    if (second) {
        temp->child = second;
        // second = second->next;
        // temp = temp->next;
    }

    if (head->child) head->child->next = nullptr;

    return head->child;
}

Node<int>* flattenLinkedList(Node<int>* head) {
    // edge case
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node<int>* mergeHead = flattenLinkedList(head->next);

    return mergeTwoLists(head, mergeHead);
}

void solve() {
    int n; cin >> n;
    Node<int>* dummy = new Node<int>(-1LL);
    Node<int>* start = dummy;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int>arr(m);
        cin >> arr[0];

        Node<int>* head = new Node<int>(arr[0]);
        Node<int>* temp = head;


        for (int j = 1; j < m; j++) {
            cin >> arr[j];
            temp->child = new Node<int>(arr[j]);
            temp = temp->child;
            // cout << temp->data << " " << temp->child << " " << temp->next << endl;
        }

        // printLinkedListChild(head);

        dummy->next = head;
        dummy = dummy->next;
    }

    // printLinkedList(start->next);

    Node<int>* ansHead = flattenLinkedList(start->next);
    Node<int>* temp = ansHead;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    // printLinkedList(ansHead);
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}