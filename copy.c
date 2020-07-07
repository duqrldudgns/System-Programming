#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
        if (argc < 3 ) {
                printf("Usage : %s <filename1> .. <filename N> <directoryname>\n", argv[0]);
                return 0;
        }

        FILE *fd, *dest;
        char buf[257];
        char dir[50];
        int len;

        for(int i=1;i<argc-1;i++)
        {
                memset(dir, 0, 50);
                sprintf(dir, "./%s/%s",argv[argc-1] ,argv[i]);

                //printf("int : %d, dir : %s \n",i, dir);

                fd = fopen(argv[i], "r");
                if((dest = fopen(dir, "w")) == NULL) {
                        printf("%s directory open failed \n",argv[i+1]);
                        printf("Before running, the target directory must be created\n");
                        printf("Usage : %s <filename1> .. <filename N> <directoryname>\n", argv[0]);
                        return 0;
                }

                while ( len = fread(buf, 1, 256, fd) )
                {
                        buf[len] = '\0';
                        fwrite(buf, 1, len, dest);
                        //printf("Length : %d\n", len);
                        //printf("%s", buf);
                }

                fclose(dest);
                fclose(fd);

        printf("%s copy success \n",argv[i]);
        }

        return 0;
}
