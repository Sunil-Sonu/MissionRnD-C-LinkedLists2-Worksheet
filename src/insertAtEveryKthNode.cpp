/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	int i=0, j = 0,count=0;
    if (K<0 || head==NULL)
	return NULL;
	else
	{
		struct node *cur = head;
		struct node *next;
		struct node *new_node;
		struct node *traverse = head;
		while (traverse != NULL)
		{
			count++;
			traverse = traverse->next;
		}
		if (count < K)
		{
			return head;
		}
		while (count>0)
		{
			for (i = 1; i < K; i++)
			{
				cur = cur->next;
				count--;
			}
			if (i == K && count>0)
			{
				new_node = (struct node *)malloc(sizeof(struct node));
				new_node->num = K;
				next = cur->next;
				cur->next = new_node;
				new_node->next = next;
				cur = next;
			}
			count--;
		}
		return head;
	}
}
