#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
};

ListNode* Process(ListNode* head, int x) {
    ListNode* smallHead = nullptr;
    ListNode* smallTail = nullptr;

    ListNode* bigHead = nullptr;
    ListNode* bigTail = nullptr;

    ListNode* cur = head;

    while (cur != nullptr) {
        ListNode* next = cur->next;
        cur->next = nullptr;

        if (cur->value <= x) {
            if (smallHead == nullptr) {
                smallHead = cur;
                smallTail = cur;
            } else {
                smallTail->next = cur;
                smallTail = cur;
            }
        } else {
            if (bigHead == nullptr) {
                bigHead = cur;
                bigTail = cur;
            } else {
                bigTail->next = cur;
                bigTail = cur;
            }
        }

        cur = next;
    }

    if (smallHead == nullptr) {
        return bigHead;
    }

    smallTail->next = bigHead;
    return smallHead;
}

void PrintList(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        std::cout << cur->value;
        if (cur->next != nullptr) {
            std::cout << ' ';
        }
        cur = cur->next;
    }
    std::cout << '\n';
}

void DeleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    int n;
    std::cin >> n;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;

        ListNode* node = new ListNode;
        node->value = x;
        node->next = nullptr;

        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    int border;
    std::cin >> border;

    head = Process(head, border);

    PrintList(head);
    DeleteList(head);

    return 0;
}
