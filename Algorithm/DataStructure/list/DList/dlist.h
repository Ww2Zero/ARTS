#ifndef ZERO_DLIST_H
#define ZERO_DLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct DListNode {
    struct DListNode *prev;
    struct DListNode *next;
    void *value;
} DListNode;


typedef struct DList {
    DListNode *head; // 链表头节点
    DListNode *tail; // 链表尾节点
    unsigned long len; // 链表长度

    void *(*dup)(void *ptr); // 节点复制函数

    void (*free)(void *ptr); // 节点释放函数

    int (*match)(void *ptr, void *key); // 节点匹配函数
} DList;

// 从头向后遍历
#define ITER_START_HEAD 0
// 从后向头遍历
#define ITER_START_TAIL 1

typedef struct DListIter {
    DListNode *next;
    int direction;
} DListIter;

#define listSetDupMethod(l, m) ((l)->dup = (m))
#define listSetFreeMethod(l, m) ((l)->free = (m))
#define listSetMatchMethod(l, m) ((l)->match = (m))

DListNode *ListNewNode(void *value);

DList *ListCreate(void);

DList *ListAddNodeHead(DList *list, void *value);

DList *ListAddNodeTail(DList *list, void *value);

void ListDelHeadNode(DList *list);

void ListDelTailNode(DList *list);

void ListDelNode(DList *list, DListNode *node);

void ListDelValue(DList *list, void *value);

DList *ListDup(DList *list);

void ListTraverse(DList *list, int direction);

void ListRelease(DList *list);

DListIter *ListGetIter(DList *list, int direction);

DListNode *ListNext(DListIter *iter);

DListNode *ListSearchKey(DList *list, void *key);

DListNode *ListIndex(DList *list, long index);

void ListReleaseIter(DListIter *iter);

#endif //ZERO_DLIST_H
