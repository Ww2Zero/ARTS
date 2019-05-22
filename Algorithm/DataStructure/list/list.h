#ifndef __ASLIST_H__
#define __ASLIST_H__

#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

typedef struct ListNode {
    int value;
    struct ListNode *next;
} ListNode;

ListNode *listNewNode(int value);

ListNode *listCreate(int array[], int len);

ListNode *listAddNodeHead(ListNode *head, int value);

ListNode *listAddNodeTail(ListNode *head, int value);

ListNode *listDelNodeHead(ListNode *head);

ListNode *listDelNodeTail(ListNode *head);

ListNode *listDelNode(ListNode *head, int value);

int listLength(ListNode *head);

void listRelease(ListNode *head);

void listTraverse(ListNode *head);

#endif