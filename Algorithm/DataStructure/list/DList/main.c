#include "dlist.h"
#include "string.h"

#define ARRAY_LEN(a) (sizeof(a) / sizeof(a[0]))


char *newValue(char *s) {
    int len = strlen(s);
    char *new = (char *) malloc(len + 1);
    strcpy(new, s);
    return new;
}

void freeValue(void *ptr) {
    free(ptr);
    ptr = NULL;
}

int matchValue(void *v1, void *v2) {
    if (strcmp(v1, v2) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void *dupValue(void *v1) {
    void *vDup = newValue(v1);
    return vDup;
}

DList *createDListForArray(char *a[], int len) {
    DList *list = ListCreate();
    listSetDupMethod(list, dupValue);
    listSetFreeMethod(list, freeValue);
    listSetMatchMethod(list, matchValue);

    for (int i = 0; i < len; i++) {
        ListAddNodeTail(list, (void *) a[i]);
    }
    return list;
}


int main() {
    char *test[] = {newValue("11"), newValue("22"), newValue("33"), newValue("44"), newValue("55")};
    DList *list = createDListForArray(test, ARRAY_LEN(test));
    ListTraverse(list, ITER_START_HEAD);
    ListTraverse(list, ITER_START_TAIL);
    DListNode *node;
    printf("test-->ListSearchKey(list,\"11\")\n");
    node = ListSearchKey(list, "22");
    if (node) {
        printf("found Node:%s\n", node->value);
    } else {
        printf("not found\n");
    }
    printf("test-->ListDelNode(list,node)\n");
    ListDelNode(list, node);
    ListTraverse(list, ITER_START_HEAD);
    printf("test-->ListAddNodeHead(list, newValue(\"00\"))\n");
    ListAddNodeHead(list, newValue("00"));
    ListTraverse(list, ITER_START_HEAD);

    printf("test-->ListAddNodeTail(list, newValue(\"66\"));\n");
    ListAddNodeTail(list, newValue("66"));
    ListTraverse(list, ITER_START_HEAD);

    printf("test-->ListDelHeadNode(list)\n");
    ListDelHeadNode(list);
    ListTraverse(list, ITER_START_HEAD);

    printf("test-->ListDelTailNode(list)\n");
    ListDelTailNode(list);
    ListTraverse(list, ITER_START_HEAD);

    printf("test-->ListDelValue(list,newValue(\"33\"))\n");
    ListDelValue(list, newValue("33"));
    ListTraverse(list, ITER_START_HEAD);

    printf("test-->ListSearchKey(list,\"12\")\n");
    node = ListSearchKey(list, "12");
    if (node) {
        printf("found Node:%s\n", node->value);
    } else {
        printf("not found\n");
    }

    printf("test-->ListIndex(list,2)\n");
    node = ListIndex(list, 2);
    printf("list index is %s\n", node->value);

    printf("test-->ListDup\n");
    DList *copyList = ListDup(list);
    printf("copyList is");
    ListTraverse(copyList, ITER_START_HEAD);
    ListRelease(copyList);
    ListRelease(list);

    return 0;
}