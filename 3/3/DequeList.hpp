//
//  DequeList.hpp
//  3
//
//  Created by Anita Stashevskaya on 06.06.2022.
//

#ifndef DequeList_hpp
#define DequeList_hpp

#include <stdio.h>

#endif /* DequeList_hpp */
#include "List.hpp"
//#include "Iterator.hpp"
#pragma once

class DequeList : public List {
private:
    ListD* first;
    int size;
public:
    //friend class ListIterator;
    class ListIterator : public Iterator {
    private:
        DequeList *list;
        ListD * currentNode;
    public:
        ListIterator(DequeList *list);
        void start();
        int getElem() const;
        void next();
        void prev();
        bool finish() const;
        ListD* getNow() const;
    };
    DequeList();
    DequeList(const DequeList& copy);
    DequeList(DequeList&& copy);
    ~DequeList();
    DequeList& operator= (const DequeList &copy);
    DequeList& operator=(DequeList&& copy);
    void addElem(const int &elem, Iterator &iter);
    void deleteElem(Iterator &iter);
    void clear();
    bool isEmpty() const;
    int getSize() const;
    Iterator* findElem(const int &elem);
    Iterator* getIterator();
};
