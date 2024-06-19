// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-06-18
Time: 14:13:12
Problem: LinkedList
Link:
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define endl "\n"
// #define int long long
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

    Node(T data1, Node<T>* next1) {
        this->data = data1;
        this->next = next1;
    }
    Node(T data1) {
        this->data = data1;
        this->next = NULL;
    }
    Node() {
        this->data = 0;
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

void printLinkedList(Node<int>* head) {
    if (head == NULL) {
        return;
    }

    Node<int>* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int LengthOfLinkedList(Node<int>* head) {
    if (head == NULL) {
        return 0;
    }

    Node<int>* temp = head;
    int length = 0;

    while (temp) {
        temp = temp->next;
        length++;
    }
    return length;
}

bool searchElementInLinkedList(Node<int>* head, int target) {
    if (head == NULL) {
        return head;
    }

    Node<int>* temp = head;
    int length = 0;

    while (temp) {
        if (temp->data == target) {
            return true;
        }
        temp = temp->next;
        length++;
    }
    return false;
}


Node<int>* removesHead(Node<int>* head) {
    if (head == NULL) {
        return head;
    }
    Node<int>* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node<int>* removesTail(Node<int>* head) {
    // if there is no element
    if (head == NULL) {
        // cout << "jj" << endl;
        return head;
    }

    //  if there is only one element
    Node<int>* temp = head;
    if (temp->next == NULL) {
        delete temp;   // garbage collection
        return NULL;
    }

    // if there is more than one element
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // freeing memeory
    delete temp->next;

    // standing at before the last element
    // disconnect it from the last element by making it's next pointer null
    temp->next = nullptr;

    // returing new tail
    Node<int>* tail = temp;
    return tail;
}

Node<int>* deleteKthNode(Node<int>* head, int k) {
    if (head == NULL) {
        return head;
    }


    if (k == 1) {
        Node<int>* temp = head;
        head = head->next;
        delete(temp);
        return head;
    }

    Node<int>* temp = head;
    Node<int>* prev = NULL;
    int cnt = 1;

    while (cnt != k) {
        prev = temp;
        if (temp->next != NULL)
            temp = temp->next;
        else
            return head;
        cnt++;
    }

    cout << "prev : " << prev->data << " " << prev->next << endl;
    cout << "temp : " << temp->data << " " << temp->next << endl;

    // bypassing temp
    prev->next = temp->next;
    free(temp);

    return head;
}

Node<int>* deleteElement(Node<int>* head, int target) {
    if (head == NULL) {
        return head;
    }

    // if target is the first element
    if (head->data == target) {
        Node<int>* temp = head;
        head = head->next;
        delete temp;
        cout << "head: " << head->data << " " << head->next << " " << head << endl;
        return head;
    }

    Node<int>* temp = head;
    Node<int>* prev = NULL;

    while (temp) {
        if (temp->data != target) {
            prev = temp;
            temp = temp->next;
        }
        else {
            break;
        }
        // cout << "prev: " << prev->data << " " << prev->next << endl;
        // cout << "temp: " << temp->data << " " << temp->next << endl;
    }

    if (temp->data == target) {
        // cout << "prev: " << prev->data << " " << prev->next << endl;
        prev->next = temp->next;
        // cout << "temp: " << temp->data << " " << temp->next << endl;
        delete temp;
    }
    return head;
}

Node<int>* insertKthPos(Node<int>* head, int k, int val) {
    if (k == 1) {
        Node<int>* temp = new Node(val);
        temp->next = head;
        head = temp;
        return head;
    }

    int cnt = 1;
    Node<int>* temp = head;
    Node<int>* prev = NULL;

    while (cnt != k) {
        if (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        else {
            break;
        }
    }

    // k is greater than length of linked list
    if (k > cnt) {
        d(cnt) dl(k);
        if (cnt + 1 == k) {
            temp->next = new Node(val);
            return head;
        }
        else {
            return head;
        }
    }

    prev->next = new Node(val, temp);
    return head;
}


void solve() {
    int n; cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node<int>* head = LinkedListTraversalFromArray(arr, n);
    // cout << head << endl;
    // head = removesHead(head);
    // cout << head << endl;
    // Node<int>* tail = removesTail(head);
    // cout << "tail : " << tail->data << endl;
    // printLinkedList(head);
    // cout << LengthOfLinkedList(head) << endl;
    // cout << searchElementInLinkedList(head, 1) << endl;
    // head = deleteKthNode(head, 30);
    // head = deleteElement(head, 3);
    head = insertKthPos(head, 3, 100);
    printLinkedList(head);
    head = insertKthPos(head, 1, 100);
    printLinkedList(head);
    head = insertKthPos(head, 5, 100);
    printLinkedList(head);
    head = insertKthPos(head, 7, 100);
    printLinkedList(head);
    head = insertKthPos(head, 9, 100);
    printLinkedList(head);
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}