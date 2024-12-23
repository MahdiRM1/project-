#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generateArray.h"

extern int map[17][17];

int generate_number() {//randomize road difficulty
    const double probs [9] = {0.65, 0.25, 0.05, 0.05, 0, 0, 0, 0, 0};
    double cdf [9];
    cdf [0] = probs [0];
    for (int i=1; i < 9; ++i) {
        cdf [i] = cdf [i-1] + probs[i];
    }
    double rand_val = (double) rand() / RAND_MAX;
    for (int i=0; i<9; ++i) {
        if (rand_val < cdf[i]) return (char)(i + 1);
    }
    return -1;
}

void generate_array(int x, int y) {
    srand(time(NULL));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            map[i][j] = generate_number();
        }
    }
}