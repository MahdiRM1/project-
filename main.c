#include <stdio.h>
#include <stdlib.h>
#include "printmap.h"
#include "generateArray.h"
#include "road.h"


int map[17][17]; //main array

const int maxv=10;

int main() {
		int n, i;
		int x, y;
		clearScreen();
		printf("enter x and y for map:");//game map
		scanf("%d %d", &x, &y);
		generate_array(x,y);
		Node c;
		printf("enter location of teriory:");
		scanf("%d %d", &c.x, &c.y);
		c.x--;
		c.y--;
		map[c.x][c.y] = 7;

		int v;
		Node Vill[10];
		printf("enter number of villages:");
		scanf("%d", &v);
		for(i=0; i<v; i++) {
			int pi, qi;
			printf("enter location of village %d:", i+1);
			scanf("%d %d", &pi, &qi);
			Vill[i].x = pi - 1;
			Vill[i].y = qi - 1;
			map[Vill[i].x][Vill[i].y] = 8;
		}

		printf("enter number of blocked houses:");
		scanf("%d", &n);
		for(i=0; i<n; i++) {
			int pi, qi;
			printf("enter location of blocked house %d:", i+1);
			scanf("%d %d", &pi, &qi);
			map[pi-1][qi-1] = -2;
		}

		clearScreen();
		printMap(x,y);

		printf("do you want to continue To see the roads?\n0 for No\n1 for Yes\n");
		scanf("%d", &i);
		if(!i) return 0;//finish

		Path path;

		clearScreen();
		for(i=0;i<v;i++){
		int countRoad;
		int countPrice;
    	a_star(c, Vill[i], &path, i);
		}

		printMap(x,y);

		printf("press any key to exit\n");
		scanf("%d", &i);

		return 0;
	}
