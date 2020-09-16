#include <string>
#include "LinkStack.h"

int Judge_s(char s[], LinkStack S)//首先判断是否合法
{
    if(S.Match(s)==-1)    //括号是否匹配(调用。h文件的match函数)
        return -1;
    
    int len=strlen(s);
    for(int i=0;i<len;i++)
        if(s[i]==')'&&s[i+1]=='(')
            return -1;    //括号挨在一起 不合法
    
    return 0;
}

//检测括号是否可以删除
int check(char s[], int left, int right)
{
    int i;            //下标
    int leftCount;    //左括号统计（用于判断括号内是否还有括号）
    
    if (s[left-1] == '-')    //处理 ' -(a +|- b) '
    {
        i = left;
        leftCount = 1;
        while (++i < right)
        {
            if (s[i] == '(')
                leftCount++;
            
            if ((s[i] == '+' || s[i] == '-' ) && leftCount == 1)
                return 0;
        }
    }
    
    if (s[left-1] == '/')    //处理 ' /(a +|-|*|/ b) '
        return 0;
    
    //处理 ' +(a +|-|*|/ b) +|- '
    if (s[left-1] != '*' && s[left-1] != '/' &&s[right+1] != '*' && s[right+1] != '/')
        return 1;
    
    //处理 ' *(a *|/ b) +|-|*|/ '
    i = left;
    leftCount = 1;
    while (++i < right)
    {
        if (s[i] == '(')
            leftCount++;
        
        if ((s[i] == '*' || s[i] == '/' ) && leftCount == 1)
            return 1;
    }
    
    int flag=0; //没有符号
    for(int i=left+1;i<right;i++)    //处理括号中只有数字的情况
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
        return 1;   //没有符号 删除
    
    return 0;
}

int delExcessBrackets(char s[], int index)//删除多余的括号
{
    int left, right;
    while (s[index] != '\0')
    {
        if (s[index] == ')')     //如果为右括号，返回下标
            return index;
        
        if (s[index] == '(')     //如果为左括号，找到右括号的下标
        {
            left = index;
            index = right =  delExcessBrackets(s, index+1);
            
            if (check(s, left, right))    //若检测结果为可以删除，那么把括号位置换成空
                s[left] = s[right] = ' ';
        }
        index++;
    }
    return 0;
}

int main()
{
    LinkStack S;
    char exp[256];
    scanf("%s", exp);
    //strcpy(exp,"(a+((b)*(c+d)))");//(((a+b)*c/d)-(a)) 对(((1)+2*(3)))-4 (a+((b)*(c+d)))
    
    if(Judge_s(exp,S)==-1)
    {
        cout << "wrong" << endl;
        return 0;
    }
    else
    {
        cout << "right" << endl;
        
        delExcessBrackets(exp, 0);
        
        int i = -1;
        while (exp[++i] != '\0')
        {
            if (exp[i] != ' ')
                printf("%c", exp[i]);
        }
        cout << endl;
    }
    
    return 0;
}
