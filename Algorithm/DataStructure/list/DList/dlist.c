#include "dlist.h"

/**
 * 新建链表节点
 * @param value
 * @return
 */
DListNode *ListNewNode(void *value) {
    DListNode *node;
    node = malloc(sizeof(*node));
    if (node == NULL) {
        return NULL;
    }
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

/**
 * 新建链表
 * @return
 */
DList *ListCreate(void) {
    DList *list;
    list = malloc(sizeof(*list));
    if (list == NULL) {
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->free = NULL;
    list->dup = NULL;
    list->match = NULL;
    list->len = 0;
    return list;
}

/**
 * 链表头节点插入新的节点
 * @param list
 * @param value
 * @return
 */
DList *ListAddNodeHead(DList *list, void *value) {
    DListNode *node;
    node = ListNewNode(value);
    if (node == NULL) {
        return list;
    }
    if (list->len == 0) {
        list->head = node;
        list->tail = node;
    } else {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
    list->len++;
    return list;
}

/**
 * 链表尾节点插入新节点
 * @param list
 * @param value
 * @return
 */
DList *ListAddNodeTail(DList *list, void *value) {
    DListNode *node;
    node = ListNewNode(value);
    if (node == NULL) {
        return list;
    }
    if (list->len == 0) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
    list->len++;
    return list;
}

/**
 * 删除链表的头节点
 * @param list
 * @return
 */
void ListDelHeadNode(DList *list) {
    if (list->head) {
        DListNode *head = list->head;
        list->head = head->next;
        head->next->prev = head->prev;
        if (list->free) {
            list->free(head->value);
        }
        free(head);
        list->len--;
    }
}

/**
 * 删除链表的尾节点
 * @param list
 * @return
 */
void ListDelTailNode(DList *list) {
    if (list->tail) {
        DListNode *tail = list->tail;
        list->tail = tail->prev;
        list->tail->next = NULL;
        if (list->free) {
            list->free(tail->value);
        }
        free(tail);
        list->len--;
    }
}

/**
 * 链表中删除指定节点
 * @param list
 * @param node
 * @return
 */
void ListDelNode(DList *list, DListNode *node) {
    // 是否头节点
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }
    // 是否尾节点
    if (node->next) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }
    if (list->free) {
        list->free(node->value);
    }
    free(node);
    list->len--;
}

/**
 * 链表中删除指定值的节点
 * @param list
 * @param value
 * @return
 */
void ListDelValue(DList *list, void *value) {
    DListNode *node = ListSearchKey(list, value);
    ListDelNode(list, node);
}

/**
 * 复制双链表，返回新的双链表指针
 * @param list
 * @return
 */
DList *ListDup(DList *list) {
    DList *copy = ListCreate();
    if (copy == NULL) {
        return NULL;
    }
    copy->match = list->match;
    copy->free = list->free;
    copy->dup = list->dup;
    DListIter *iter = ListGetIter(list, ITER_START_HEAD);
    DListNode *node;
    while ((node = ListNext(iter)) != NULL) {
        void *value;
        if (copy->dup) {
            value = copy->dup(node->value);
            if (value == NULL) {
                ListRelease(copy);
                ListReleaseIter(iter);
                return NULL;
            }
        } else {
            value = node->value;
        }
        if (ListAddNodeTail(copy, value) == NULL) {
            ListRelease(copy);
            ListReleaseIter(iter);
            return NULL;
        }
    }
    ListReleaseIter(iter);
    return copy;
}

/**
 * 按照direction方向遍历输出链表节点的值
 * @param list
 * @param direction
 */
void ListTraverse(DList *list, int direction) {
    DListIter *iter = ListGetIter(list, direction);
    DListNode *node;
    while (node = ListNext(iter)) {
        printf("%s->", node->value);
    }
    ListReleaseIter(iter);
    printf("NULL\n");
}

void ListRelease(DList *list) {
    DListIter *iter = ListGetIter(list, ITER_START_HEAD);
    DListNode *node;
    while (node = ListNext(iter)) {
        if (list->free) {
            list->free(node->value);
        }
        free(node);
    }
    free(list);
    ListReleaseIter(iter);
}

/**
 * 获取双链表的迭代器
 * @param list
 * @param direction 迭代器的方向 0 从头到尾 1 从尾到头
 * @return
 */
DListIter *ListGetIter(DList *list, int direction) {
    DListIter *iter = malloc(sizeof(DListIter));
    if (iter == NULL) {
        return NULL;
    }
    // 从头向后遍历
    if (direction == ITER_START_HEAD) {
        iter->next = list->head;
    } else {
        iter->next = list->tail;
    }
    iter->direction = direction;
    return iter;
}

/**
 * 获取迭代器的下一个节点
 * @param iter
 * @return
 */
DListNode *ListNext(DListIter *iter) {
    DListNode *current = iter->next;
    if (current) {
        if (iter->direction == ITER_START_HEAD) {
            iter->next = current->next;
        } else {
            iter->next = current->prev;
        }
    }
    return current;
}

/**
 * 通过迭代器获取链表中的值为key的节点
 * @param list
 * @param key
 * @return
 */
DListNode *ListSearchKey(DList *list, void *key) {
    DListIter *iter = ListGetIter(list, ITER_START_HEAD);

    DListNode *node, *found = NULL;

    while (node = ListNext(iter)) {
        if (list->match) {
            if (list->match(node->value, key)) {
                found = node;
                break;
            }
        } else {
            if (key == node->value) {
                found = node;
                break;
            }
        }
    }
    ListReleaseIter(iter);
    return found;
}

/**
 * 获取链表中索引为index的节点
 * @param list
 * @param index
 * @return
 */
DListNode *ListIndex(DList *list, long index) {
    DListNode *node;
    if (index < 0) {
        index = (-index) - 1;
        node = list->tail;
        while (index-- && node) {
            node = node->prev;
        }
    } else {
        node = list->head;
        while (index-- && node) {
            node = node->next;
        }
    }
    return node;
}

/**
 * 回收迭代节点的内存
 * @param iter
 */
void ListReleaseIter(DListIter *iter) {
    free(iter);
}