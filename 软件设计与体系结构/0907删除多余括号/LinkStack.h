//
//  LinkStack.hpp
//  0907删除多余括号
//
//  Created by yfkj on 2020/9/8.
//  Copyright © 2020 yfkj. All rights reserved.
//

#ifndef LinkStack_h
#define LinkStack_h

#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class LinkStack
{
    Node* top;  //栈顶指针
public:
    bool isEmpty();
    int Pop();
    void Push(int x);
    LinkStack();
    virtual ~LinkStack();
    int Match(char s[]);
};

#endif /* LinkStack_h */
