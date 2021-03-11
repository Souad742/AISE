#include <sys/sysctl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

void getMemory()
{
    FILE *meminfo = fopen("/proc/meminfo", "r");
    int totalMemory = 0;
    if(meminfo == NULL)
    {
        exit(-1);
    }
    char buff[256];
    while(fgets(buff, sizeof(buff), meminfo))
    {
        int ramKB;
        if(sscanf(buff, "MemTotal: %d kB", &ramKB) == 1)
        {
            totalMemory = ramKB;

        }
    }
    /*if(fclose(meminfo) != 0)
    {
        exit(-1);
    }*/
     (fclose(meminfo));
    printf("total memory :%d\n", totalMemory);
}


   

 
