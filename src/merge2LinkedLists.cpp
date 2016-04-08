/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *res = NULL;
	if (head1 == NULL && head2 == NULL)
		return NULL;
	else if (head2 == NULL)
		return head1;
	else if (head1 == NULL)
		return head2;
	else
	{
		if ((head1->num) >= (head2->num))
		{
			res = head2;
			res->next = merge2LinkedLists(head1, head2->next);
		}
		else{
			res = head1;
			res->next = merge2LinkedLists(head1->next, head2);
		}
		return res;
	}
}
