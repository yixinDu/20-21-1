#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int i,p_id;
    if((p_id==fork())==0)
    {
        for(int i=1;i<3;i++)
            printf("This is child process\n");
        if(p_id==-1)
        {
            printf("fork new process error\n");
            return 0;
        }
        else
            for(int i=1;i<3;i++)
                printf("This is parent process\n");
    }
    return 0;
}
