#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(1)д��
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

//ʱ�临�Ӷ�ΪO(N),�ռ临�Ӷ�ΪO(1)��д��
ListNode* mergeNodes(ListNode* head) {
	ListNode* cur = head;		//������
	ListNode* ret = head;		//��¼�ܺ�
	ListNode* prev = head;		//��������

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