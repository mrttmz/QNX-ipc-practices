
#include <sys/neutrino.h>
#include <stdio.h>

int chid;
int rcvid;
void * msg;

int main()
{
    /**First, a channel is created with ChannelCreate 
     * return value of this function (chid) will be used for client processes
     * to create a connection
    */
    const void* rmsg = 20;
    chid = ChannelCreate(0);
    printf("[SERVER] Channel id : %d \n", chid);

    while(1){

            /**MsgReceive functions waits until a it receives a msg from client */
            printf("[SERVER]Waiting to receive.. \n");
            rcvid = MsgReceive(chid, &msg, sizeof(msg), NULL);
            printf("[SERVER]Received %d \n", (int*) msg );

            /**MsgReply function replies after Server receives a message, so it uses rcvid
             * while for reply, here reply message is 20.
            */
            MsgReply(rcvid, 1, &rmsg, sizeof(rmsg));
            printf("[SERVER]Replied with  %d \n", (int*) rmsg );
    
    /**Server is always running in while loop since there are no crashes
     * after MsgReply server waits for a new message to receive. Any connection 
     * from any client is accepted since chid is pid is configured properly
     */
    }
    
    return 0;
}