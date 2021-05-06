
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <stdio.h>
#include <stdlib.h>

int coid;
int chid;
int pid;

typedef union {
    struct _pulse pulse;
    //TODO: implement other message types that you will receive
} myMessage_t;

void* rmsg;
myMessage_t smsg;
int priority;


int main(int argc, char* argv[])
{
    
    priority = 0;
    smsg.pulse.code = 22 ;
    smsg.pulse.value.sival_int = 33;

    pid = atoi(argv[1]);
    chid = atoi(argv[2]);
    printf ("pid : %d , chid %d \n", pid, chid);

    printf("[CLIENT] pulse code to send : %d \n", smsg.pulse.code);
    printf("[CLIENT] pulse value to send : %d \n", smsg.pulse.value.sival_int);

    coid = ConnectAttach(ND_LOCAL_NODE, pid, chid, _NTO_SIDE_CHANNEL, 0);
    printf("[CLIENT] Connection id : %d \n", coid);
    
    
    MsgSendPulse(coid, priority, smsg.pulse.code, smsg.pulse.value.sival_int);
    printf("[CLIENT]Sent done \n");
   
    
    return 0;


}


