#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *prev, *next;
    Node(int value): value(value), prev(nullptr), next(nullptr) {}
};

int main() {
    int N, K;
    cin >> N >> K;

    // 이중 연결 리스트 생성
    Node* head = new Node(1);
    Node* cur = head;
    for (int i = 2; i <= N; i++) {
        Node* node = new Node(i);
        cur->next = node;
        node->prev = cur;
        cur = node;
    }
    cur->next = head;
    head->prev = cur;

    // 요세푸스 순열 생성
    Node* target = head;
    cout << "<";
    while (N--) {
        for (int i = 0; i < K - 1; i++) {
            target = target->next;
        }
        cout << target->value;
        if (N > 0) cout << ", ";
        target->prev->next = target->next;
        target->next->prev = target->prev;
        Node* temp = target->next;
        delete target;
        target = temp;
    }
    cout << ">";

    return 0;
}