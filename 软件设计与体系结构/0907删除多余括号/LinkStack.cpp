#include "LinkStack.h"

LinkStack::LinkStack()
{
    top = NULL;
}

LinkStack::~LinkStack()
{
    
}

void LinkStack::Push(int x) //头插
{
    Node* newp=new Node; newp->data=x;
    newp->next=top;
    top=newp;
}

int LinkStack::Pop()    //头删
{
    Node* p=top;
    top = top->next;
    int x = p->data;
    delete p;
    return x;
}

bool LinkStack::isEmpty()
{
    return top==NULL;
}

int LinkStack::Match(char *s)
{
    int i=0;
    for(;s[i]!='\0';i++)    //依次读取一个字符
    {
        if(s[i]=='(' || s[i]==')')
        {
            if(s[i]=='(' )   //如果是左括号
                Push(1);
            else    //右括号
            {
                if(isEmpty())   //右括号多了
                    return -1; //)多了
                
                //如果不为空 需要匹配 匹配成功后删除
                if(s[i]==')')
                {
                    if(top->data==1)
                        Pop();
                    else
                        return -1;  //不匹配
                }
            }
        }
    }
    if(isEmpty()) return 0;
    if(!isEmpty())
    {
        if(top->data==1)
            return -1;//(
    }
    
    return 0;
}
