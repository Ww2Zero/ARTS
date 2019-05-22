#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#define ALEN(a) (sizeof(a) / sizeof(a[0]))

int main(void) {

  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  printf("List:\n");
  ListNode *head = listCreate(a, ALEN(a));
  listTraverse(head);

  printf("Del Node 4\n");
  head = listDelNode(head, 4);
  listTraverse(head);

  head = listDelNode(head, 5);
  head = listAddNodeTail(head, 7);
  printf("Del Node 5, Add Tail 7\n");
  listTraverse(head);

  head = listDelNode(head, 7);
  head = listAddNodeTail(head, 8);
  head = listAddNodeHead(head, 9);
  printf("Del Node 7, Add Tail 8, Add Head 9\n");
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
