#include <sys/iofunc.h>
#include <sys/dispatch.h>
#include <errno.h>
#include <stdio.h>
#include "namelookup.h"

int coid;
int sid;
int priority;
myMessage_t smsg;

int main()
{
    priority = 0;
    smsg.pulse.code = 65 ;
    smsg.pulse.value.sival_int = 333;

    coid = name_open( "mertinyeri", 0 );
    if(coid == -1)
    {
        printf("could not create channel--> errno : %d \n", errno);
    }
    else
    {
        printf("[CLIENT] mertinyeri opened \n");
    }
    
    printf("[CLIENT] sending pulse data... \n");
    sid = MsgSendPulse(coid, priority, smsg.pulse.code, smsg.pulse.value.sival_int);
    
    if(sid == -1)
    {
        printf("could not send pulse data--> errno : %d \n", errno);
    }
    else
    {
        printf("[CLIENT] pulse data sent! \n");
    }

    name_close(coid);
}