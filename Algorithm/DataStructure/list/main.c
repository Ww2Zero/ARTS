#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN(a) (sizeof(a) / sizeof(a[0]))

int main(void) {

  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  printf("List:\n");
    ListNode *head = listCreate(a, ARRAY_LEN(a));
  listTraverse(head);

  printf("Del Node 4\n");
  head = listDelNode(head, 4);
  listTraverse(head);

    head = listDelNode(head, 11);
    printf("Del Node 11\n");
  listTraverse(head);

    head = listAddNodeTail(head, 11);
    head = listAddNodeHead(head, 0);
    printf("Add Tail 11, Add Head 0\n");
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
