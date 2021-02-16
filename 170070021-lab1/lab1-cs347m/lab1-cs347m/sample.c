#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
    char buf[512];
    int n;

    while(1) {
        n = read(0, buf, sizeof(buf));
        if(n==0) break;
        if(n<0) {
            fprintf(stdout, "Main; read error\n");
            exit(-1);
        }

        if(write(1, buf, n) != n) {
            fprintf(stdout, "Main; write error\n");
            exit(-1);
        }
    }

    return 0;
}