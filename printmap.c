#include <stdio.h>
#include <stdlib.h>
#include "printmap.h"

extern int map[17][17];

void clearScreen() {
    //function for clear screen
    system("clear");
}

void printMap(int x,int y) {
    //function for print game map
    int i, j;
    for(i=0; i<x; i++) {
        for(j=0; j<y; j++) {
            if(map[i][j]==7) printf("🏰");
            else if(map[i][j]==-2) printf("❌");
            else if(map[i][j]==8) printf("🌳");
            else if(map[i][j]==0) printf("🛣 ");
            else if(map[i][j]==1) printf("1️⃣ ");
            else if(map[i][j]==2) printf("2️⃣ ");
            else if(map[i][j]==3) printf("3️⃣ ");
            else if(map[i][j]==4) printf("4️⃣ ");

        }
        printf("\n");
    }
}
