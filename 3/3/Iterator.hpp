//
//  Iterator.hpp
//  3
//
//  Created by Anita Stashevskaya on 06.06.2022.
//

#ifndef Iterator_hpp
#define Iterator_hpp

#include <stdio.h>

#endif /* Iterator_hpp */

#pragma once

struct ListD {
    int data;
    ListD *next;
    ListD *prev;
};

class Iterator {
public:
    virtual void start() = 0;
    virtual int getElem() const = 0;
    virtual void next() = 0;
    virtual void prev() = 0;
    virtual bool finish() const = 0;
    virtual ListD* getNow() const = 0;
};
