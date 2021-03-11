
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fnmatch.h>
#include <sys/types.h>
#include <string.h>
#include <sys/sysctl.h>

#define BUFSZ 1024
#define MEM_FIELD_NAME "VmSize:"/* mémoire physique + swap*/
#include <time.h>
clock_t start, end;
double cpu_time_used;

void getMemory()
{

     int totalMemory = 0;
    //ouvrir le fichier meminfo en lecture là ou il ya toutes les informations sur l'utilisation de la mémoire 
    FILE *meminfo = fopen("/proc/meminfo", "r");
    
    if(meminfo == NULL)
    {
        printf("erreur, le repertoire vide!!");
        exit(-1);
    }
    char buff[256];
    //tant qu'on lit on affiche la capacité de la mémoire
    while(fgets(buff, sizeof(buff), meminfo))
    {
        int ram;
        if(sscanf(buff, "MemTotal: %d kB", &ram) == 1)
        {
            totalMemory = ram;

        }
    }
//fermer le descripteur du fichier déja ouvert (/proc/meminfo)
   (fclose(meminfo));
 //affichage de la capacité total de la mémoire
    printf("\tTOTAL MEMORY : %d\n \n", totalMemory);
}


void processdir(const struct dirent *piddir)
{
    char path[BUFSZ];
    char line[BUFSZ];
    char *memstr;
    FILE *pidmemfile;
    int  offset = strlen(MEM_FIELD_NAME);
    int time = 0;
    
    /* Construction du chemin complet du fichier contenant des informations de mémoire de ce  PID */
    snprintf(path, BUFSZ, "/proc/%s/status", piddir->d_name);
    
    /*ouvrir le fichier  */
    pidmemfile = fopen(path, "r");
    /*lire ligne par ligne jusqu'à ce qu'on arrive à la ligne qu'on veut*/
  
    while (fgets(line, BUFSZ, pidmemfile) != NULL) {
        memstr = strstr(line, MEM_FIELD_NAME);
        if (memstr != NULL) {  /* Found our line */
            start = clock();
            memstr += offset;
            end = clock();
           //calcul du temps écoulé
           cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
          // ++memstr;//aligned code
            
            
          
          
        
         //printf("PID TIME MEM");
         printf("\t%s\t %lf %s\n", piddir->d_name, cpu_time_used, memstr);
       
         break; 
            
         
        }
         
}
    
    fclose(pidmemfile);

}



