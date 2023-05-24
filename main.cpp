#include "Linklist.hpp"
#include "Linknode.hpp"
#include <iostream>


int main()
{
    int a = 1;
    Linknode<int> node1(1);
    Linknode<int> node2(2);
    Linknode<int> node3(3);
    Linknode<int> node4(4);
    Linklist<int> list;
    list.Insert(&node1, list.getEnd());
    Linklist_iterator<int> it = list.begin();
    for (int i = 1; i < list.Length(); i++)
        ++it;
    list.it_Insert(it, 2);
    list.Insert(&node3, list.getEnd());
    list.Insert(&node4, list.getEnd());
    //list.Delete(node3);
    //list.it_Delete(3);
    //list.Modity(4,5);
    list.Length();
    return 0;
}