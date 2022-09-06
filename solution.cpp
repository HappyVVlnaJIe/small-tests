#include <iostream>
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

bool isPalindrome(int x) {
	if (x < 0)
	{
		return false;
	}
	if (x < 10)
	{
		return true;
	}
	int temp = 1;
	while (temp < x)
	{
		temp *= 10;
	}
	int res = 0;
	while (temp > 0)
	{
		res += temp * (x / temp);
		temp /= 10;
	}
	if (res == x)
	{
		return true;
	}
	return false;
}
