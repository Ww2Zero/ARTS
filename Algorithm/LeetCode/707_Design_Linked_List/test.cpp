#include "solution.h"

#include <vector>

using namespace std;


int main() {

    MyLinkedList *myLinkedList = new MyLinkedList();

    myLinkedList->addAtHead(1);
    myLinkedList->addAtTail(2);
    myLinkedList->addAtIndex(1, 3);

    int index0 = myLinkedList->get(0);
    int index1 = myLinkedList->get(1);
    int index2 = myLinkedList->get(2);

    assert(index0 == 1);
    assert(index1 == 3);
    assert(index2 == 2);
    myLinkedList->deleteAtIndex(1);
    index0 = myLinkedList->get(0);
    index1 = myLinkedList->get(1);
    assert(index0 == 1);
    assert(index1 == 2);


//    ["MyLinkedList","addAtHead","addAtHead","deleteAtIndex","addAtIndex","addAtHead","addAtHead","addAtHead","get","addAtTail","addAtIndex","addAtHead"]
//    [[],[5],[2],[1],[1,9],[4],[9],[8],[3],[1],[3,6],[3]]

    MyLinkedList *list = new MyLinkedList();
    list->addAtHead(5);
    list->addAtHead(1);
    list->deleteAtIndex(1);
    list->addAtIndex(1, 9);
    list->addAtHead(4);
    list->addAtHead(9);
    list->addAtHead(8);
    list->get(3);
    list->addAtTail(1);
    list->addAtIndex(3, 6);
    list->addAtHead(3);


//    ["MyLinkedList","get","addAtIndex","get","get","addAtIndex","get","get"]
//    [[],[0],[1,2],[0],[1],[0,1],[0],[1]]
//    Output
//    [null,-1,null,-1,-1,null,-1,-1]
//    Expected
//    [null,-1,null,-1,-1,null,1,-1]

    MyLinkedList *l = new MyLinkedList();
    l->get(0);
    l->addAtIndex(1, 2);
    l->get(0);
    l->get(1);
    l->addAtIndex(0, 1);
    l->get(0);
    l->get(1);

//    ["MyLinkedList","get","addAtIndex","get","get","addAtIndex","get","get"]
//    [[],[0],[1,2],[0],[1],[0,1],[0],[1]]
//    Output
//    [null,-1,null,2,-1,null,1,2]
//    Expected
//    [null,-1,null,-1,-1,null,1,-1]

    MyLinkedList *l1 = new MyLinkedList();
    l1->get(0);
    l1->addAtIndex(1, 2);
    l1->get(0);
    l1->get(1);
    l1->addAtIndex(0, 1);
    l1->get(0);
    l1->get(1);

    return 0;
}