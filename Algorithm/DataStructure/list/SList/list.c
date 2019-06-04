#include "list.h"

/**
 * 创建链表的节点
 * @param value 节点的值
 * @return 新建节点的指针
 */
ListNode *listNewNode(int value) {
  ListNode *node;
  node = malloc(sizeof(ListNode));
  if (node != NULL) {
    node->next = NULL;
    node->value = value;
  }
  return node;
}

/**
 * 使用数组初始化一个链表，一共len个元素，（暂不考虑输入的合法性）
 * @param array 数组
 * @param len 数组的长度
 * @return 新建链表头指针
 */
ListNode *listCreate(int array[], int len) {
  ListNode *head = NULL;
  for (int i = 0; i < len; i++) {
    head = listAddNodeTail(head, array[i]);
    if (head == NULL) {
      return NULL;
    }
  }
  return head;
}

/**
 * 头插法插入节点
 * @param head 链表的头节点
 * @param value 插入的值
 * @return 返回链表的新的头节点
 */
ListNode *listAddNodeHead(ListNode *head, int value) {
  ListNode *node;
  node = listNewNode(value);
  if (node == NULL) {
    return NULL;
  }
  if (head) {
    node->next = head;
  }
  return node;
}

/**
 * 尾插法插入节点
 * @param head 链表的头节点
 * @param value 插入的值
 * @return 返回链表的头节点
 */
ListNode *listAddNodeTail(ListNode *head, int value) {
  ListNode *node;
  node = listNewNode(value);
  if (node == NULL) {
    return NULL;
  }
  if (head) {
    ListNode *current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = node;
  } else {
    head = node;
  }
  return head;
}

/**
 * 删除链表的头节点
 * @param head
 * @return
 */
ListNode *listDelNodeHead(ListNode *head) {
  ListNode *current = head;
  if (current) {
    head = current->next;
  }
  return head;
}

/**
 * 删除链表的尾节点
 * @param head
 * @return
 */
ListNode *listDelNodeTail(ListNode *head) {
  ListNode *current = head, *prev = NULL;
  if (current) {
    if (current->next) {
      while (current->next) {
        prev = current;
        current = current->next;
      }
      prev->next = NULL;
      free(current);
      return head;
    }
  }
  return NULL;
}

/**
 * 遍历链表删除value值的节点
 * @param head 链表的头节点
 * @param value 删除的目标值
 * @return 链表的头节点
 */
ListNode *listDelNode(ListNode *head, int value) {
  ListNode *current = head, *prev = NULL;
  while (current) {
    if (current->value == value) {
      if (current == head) {
        head = head->next;
      } else {
        prev->next = current->next;
      }
      free(current);
      break;
    }
    prev = current;
    current = current->next;
  }
  return head;
}

/**
 * 计算链表的长度
 * @param head 链表的头节点
 * @return 链表的长度
 */
int listLength(ListNode *head) {
  int len = 0;
  while (head) {
    len++;
    head = head->next;
  }
  return len;
}

/**
 * 释放链表
 * @param head
 */
void listRelease(ListNode *head) {
  ListNode *current = head;
  while (current) {
    ListNode *node = current->next;
    free(current);
    current = node;
  }
}

/**
 * 遍历打印链表
 * @param head
 */
void listTraverse(ListNode *head) {
  ListNode *current = head;
  while (current) {
    printf("%d", current->value);
    printf("->");
    current = current->next;
    if (current == head) {
      break;
    }
  }
  printf("NULL\n");
}