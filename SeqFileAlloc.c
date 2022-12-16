#include <stdio.h>
#include<string.h>

void main()
{
    int disk[20], block, sb, len, count = 0;
    int fname;
    char con;
    
    //initialize all blocks as empty.
    for(block=0;block<20;block++)
        disk[block]=0;
    
    x: count = 0;    
    printf("Enter filename(int): ");
    scanf("%d", &fname);
    printf("Starting block of a file: ");
    scanf("%d", &sb);
    printf("Length of the file: ");
    scanf("%d", &len);
    
    //check if the blocks are empty
    int i;
    for(i = sb; i < (sb + len); i++)
        if(disk[i] == 0)
            count++;
    
    // all required blocks are empty    
    if(len == count)
    {
        int j;
        for(j = sb; j < (sb + len); j++)
            //occupy blocks
            if(disk[j] == 0)
                disk[j] = 1;
        printf("The file is allocated to disk\n");
    }
    else
    {
        printf("The file can't allocated \n");
        if(sb < 0 || sb > 20)
            printf("Starting block not in memory.");
        if(len > 20)
            printf("File size greater than memory.\n");
        else
            printf("Disk blocks are not available.\n");
    }
        printf("Do you want to add more file(Yes -y)?");
        scanf("%s", &con);
        if(con=='y')
            goto x;
            printf("Remaining empty blocks:\n");
            for(i = 0; i<20; i++)
                if (disk[i] == 0)
                    printf("%d \t",i);
                    //printf("%d\t%d\n", i,disk[i]);
}
