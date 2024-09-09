#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//时间复杂度O(N),空间复杂度O(1)写法
//ListNode* mergeNodes(ListNode* head) {
//    ListNode* ret = new ListNode();
//    ListNode* cur = head;
//    ListNode* ans = ret;
//
//    int sum = 0;
//    while (cur != nullptr) {
//        if (cur->val == 0) {
//            if (sum) {
//                ListNode* temp = new ListNode(sum);
//                ans->next = temp;
//                ans = ans->next;
//            }
//            sum = 0;
//        }
//        else sum += cur->val;
//        cur = cur->next;
//    }
//    return ret->next;
//}

//时间复杂度为O(N),空间复杂度为O(1)的写法
ListNode* mergeNodes(ListNode* head) {
	ListNode* cur = head;		//遍历用
	ListNode* ret = head;		//记录总和
	ListNode* prev = head;		//修正链表

	int temp = 0;
	while (cur != nullptr) {
		if (cur->val == 0) temp = 0;
		else {
			if (!temp) {
				temp = 1;
				ret = cur;
				prev->next = ret;
				prev = prev->next;
			}
			else ret->val += cur->val;
		}
		cur = cur->next;
	}
	prev->next = nullptr;
	return head->next;
}

int main() {
    
	return 0;
}