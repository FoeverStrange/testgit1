//
//  Deque.hpp
//  Snake
//
//  Created by Cedric on 2020/4/24.
//  Copyright © 2020 Cedric. All rights reserved.
//


#ifndef Deque_hpp
#define Deque_hpp

#include <iostream>

template<class type>
struct QueneNode
{
    type data;
    QueneNode *next,*prev;
};

template<class type>
class Deque
{
public:
    Deque();
    ~Deque();
    void clear();//清除队列
    bool push_back(type &value);//在队尾增加一个
    bool push_front(type &value);//在队首增加一个
    bool pop_back();//在队尾删除一个
    inline unsigned size() {return qsize;}
    type operator[](unsigned i);
protected:
    unsigned qsize;
    QueneNode<type> *head,*tail;
};

#endif /* Deque_hpp */
