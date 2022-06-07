//
//  List.hpp
//  3
//
//  Created by Anita Stashevskaya on 06.06.2022.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>

#endif /* List_hpp */

#pragma once
#include "Iterator.hpp"

class List {
public:
    virtual void addElem(const int &elem, Iterator &iter) = 0;
    virtual void deleteElem(Iterator &iter) = 0;
    virtual Iterator* findElem(const int &elem) = 0;
    virtual void makeEmpty() = 0;
    virtual bool Empty() const = 0;
    virtual int getSize() const = 0;
    virtual Iterator* getIterator() = 0;
};
