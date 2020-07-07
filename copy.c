int main(int argc, char *argv[])
{
        if (argc < 3 ) {
                //printf("Usage : %s <filename1> <filename2>\nor\n", argv[0]);
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
                strcat(dir,"./");
                strcat(dir,argv[argc-1]);
                strcat(dir,"/");
                strcat(dir,argv[i]);

                //printf("int : %d, dir : %s \n",i, dir);

                fd = fopen(argv[i], "r");
                dest = fopen(dir, "w");

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
