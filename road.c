#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "road.h"

extern int map[17][17];

void push(PriorityQueue *pq, PriorityNode pn) {
    pq->elements[pq->size++] = pn;
    for (int i = pq->size - 1; i > 0; i--) {
        if (pq->elements[i].f < pq->elements[i - 1].f) {
            PriorityNode temp = pq->elements[i];
            pq->elements[i] = pq->elements[i - 1];
            pq->elements[i - 1] = temp;
        }
    }
}

PriorityNode pop(PriorityQueue *pq) {
    return pq->elements[--pq->size];
}

int is_in_priority_queue(PriorityQueue *pq, Node node) {
    for (int i = 0; i < pq->size; i++) {
        if (pq->elements[i].node.x == node.x && pq->elements[i].node.y == node.y)
            return 1;
    }
    return 0;
}

// فاصله منهتن
int heuristic(Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// بررسی داخل بودن در ماتریس
int is_valid(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS && map[x][y] != -2;
}

// بازسازی مسیر
void reconstruct_path(Node came_from[ROWS][COLS], Node current, Path *path) {
    path->size = 0;
    while (came_from[current.x][current.y].x != -1) {
        path->nodes[path->size++] = current;
        current = came_from[current.x][current.y];
    }
    path->nodes[path->size++] = current;
}

void a_star(Node start, Node goal, Path *path) {
    PriorityQueue open_set = { .size = 0 };
    Node came_from[ROWS][COLS];
    int g_score[ROWS][COLS];
    int f_score[ROWS][COLS];
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    Node best_goal = {-1, -1};
    int best_cost = INF;

    // مقداردهی اولیه
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            came_from[i][j] = (Node){-1, -1};
            g_score[i][j] = INF;
            f_score[i][j] = INF;
        }
    }

    g_score[start.x][start.y] = 0;
    f_score[start.x][start.y] = INF;

    push(&open_set, (PriorityNode){start, 0, f_score[start.x][start.y], f_score[start.x][start.y]});

    while (open_set.size > 0) {
        PriorityNode current = pop(&open_set);

            if (current.node.x == goal.x && current.node.y == goal.y) {
                if (g_score[current.node.x][current.node.y] < best_cost) {
                    best_cost = g_score[current.node.x][current.node.y];
                    best_goal = current.node;
                }
            }

        for (int i = 0; i < 4; i++) {
            int nx = current.node.x + directions[i][0];
            int ny = current.node.y + directions[i][1];

            if (is_valid(nx, ny)) {
                int tentative_g_score = g_score[current.node.x][current.node.y] + map[nx][ny];
                if (tentative_g_score < g_score[nx][ny]) {
                    came_from[nx][ny] = current.node;
                    g_score[nx][ny] = tentative_g_score;
                    f_score[nx][ny] = g_score[nx][ny];
                    if (!is_in_priority_queue(&open_set, (Node){nx, ny})) {
                        push(&open_set, (PriorityNode){{nx, ny}, g_score[nx][ny], f_score[nx][ny], f_score[nx][ny]});
                    }
                }
            }
        }
    }

    if (best_goal.x != -1) {
        reconstruct_path(came_from, best_goal, path);
    } else {
        path->size = 0; // مسیری پیدا نشد
    }
    	if (path->size > 0) {
        	for (int i = path->size - 1; i >= 0; i--) {
            	map[path->nodes[i].x][path->nodes[i].y] = 0;
        	}
    	} else {
        	printf("No path found.\n");
    	}
        map[start.x][start.y] = 7;
        map[goal.x][goal.y] = 8;
}