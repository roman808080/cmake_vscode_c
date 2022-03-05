#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
class LinkedListNode{
public:
    int val;
    LinkedListNode *next;

    LinkedListNode(int node_value) {
        val = node_value;
        next = NULL;
    }
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, int val){
    if(head == NULL) {
        head = new LinkedListNode(val);
    }
    else {
        LinkedListNode *end = head;
        while (end->next != NULL) {
            end = end->next;
        }
        LinkedListNode *node = new LinkedListNode(val);
        end->next = node;
    }
    return head;
}


/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode *next;
};
*/

void removeAll(int val, LinkedListNode **list) {
    LinkedListNode* start = *list;
    
    while (start != NULL) {
        if (start->val == val) {
            
            LinkedListNode* temp = start;
            start = start->next;
            delete temp;
        }
        else {
            break;
        }
    }

    *list = start;
    LinkedListNode* previous = start;

    if (start == NULL) {
        return;
    }
    LinkedListNode* current = start->next;

    while (current != NULL) {
        if (current->val == val) {
            LinkedListNode* temp = current;
            previous->next = current->next;
            
            current = current->next;
            delete temp;
        }
        else {
            previous = current;
            current = current->next;
        }
    }
}

int main() {
    int _val;
    cin >> _val;

    int _list_size;
    int _list_item;
    LinkedListNode* _list = NULL;
    cin >> _list_size;
int _list_i;
    for(_list_i = 0; _list_i < _list_size; _list_i++) { 
        cin >> _list_item;
		_list = _insert_node_into_singlylinkedlist(_list, _list_item);
    }
  
    removeAll(_val, &_list);
    
	LinkedListNode* _current = _list;
  	while (_current != NULL)
    {
      cout << _current->val << " ";
      _current = _current->next;
    }
  
    return 0;
}
