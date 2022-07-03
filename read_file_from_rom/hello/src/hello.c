
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    // no dependency from vfs_entity when using stderr
    fprintf(stderr,"Hello world! argc = %d\n",argc); 

    if(argc>1) {
        for(int i=1;i<argc;i++)
          fprintf(stderr," Argv = %s\n",argv[i]);
    }

    return EXIT_SUCCESS;
}
