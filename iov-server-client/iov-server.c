#include <stdio.h>
#include <sys/iofunc.h>
#include <sys/dispatch.h>
#include <stdlib.h>
#include "iov.h"

myMessage_t msg;

name_attach_t *attach;

char* rbuf;


int rcvid;
int bytes_received;


int main()
{

    attach = name_attach( NULL, "mertinyeri", 0 );

    if(attach == NULL)
    {
        perror("name_attach");
        return 0;
    }

    while(1)
    {
        printf("[SERVER]Waiting to receive.. \n");
        rcvid = MsgReceive( attach->chid, &msg ,sizeof(msg), NULL );
   

        if(rcvid == -1 )
        {
            printf("[SERVER]could not receive msg. \n");
            return 0;
        }
        else if(rcvid == 0)
        {
            printf("[SERVER]pulse data received. \n");
        }
        
        else
        {
            printf("[SERVER]received normal data \n");
            printf("msg : %s\n", sizeof(msg.messageFromMert));
            rbuf = malloc(sizeof(io_devctl_t)+sizeof(myMessage_t));
            bytes_received = MsgRead(rcvid, rbuf, sizeof(myMessage_t), sizeof(io_devctl_t));
            printf("[SERVER]received bytes : %d \n", bytes_received);
        }


    }


    name_detach( attach, 0 );

}