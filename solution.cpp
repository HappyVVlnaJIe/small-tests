struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* reverseList1(ListNode* head) 
	{

		ListNode* new_head = nullptr; 

		while (head != nullptr)
		{
			ListNode* next = head->next;
			head->next = new_head;
			new_head = head;
			head = next;
		}

		return new_head;
	}

	ListNode* reverseList2(ListNode* head) 
	{
		if (head->next == nullptr)
		{
			return head;
		}
		ListNode* new_head = reverseList2(head->next);
		head->next->next = head;
		head->next = nullptr;

		return new_head;
	}
};
