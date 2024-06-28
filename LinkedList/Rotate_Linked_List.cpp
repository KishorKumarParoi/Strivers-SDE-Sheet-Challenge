// 🕉️ Jai Siya Ram 🕉️//
/*
Author : @Kishor_Paroi
Github: KishorKumarParoi
Date: 2024-06-29
Time: 14:13:12
Problem: Rotate LinkedList
Link: https://leetcode.com/problems/rotate-list/description/
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
    if (head == NULL) {
        if (k == 1)
            return new Node(val);
        return head;
    }

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

Node<int>* reverseLinkedList(Node<int>* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node<int>* temp = head;
    Node<int>* prev = NULL;
    Node<int>* nextNode = NULL;

    while (temp) {
        nextNode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextNode;
    }

    return prev;
}

Node<int>* reverseKGroup(Node<int>* head, int key) {
    if (head == NULL || head->next == NULL)
        return head;

    Node<int>* temp = head;
    Node<int>* prevHead = NULL;
    Node<int>* nextHead = NULL;
    Node<int>* newHead = NULL;
    Node<int>* startPoint = head;

    while (temp) {
        int limit = key - 1;
        // getting Kth Node by traversing
        while (temp and limit--) {
            temp = temp->next;
        }
        // dl(limit);

        // for incomplete group like 1 2 3 4 if k = 3, then 4 will be only one member
        // for this case return the head as there would be no reverse operation
        if (limit >= 0) {
            // cout << "dsf" << endl;
            return head;
        }

        // pointed to the (k+1)th node for further connection
        nextHead = temp->next;
        // end Point of Kth group
        // disconnect with the later part of linked list for reversing this part
        temp->next = NULL;

        // got new head after reversing Kth group
        newHead = reverseLinkedList(startPoint);
        // cout << "newHead: " << newHead->data << " -> ";
        // printLinkedList(newHead);

        // cout << "temp : " << temp->data << " -> ";
        // printLinkedList(temp);

        if (prevHead == NULL)
            // update head only first time
            head = newHead;

        if (prevHead != NULL)
            prevHead->next = newHead;

        if (nextHead == NULL) {
            return head;
        }

        prevHead = startPoint;

        startPoint->next = nextHead;
        startPoint = startPoint->next;
        temp = startPoint;

        // cout << "head : " << head->data << " -> ";
        // printLinkedList(head);

        // cout << "temp : " << temp->data << " -> ";
        // printLinkedList(temp);

        // cout << "startPoint : " << startPoint->data << " -> ";
        // printLinkedList(startPoint);

        // printLinkedList(head);
    }
    return head;
}


Node<int>* rotateRight(Node<int>* head, int k) {
    if (head == NULL || head->next == NULL)
        return head;

    int length = 0;
    Node<int>* temp = head;
    Node<int>* lastNode = NULL;

    // length of linked list
    while (temp) {
        lastNode = temp;
        temp = temp->next;
        length++;
    }

    // if k % length equals to zero then after rotating Linked List will be same at it was
    if (k % length == 0) {
        return head;
    }

    // update k 
    k = k % length;

    // get back to head again for rotating purpose
    temp = head;

    int rotate = length - k - 1;

    while (rotate--) {
        temp = temp->next;
    }


    // // disconnect the node link and return head 
    Node<int>* newHead = temp->next;
    temp->next = NULL;

    // connect with the last node with first node and made it circular
    lastNode->next = head;

    // cout << "newHead : " << newHead->data << endl;

    return newHead;
}


void solve() {
    int n; cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node<int>* head = LinkedListTraversalFromArray(arr, n);
    // head = reverseLinkedList(head);
    // head = reverseKGroup(head, 5);
    head = rotateRight(head, 4);
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
    // head = insertKthPos(head, 3, 100);
    printLinkedList(head);
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(nullptr));

    // TEST
    solve();

    return 0;
}