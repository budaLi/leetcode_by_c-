// leetcode_by_c++.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

//定义一个ListNode的结构体
struct ListNode {
	//存储node的值
	int val;
	//node的下一个节点
	ListNode *next;
	//无参构造函数 默认值为0，next为null
	ListNode():val(0),next(nullptr){}
	//一个参数 值为x 
	ListNode(int x):val(x),next(nullptr){}
	//两个参数 第一个为值 第二个为next
	ListNode(int x,ListNode *next):val(x),next(next){}
};
class Solution {
public :
	// 分析 两个数的位数对应相加要考虑进位  比如 19+17   9+7=16 产生进位
	//几种比较特殊的情况 
	//1 两个链表长度不相等 或者其中一个为空 
	//2 用什么数据结构存储返回结果 99+1 =100  产生多的位数 
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//定义一个新的链表
		ListNode *dummyHead = new ListNode(0);
		ListNode *p = l1, *q = l2, *cur = dummyHead;
		//定义进位
		int carry = 0;
		while (p!=NULL||q!=NULL)
		{
			//获取p 和q的值
			int x = (p != NULL) ? p->val : 0;
			int y = (q != NULL) ? q->val : 0;
			int sum = carry + x + y;
			carry = sum / 10;
			cur->next = new ListNode(sum % 10);
			cur = cur->next;
			if (p != NULL) p = p->next;
			if (q != NULL) q = q->next;

		}
		if (carry > 0) {
			cur->next = new ListNode(carry);

		}
		return dummyHead->next;

	}
};

int main(int argc, char* args[]) {
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	Solution solution;
	ListNode* result = solution.addTwoNumbers(l1, l2);
		while (result!=NULL)
		{
			cout << result->val << endl;
				result = result->next;
		}

}