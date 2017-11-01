//stuff i created that maybe will be needed to be implemented into the client




void sendHeader(int sd,int type, char *filename, char *dir){

    char[1000] buffer;

    switch(type){
    case 1:
        sprintf(buffer,"%i %s",type,dir);
        break;
    case 2:
        sprintf(buffer,"%i %s",type,dir);
        break;
    case 3:
        sprintf(buffer,"%i %s %s",type,dir,filename);
        break;
    case 4:
        sprintf(buffer,"%i %s %s",type,dir,filename);
        break;
    default:
        exit(1);
        //error handle wew lad
    }

    write(sd,buffer,sizeof(buffer));

}
const char *getLS(int sd){

    FILE *fp;
    fp = popen("/bin/ls /etc", "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }
    int len = lseek(fp,0,SEEK_END);

    char ls[len];

    fread(ls,len,1,fp);

    return ls;

}


void readLS(int sd){

    if ((nr = read(sd, buf, sizeof(buf))) <= 0)
         exit(0);

    printf(buf);

}
