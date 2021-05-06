
#include <sys/neutrino.h>
#include <process.h>
#include <stdio.h>

typedef union {
    struct _pulse pulse;
    // other message types you will receive
} myMessage_t;

int pid;
int chid;
int rcvid;
myMessage_t msg;

int main()
{
    const void* rmsg = 20;
    pid =getpid();
    chid = ChannelCreate(0);
    printf("[SERVER] Process id : %d \n", pid);
    printf("[SERVER] Channel id : %d \n", chid);

    while(1){

            printf("[SERVER]Waiting to receive.. \n");

            rcvid = MsgReceive(chid, &msg, sizeof(msg), NULL);

            if (rcvid == 0) 
            {
                printf("[SERVER]pulse code   : %d \n",msg.pulse.code);
                printf("[SERVER]pulse value  : %d \n",msg.pulse.value.sival_int);
                
                // it’s a pulse, look in msg.pulse… for data
            } 
            else 
            {
                 // it’s a regular message
                 printf("[SERVER] rcvid : %d ", rcvid);
            }

            MsgReply(rcvid, 1, &rmsg, sizeof(rmsg));
            printf("[SERVER]Replied with  %d \n", (int*) rmsg );
    }
    
    return 0;
}


