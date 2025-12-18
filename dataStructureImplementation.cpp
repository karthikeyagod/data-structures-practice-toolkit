#include <bits/stdc++.h>
using namespace std;

/* ---------- STACK ---------- */
class Stack {
    vector<int> st;
public:
    void push(int x) {
        st.push_back(x);
        cout << "Pushed " << x << " into stack\n";
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Popped " << st.back() << " from stack\n";
        st.pop_back();
    }

    void display() {
        if (st.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int x : st) cout << x << " ";
        cout << endl;
    }
};

/* ---------- QUEUE ---------- */
class QueueDS {
    queue<int> q;
public:
    void enqueue(int x) {
        q.push(x);
        cout << "Enqueued " << x << " into queue\n";
    }

    void dequeue() {
        if (q.empty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Dequeued " << q.front() << " from queue\n";
        q.pop();
    }

    void display() {
        if (q.empty()) {
            cout << "Queue is empty\n";
            return;
        }
        queue<int> temp = q;
        cout << "Queue elements: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

/* ---------- LINKED LIST ---------- */
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    void insert(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        if (!head) {
            cout << "Linked list is empty\n";
            return;
        }
        Node* temp = head;
        cout << "Linked list: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

/* ---------- SORTING & SEARCHING ---------- */
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int binarySearch(vector<int>& arr, int key) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

/* ---------- MAIN ---------- */
int main() {
    Stack st;
    QueueDS q;
    LinkedList ll;
    vector<int> arr;

    int choice;
    do {
        cout << "\n--- Data Structures Practice Toolkit ---\n";
        cout << "1. Stack\n";
        cout << "2. Queue\n";
        cout << "3. Linked List\n";
        cout << "4. Sorting & Searching\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int op, x;
            cout << "1. Push  2. Pop  3. Display\n";
            cin >> op;
            if (op == 1) {
                cout << "Enter value: ";
                cin >> x;
                st.push(x);
            } else if (op == 2) {
                st.pop();
            } else if (op == 3) {
                st.display();
            }
        }

        else if (choice == 2) {
            int op, x;
            cout << "1. Enqueue  2. Dequeue  3. Display\n";
            cin >> op;
            if (op == 1) {
                cout << "Enter value: ";
                cin >> x;
                q.enqueue(x);
            } else if (op == 2) {
                q.dequeue();
            } else if (op == 3) {
                q.display();
            }
        }

        else if (choice == 3) {
            int op, x;
            cout << "1. Insert  2. Display\n";
            cin >> op;
            if (op == 1) {
                cout << "Enter value: ";
                cin >> x;
                ll.insert(x);
            } else if (op == 2) {
                ll.display();
            }
        }

        else if (choice == 4) {
            int n;
            cout << "Enter number of elements: ";
            cin >> n;
            arr.resize(n);
            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];

            bubbleSort(arr);
            cout << "Sorted array: ";
            for (int x : arr) cout << x << " ";
            cout << endl;

            int key;
            cout << "Enter element to search: ";
            cin >> key;
            int idx = binarySearch(arr, key);
            if (idx != -1)
                cout << "Element found at index " << idx << endl;
            else
                cout << "Element not found\n";
        }

    } while (choice != 0);

    return 0;
}
