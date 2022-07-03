
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
    // no dependency from vfs_entity when using stderr
    fprintf(stderr,"Hello world! argc = %d\n",argc); 

    if(argc>1) {
        for(int i=1;i<argc;i++)
          fprintf(stderr," Argv = %s\n",argv[i]);
    }

    // Read file
    int fd;

    fd = open("/foo.cfg",O_RDONLY);

    if(fd<0) {
        fprintf(stderr,"Can't open foo.cfg\n"); 
    }

    char buf[1000];
    int cnt = read(fd,buf,100);

    if (cnt>0) {
        buf[10] = 0;
        fprintf(stderr,"Read: %s\n",buf);
    }
    else {
        fprintf(stderr,"Can't read foo.cfg\n"); 
    }
    close(fd);

    return EXIT_SUCCESS;
}
