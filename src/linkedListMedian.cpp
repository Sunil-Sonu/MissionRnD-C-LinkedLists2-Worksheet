/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	int count = 0,median,temp;
	if (head==NULL)
	return -1;
	else
	{
		struct node *cur = head;
		while (cur != NULL)
		{
			count++;
			cur = cur->next;
		}
		temp = count / 2;
		cur = head;
		if (count % 2 == 0)
		{
			while (temp > 1)
			{
				cur = cur->next;
				temp--;
			}
			median = ((cur->num) + (cur->next->num)) / 2;
			return median;
		}
		else
		{
			while (temp > 0)
			{
				cur = cur->next;
				temp--;
			}
			median = cur->num;
			return median;
		}
	}
}
