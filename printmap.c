#include <stdio.h>
#include <stdlib.h>
#include "printmap.h"

extern int map[17][17];

void printMap(int x,int y) {
    //function for print game map
	    system("clear");
    int i, j;
    for(i=0; i<x; i++) {
        for(j=0; j<y; j++) {
            if(map[i][j]==7) printf("\033[1;33mC ");
            else if(map[i][j]==-1) printf("\033[1;31mX ");
            else if(map[i][j]==5) printf("\033[1;32mV ");
            else if(map[i][j]==6) printf("\033[1;37mR ");
            else printf("\033[1;36m%d ", map[i][j]);
        }
        printf("\n");
    }
}