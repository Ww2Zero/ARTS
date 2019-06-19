struct tNode {
    int val;
    tNode *next;

    tNode(int v) : val(v), next(nullptr) {}
};

class MyLinkedList {

private:
    tNode *head;
    tNode *tail;
    int len;
private:

    tNode *getListNode(tNode *node, int index) {
        if (node == nullptr || index <= 0) {
            return node;
        }
        return getListNode(node->next, --index);
    }

    tNode *createNewNode(int val) {
        tNode *newNode = new tNode(val);
        if (newNode == nullptr) {
            return nullptr;
        }
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return nullptr;
        }
        return newNode;
    }

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        len = 0;
        head = nullptr;
        tail = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || head == nullptr || index > len) {
            return -1;
        }
        tNode *target = getListNode(head, index);
        if (target == nullptr) {
            return -1;
        }
        return target->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        tNode *newNode = createNewNode(val);
        if (newNode) {
            newNode->next = head;
            head = newNode;
        }
        ++len;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        tNode *newNode = createNewNode(val);
        if (newNode) {
            tail->next = newNode;
            tail = newNode;
        }
        ++len;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > len) {
            return;
        }
        if (index <= 0) {
            addAtHead(val);
        } else if (index >= len) {
            addAtTail(val);
        } else {
            tNode *addpos = getListNode(head, index - 1);
            if (addpos != nullptr) {
                tNode *newNode = createNewNode(val);
                newNode->next = addpos->next;
                addpos->next = newNode;
                ++len;
            }
        }

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || head == nullptr) {
            return;
        }
        tNode *delNode;
        if (index == 0) {
            delNode = head;
            if (head == tail) {
                tail = nullptr;
            }
            head = head->next;
        } else {
            tNode *preNode = getListNode(head, index - 1);
            if (preNode != nullptr) {
                delNode = preNode->next;
                if (delNode == nullptr) {
                    return;
                }
                if (delNode == tail) {
                    tail = preNode;
                }

                preNode->next = delNode->next;
            }
        }
        delete delNode;
        --len;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */