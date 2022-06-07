//
//  main.cpp
//  3
//
//  Created by Anita Stashevskaya on 06.06.2022.
//
#include "Iterator.hpp"
#include "DequeList.hpp"
#include "DequeList.cpp"
#include "List.hpp"
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    DequeList *buf = new DequeList();
    DequeList::ListIterator iter(buf);
    buf -> addElem(1, iter);
    buf -> addElem(3, iter);
    buf -> addElem(2, iter);
    buf -> addElem(5, iter);
    buf -> addElem(2, iter);
    buf -> addElem(2, iter);
    buf -> addElem(2, iter);
    
    while(!iter.finish()) {
        iter.next();
        cout<<iter.getElem()<<", ";
    }
    
    cout<< "Size " << buf -> getSize() << "\n";
    cout<< "Empty? " << buf -> isEmpty() << "\n";
    try {
        Iterator *iter5 = buf -> findElem(9);
    } catch (int a) {
        cout<<"Error\n";
    }
    
    Iterator *iter1 = buf -> findElem(5);
    buf -> deleteElem(*iter1);
    iter.start();
    while (!iter.finish()) {
        iter.next();
        cout<< iter.getElem() << "\n";
    }
    
    DequeList *buf1 = new DequeList();
    DequeList::ListIterator iter2(buf1);
    buf1 -> addElem(2, iter2);
    buf1 -> addElem(2, iter2);
    buf1 -> addElem(2, iter2);
    buf -> operator=(*buf1);
    cout<< buf -> getSize() << "\n";
    iter.start();
    
    while(!iter.finish()) {
        iter.next();
        cout<< iter.getElem() << " ";
    }
    buf -> clear();
    cout<< "Is empty?" << buf -> isEmpty()<< "\n";
    
    return 0;
}
