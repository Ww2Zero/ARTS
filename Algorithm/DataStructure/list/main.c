#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "list.h"

#define ALEN(a) (sizeof(a) / sizeof(a[0]))

/**
 * 链表增减结点测试
 */
int main(void) {
    printf("\nTestListModify\n");
    int a[] = {1, 2, 3, 4, 5, 6};
    printf("Origin List:\n");
    ListNode *head = listCreate(a, ALEN(a));
    listTraverse(head);

    printf("Del Node 3\n");
    head = listDelNode(head, 3);
    listTraverse(head);

    printf("Del Node 1\n");
    head = listDelNode(head, 1);
    listTraverse(head);

    head = listDelNode(head, 6);
    head = listAddNodeTail(head, 7);
    printf("Del Node 6, Add Tail 7\n");
    listTraverse(head);

    head = listDelNode(head, 4);
    head = listAddNodeTail(head, 8);
    head = listAddNodeHead(head, 9);
    printf("Del Node 4, Add Tail 8, Add Head 9\n");
    listTraverse(head);

    head = listDelNodeHead(head);
    printf("Del Head Node\n");
    listTraverse(head);

    head = listDelNodeTail(head);
    printf("Del Tail Node\n");
    listTraverse(head);

    listRelease(head);
    return 0;
}
