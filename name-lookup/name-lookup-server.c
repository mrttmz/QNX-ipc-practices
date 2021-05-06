#include <stdio.h>
#include <sys/iofunc.h>
#include <sys/dispatch.h>
#include "namelookup.h"

name_attach_t *attach;
myMessage_t msg;
int rcvid;


int main()
{

    attach = name_attach( NULL, "aa", 0 );

    while(1)
    {
        printf("[SERVER]Waiting to receive.. \n");
        rcvid = MsgReceive( attach->chid, &msg, sizeof(msg), NULL );

        if(rcvid == -1 )
        {
            printf("[SERVER]could not receive msg. \n");
        }
        else if(rcvid == 0)
        {
            printf("[SERVER]pulse data received. \n");

            switch(msg.pulse.code) { //decides what kind of pulse is it?

                case _PULSE_CODE_DISCONNECT: //client disconnected

                     printf("[SERVER]pulse data received.Client disconnected \n");
                     break;

                case _PULSE_CODE_UNBLOCK: //client wants to unblock

                     printf("[SERVER]pulse data received.Client wants to unblock \n");
                     break;

                default :
                     printf("[SERVER]Received data : pulse code--> %d , pulse sival--> %d \n");
            }
        }
        
        else
        {
            printf("[SERVER]received normal data \n");
        }


    }


    name_detach( attach, 0 );

}