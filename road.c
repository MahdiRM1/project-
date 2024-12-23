#include <stdio.h>
#include <stdlib.h>
#include "road.h"

extern int map[17][17];

void croadtov(int xc, int yc, int Villx[], int Villy[], int i, int x, int y){
    int a, b;
			a = xc;//xR
			b = yc;//yRs
			int count = 0;
			if(xc < Villx[i]) {
				for(a++; a<(Villx[i]-1); a++) {
					if(b == 0 && map[a+2][b] == -1 && map[a+1][b+1] == -1){
						map[a][b] = 6;
						b++;
						map[a][b] = 6;
						b++;
						map[a][b] = 6;
					}
					if(b == (y-1) && map[a+2][b] == -1 && map[a+1][b-1] == -1){
						map[a][b] = 6;
						b--;
						map[a][b] = 6;
						b--;
						map[a][b] = 6;
					}
					if(map[a][b] == -1){
						a--;
						if(map[a][b+1] == -1) {
							if(map[a][b-1] == -1) a--;
							b--;
						}
						else if(map[a][b-1] == -1) b++;
						if(!b) b++;
						else if(b==y) b--;
						else if(b < Villy[i]) b++;
						else b--;
					}
					map[a][b]=6;
				}
			}
			else if(xc > Villx[i]) {
				for(a--; a>(Villx[i]+1); a--) {
					if(b == 0 && map[a-2][b] == -1 && map[a-1][b+1] == -1){
						map[a][b] = 6;
						b++;
						map[a][b] = 6;
						b++;
						map[a][b] = 6;
					}
					if(b == (y-1) && map[a-2][b] == -1 && map[a-1][b-1] == -1){
						map[a][b] = 6;
						b--;
						map[a][b] = 6;
						b--;
						map[a][b] = 6;
					}
					if(map[a][b] == -1){
						a--;
						if(map[a][b+1] == -1) {
							if(map[a][b-1] == -1) a--;
							b--;
						}
						else if(map[a][b-1] == -1) b++;
						if(!b) b++;
						else if(b==y) b--;
						else if(b < Villy[i]) b++;
						else b--;
					}
					map[a][b]=6;
				}
			}
			else if(yc < Villy[i]) b++;
			else b--;

			if(b < Villy[i]) {
				for(; b<=Villy[i]; b++) {
					if(a == 0 && map[a][b+2] == -1 && map[a+1][b+1] == -1){
						map[a][b] = 6;
						a++;
						count++;
						map[a][b] = 6;
						a++;
						count++;
						map[a][b] = 6;
					}
					if(a == (x-1) && map[a][b+2] == -1 && map[a-1][b+1] == -1){
						map[a][b] = 6;
						a--;
						count--;
						map[a][b] = 6;
						a--;
						count--;
						map[a][b] = 6;
					}
					if(map[a][b] == -1){
						b--;
						if(map[a+1][b] == -1) {
							if(map[a-1][b] == -1) b--;
							a--;
						}
						else if(map[a-1][b] == -1) a++;
						if(!a) {a++;count++;}
						else if(a==x) {a--;count--;}
						else if(a < Villx[i]) {a++;count++;}
						else {a--;count--;}
					}
					if(a==Villx[i] && b==Villy[i]) break;
					map[a][b]=6;
				}
			}
			else {
				for(; b>=Villy[i]; b--) {
					if(a == 0 && map[a][b-2] == -1 && map[a+1][b-1] == -1){
						map[a][b] = 6;
						a++;
						count++;
						map[a][b] = 6;
						a++;
						count++;
						map[a][b] = 6;
					}
					if(a == (x-1) && map[a][b-2] == -1 && map[a-1][b-1] == -1){
						map[a][b] = 6;
						a--;
						count--;
						map[a][b] = 6;
						a--;
						count--;
						map[a][b] = 6;
					}
					if(map[a][b] == -1){
						b--;
						if(map[a+1][b] == -1) {
							if(map[a-1][b] == -1) b--;
							a--;
						}
						else if(map[a-1][b] == -1) a++;
						if(!a) {a++;count++;}
						else if(a==x) {a--;count--;}
						else if(a < Villx[i]) {a++;count++;}
						else {a--;count--;}
					}
					if(a==Villx[i] && b==Villy[i]) break;
					map[a][b]=6;
				}
			}
			b = Villy[i];
			if (count<0){
				for(count++;count<0;count++) {a++;map[a][b] = 6;}
			}
			else if (count>0){
				for(count--;count>0;count--) {a--;map[a][b] = 6;}
            } 
		}