#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAXCAP 3000
#define MAXVAL 10000

class Node {
private:
    Node() = delete;
    
    Node(Node const &) = delete;
    Node(Node const &&) = delete;
    
    void operator=(Node const &) = delete;
    void operator=(Node const &&) = delete;
    
    bool operator==(Node const &) const = delete;
    bool operator==(Node const &&) const = delete;
    bool operator!=(Node const &) const = delete;
    bool operator!=(Node const &&) const = delete;

public:
    int key = -1;
    int val = -1;
    Node * prev = nullptr;
    Node * next = nullptr;

    Node(int const key, int const val, Node * const prev, Node * const next)
        : key(key), val(val), prev(prev), next(next) { return; }
    ~Node() {
        this->prev = nullptr;
        this->next = nullptr;
        return;
    }
};
class Stack {
private:
    int size = 0;
    Node * head = nullptr;
    Node * tail = nullptr;
    
    Stack(Stack const &) = delete;
    Stack(Stack const &&) = delete;
    
    void operator=(Stack const &) = delete;
    void operator=(Stack const &&) = delete;

    bool operator==(Stack const &) const = delete;
    bool operator==(Stack const &&) const = delete;
    bool operator!=(Stack const &) const = delete;
    bool operator!=(Stack const &&) const = delete;

public:
    Stack();
    ~Stack();
    
    void remove(Node * const node);
    Node * popTop();
    Node * popBottom();
    void push(Node * const node);
    int getSize() const;
};

Stack::Stack() { return; }
Stack::~Stack() {
    Node * temp(nullptr);
    while (temp) {
        temp = head;
        this->remove(temp);
        delete temp;
    }
    
    return;
}
void Stack::remove(Node * const node) {
    if (!node) return;
    
    if (!node->prev) this->head = node->next;
    else node->prev->next = node->next;
    
    if (!node->next) this->tail = node->prev;
    else node->next->prev = node->prev;

    node->prev = nullptr;
    node->next = nullptr;
    
    --size;
    
    return;
}
Node * Stack::popTop() {
    Node * top(this->tail);
    this->remove(top);
    return top;
}
Node * Stack::popBottom() {
    Node * bottom(this->head);
    this->remove(bottom);
    return bottom;
};
void Stack::push(Node * const node) {
    if (!node || node->prev || node->next) return;

    if (this->tail) this->tail->next = node;
    node->prev = this->tail;
    this->tail = node;
    
    ++size;

    return;
}
int Stack::getSize() const {
    return this->size;
}

class LRUCache {
private:
    int capacity = 0;
    int filled = 0;
    Stack stack;
    vector<Node *> keys = vector<Node *>(MAXCAP,nullptr);

public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if ((key < 0) || (MAXCAP <= key)) return -1;
        
        Node * const selected(keys[key]);
        if (!selected) return -1;
        
        stack.remove(selected);
        stack.push(selected);
        
        return selected->val;
    }
    
    void put(int key, int value) {
        if ((key < 0) || (MAXCAP <= key) || (value < 0) || (MAXVAL <= value)) return;

        if (filled < capacity) {
            Node * const node(new Node(key,value,nullptr,nullptr));

            keys[key] = node;
            stack.push(node);

            ++filled;
        } else {
            Node * const bottom(stack.popBottom());
            
            int & bottomKey(bottom->key);
            int & bottomVal(bottom->val);
            
            keys[bottomKey] = nullptr;
            
            bottomKey = key;
            bottomVal = value;
            
            keys[bottomKey] = bottom;

            stack.push(bottom);
        }
        
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
	LRUCache * const lRUCache = new LRUCache(2);
	lRUCache->put(1, 1); // cache is {1=1}
	lRUCache->put(2, 2); // cache is {1=1, 2=2}
	lRUCache->get(1);    // return 1
	lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
	lRUCache->get(2);    // returns -1 (not found)
	lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
	lRUCache->get(1);    // return -1 (not found)
	lRUCache->get(3);    // return 3
	lRUCache->get(4);    // return 4

	return 0;
}
