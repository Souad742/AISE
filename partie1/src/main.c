#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fnmatch.h>
#include <sys/types.h>
#include <string.h>
#include <sys/sysctl.h>
#include <time.h>
#include "info.h"
   




int main(int argc, char ** argv) 
{
    
     getMemory(); 

     printf("\033[32m%s\033[00m","\tPID\t TIME\t          MEMORY\n");
     DIR *procdir;
     struct dirent *procentry;

     procdir = opendir("/proc");
     if (procdir == NULL) {
         perror("Could not open directory /proc");
         return 1;
     }

     for(;;) {
         procentry = readdir(procdir);
         if (procentry == NULL) {
             break;
         }
         /* if the name of an entry in /proc has only digits, then
          * it is a subdirectory containg info about a process,
          * while the name itself is the PID of the process.
          */        
         if (!fnmatch("[1-9]*", procentry->d_name, 0)) {
             
             processdir(procentry);
         }
     }
     //printf("PID %s MEM %s Time %lf ", piddir->d_name, memstr, cpu_time_used);
     return 0;
}
