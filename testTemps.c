#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h> 
#define MINUTE_TEST 50


int h , min , s , day , mois , an; 
time_t now; // time_t est un long int permettant de stocker le nombre de seconde depuis 
	    // le premier juin 1970 
time_t calcule; 

typedef struct temp{

  int min ;
  int h; 
  int jour;
  int mois; 
  int an; 
}temp;  




void calculTemps (temp *Temp){
       
    struct tm *tempCalcule;
    time(&now); 
    struct tm *local = localtime(&now); // local time ne fait QUE CONVERTIR 
    calcule = now+50*60;
    tempCalcule = localtime(&calcule); 
    Temp->min = tempCalcule->tm_min; 
    Temp->h = tempCalcule->tm_hour; 
    Temp->jour = tempCalcule->tm_mday; 
    Temp->mois = tempCalcule->tm_mon+1; 
    Temp->an = tempCalcule->tm_year+1900; 
}






int main(void){


    char dateCalcule[100]; 
    char dateNow[100];  
    struct temp temp_calcule; 

    calculTemps(&temp_calcule); 
   

    time(&now); 
    struct tm *local = localtime(&now); // local time ne fait QUE CONVERTIR 

    sprintf(dateCalcule , "%d:%02d:%02d:%02d:%02d" , temp_calcule.an , temp_calcule.mois , temp_calcule.jour , temp_calcule.h, 
		    temp_calcule.min); 
   

    sprintf(dateNow, "%d:%02d:%02d:%02d:%02d" , local->tm_year+1900 , local->tm_mon+1 , local->tm_mday , local->tm_hour ,
		    local->tm_min);

    printf(" la date maintenant : %s vs la date calculee : %s " , dateNow , dateCalcule); 

    printf(" \n la date maintenant : %02d vs la date calculee : %02d " , local->tm_min  , temp_calcule.min);
    
    for(;;){
    
        if(strcmp(dateCalcule , dateNow) == 0){
	
	   system("
	
	}
    
    
    
    } 
}
