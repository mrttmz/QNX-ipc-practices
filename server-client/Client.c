
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <stdio.h>
#include <stdlib.h>

int coid;
int chid;
int pid;

void* rmsg;

int main(int argc, char* argv[])
{
    /**Here we take pid and chid from arguments. 
     * Server process must be initialized before Client to observe pid and chid
     * pid is process id of Server process
     * chid is channel id of server. Return value of ChannelCreate function
     * 
     * */

    pid = atoi(argv[1]);
    chid = atoi(argv[2]);
    printf ("pid : %d , chid %d \n", pid, chid);

    /**The message that will be sent is 15, it will be sent after connection created.
     * Client connects to the server by opening a connection, it uses pid and
     * chid that we took from Server before while opening connection
     *  */
    const void* smsg = 15;
    coid = ConnectAttach(ND_LOCAL_NODE, pid, chid, _NTO_SIDE_CHANNEL, 0);
    printf("[CLIENT] Connection id : %d \n", coid);
    
    MsgSend(coid, &smsg, sizeof(smsg), &rmsg, sizeof(rmsg));
    printf("[CLIENT]Sent 15.. \n");
    
    
    return 0;


}