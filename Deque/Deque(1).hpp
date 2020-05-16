//
//  Deque.hpp
//  Snake
//
//  Created by Cedric on 2020/4/24.
//  Copyright ? 2020 Cedric. All rights reserved.
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
    void clear();//�������
    bool push_back(type &value);//�ڶ�β����һ��
    bool push_front(type &value);//�ڶ�������һ��
    bool pop_back();//�ڶ�βɾ��һ��
    inline unsigned size() {return qsize;}
    type operator[](unsigned i); //����[]���ص�i�����λ�õ�����data 
protected:
    unsigned qsize;
    QueneNode<type> *head,*tail;
};

#endif /* Deque_hpp */

