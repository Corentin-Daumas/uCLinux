#include <stdio.h>
#include "libSerie.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <termios.h>

/* Definitions de MACRO */
#define ERROR -1
#define LBUF 256
static int RUN=1;

int main(int N, char *P[])
{
int fd, speed, n;
char rcv_buf[LBUF];

    if (N != 3) {
       printf("Utilisation: %s /dev/ttyXX vitesse_en_baud\n",P[0]);
       return 1;
    }
    signal(SIGINT, interrupt);
    if ((fd = UART_Open(P[1])) == ERROR) return 2;
    speed = atoi(P[2]);
    if (UART_Init(fd,speed, 0,8,1,0,1,'N') == ERROR) return 3;
    /* boucle de lecture */
    while (RUN) {
        n = UART_Recv(fd, rcv_buf,LBUF);
        if (n > 0) {
           rcv_buf[n] = '\0';
           printf("%s",rcv_buf);
        } else {
           fprintf(stderr,"Erreur lecture !!\n");
           break;
        }
    }
    printf("Au revoir !\n");
    UART_Close(fd);
    return 0;
}
