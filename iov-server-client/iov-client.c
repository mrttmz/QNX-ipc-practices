#include <sys/iofunc.h>
#include <sys/dispatch.h>
#include <errno.h>
#include <stdio.h>
#include "iov.h"

int coid;
int sid;

iov_t siov[MERTINYERI_ARRAY_SIZE];
iov_t riov[MERTINYERI_ARRAY_SIZE];
io_devctl_t header; 
myMessage_t smsg;

int main()
{
   smsg.messageFromMert ="Izmirrrrrrrrrrrrrrrrrrr";

    coid = name_open( "mertinyeri", 0 );
    if(coid == -1)
    {
        printf("could not creatw channel--> errno : %d \n", errno);
    }
    else
    {
        printf("[CLIENT] mertinyeri opened \n");
    }
    
    printf("[CLIENT] sending data... \n");

    SETIOV(&siov[0], &header, sizeof(io_devctl_t));
    SETIOV(&siov[1], &smsg, sizeof(myMessage_t));

    sid = MsgSendv(coid, siov, MERTINYERI_ARRAY_SIZE, riov, MERTINYERI_ARRAY_SIZE);
    
    if(sid == -1)
    {
        printf("[CLIENT] could not send  data--> errno : %d \n", errno);
        return 0;
    }
    
    printf("[CLIENT] data sent! \n");
    

    name_close(coid);
}