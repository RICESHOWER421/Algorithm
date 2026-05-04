#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        int len = 0;
        ListNode* cur = head;
        while (cur->next != nullptr) {
            ++len;
            cur = cur->next;
        }
        cur->next = head;
        ++len;

        k %= len;
        int cnt = len - k;
        while (cnt--) {
            cur = cur->next;
            head = head->next;
        }
        cur->next = nullptr;
        return head;
    }
};

int main() {

	return 0;
}