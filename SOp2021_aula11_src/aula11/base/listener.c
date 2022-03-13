/**
 * \brief the client
 * \author Artur Pereira <artur@ua.pt>
 */

#include "comm.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    MESSAGE msg;

    /* opening the communication channel */
    cliOpenComm();

    /* use the service */
    while(1) {
      

        /* getting response */
        cliReceive(&msg);

        /* printing received message */
        printf("Message received: %s", msg.data);
    }
    return 0;
}
