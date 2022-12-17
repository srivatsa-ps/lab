#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>

void printcontents(char* dire, int tabcount){
    struct dirent* dirinfo;
    DIR* d = opendir(dire);
    if(d == NULL)
        return;
    while(dirinfo = readdir(d))
    {
        for(int i=0; i<tabcount; i++)printf("\t");
        printf("%s\n",dirinfo->d_name);
        if(dirinfo->d_type == DT_DIR)
            if(strcmp(dirinfo->d_name,".")!=0 && strcmp(dirinfo->d_name,"..")!=0)
                printcontents(dirinfo->d_name,tabcount+1);
    }
}

int main(int argc, char** argv){
    DIR* d = opendir(argv[1]);
    if(d==NULL){
        printf("directory does not exist\n");
        return 0;
    }
    printcontents(argv[1],0);
}
