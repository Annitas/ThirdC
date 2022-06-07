//
//  DequeList.cpp
//  3
//
//  Created by Anita Stashevskaya on 06.06.2022.
//

#include "DequeList.hpp"

#include "List.hpp"
#include <iostream>
#include <exception>

using namespace std;

DequeList::DequeList() {
    first = new ListD;
    first->data = 0;
    first->next = first;
    first->prev = first;
    size = 0;
}
DequeList::DequeList(const DequeList & copy) {
    first = new ListD;
    first->data = 0;
    first->next = first;
    first->prev = first;
    size = copy.size;
    ListD *buf = copy.first->next;
    for (int i = 0; i < size; i++) {
        ListD *temp = new ListD;
        temp->data = buf->data;
        temp->next = first->next;
        temp->prev = first;
        first->next = temp;
        first = temp;
        buf = buf->next;
    }
    first->next->prev = first;
    first = first->next;
}
DequeList::DequeList(DequeList&&  copy) {
    first = new ListD;
    first->data = 0;
    first->next = first;
    size = copy.size;
    copy.first = copy.first->next;
    for (int i = 0; i < this->size; i++) {
        ListD *temp = new ListD;
        temp->data = copy.first->data;
        temp->next = first->next;
        temp->prev = first;
        first->next = temp;
        first = temp;
        ListD *buf = copy.first->next;
        delete copy.first;
        copy.first = buf;
    }
    delete copy.first;
    first->next->prev = first;
    first = first->next;
}
DequeList::~DequeList(){
    clear();
    delete first;
}
DequeList& DequeList::operator= (const DequeList &copy) {
    if (this == &copy) {
        return *this;
    }
    if (size > 0) {
        clear();
    }
    size = copy.size;
    ListD *buf = copy.first->next;
    for (int i = 0; i < size; i++) {
        ListD *temp = new ListD;
        temp->data = buf->data;
        temp->next = first->next;
        temp->prev = first;
        first->next = temp;
        first = temp;
        buf = buf->next;
    }
    first->next->prev = first;
    first = first->next;
    return *this;
}
DequeList& DequeList::operator= (DequeList &&copy) {
    swap(first, copy.first);
    size = copy.size;
    clear();
    delete copy.first;
    return *this;
}

void DequeList::addElem(const int &elem, Iterator &iter) {
    size++;
    ListD *res = new ListD;
    res->data = elem;
    res->next = iter.getNow()->next;
    res->prev = iter.getNow();
    iter.getNow()->next->prev = res;
    iter.getNow()->next = res;
}
void DequeList::deleteElem(Iterator &iter) {
    if (size == 0) {
        throw - 1;
    }
    ListD *prev = new ListD;
    ListD *next = new ListD;
    size--;
    prev = iter.getNow()->prev;
    next = iter.getNow()->next;
    prev->next = iter.getNow()->next;
    next->prev = iter.getNow()->prev;
    free(iter.getNow());
}
void DequeList::clear() {
    first = first->next;
    while (size > 0) {
        ListD *temp = first->next;
        delete first;
        first = temp;
        size--;
    }
    first->next = first;
    first->prev = first;
}
bool DequeList::isEmpty() const {
    return (size == 0);
}

int DequeList::getSize() const {
    return size;
}
Iterator* DequeList::findElem(const int &elem) {
    ListIterator* list = new ListIterator(this);
    while (!list->finish()) {
        list->next();
        if (list->getElem() == elem) {
            return list;
        }
    }
    throw - 1;
}

Iterator* DequeList::getIterator() {
    return new ListIterator(this);
}
DequeList::ListIterator::ListIterator(DequeList *list) {
    this->list = list;
    this->currentNode = list->first;
}
void DequeList::ListIterator::start() {
    currentNode = list->first;
}
int DequeList::ListIterator::getElem() const {
    if (currentNode == list->first) {
        throw - 1;
    }
    return currentNode->data;
}
void DequeList::ListIterator::next() {
    if (finish()) {
        throw -1;
    }
    currentNode = currentNode->next;
}
void  DequeList::ListIterator::prev() {
    if (currentNode == list->first) {
        throw -1;
    }
    currentNode = currentNode->prev;
}
bool DequeList::ListIterator::finish() const {
    return (currentNode->next == list->first);
}
ListD* DequeList::ListIterator::getNow() const {
    return currentNode;
}
