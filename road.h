
#ifndef ROAD_H
#define ROAD_H

#define ROWS 17
#define COLS 17
#define INF 1000000

typedef struct{
    int x, y;
}Node;

typedef struct {
    Node nodes[ROWS * COLS];
    int size;
} Path;

typedef struct {
    Node node;
    int f;
} PriorityNode;


typedef struct {
    PriorityNode elements[ROWS * COLS];
    int size;
} PriorityQueue;


void push(PriorityQueue *pq, PriorityNode pn);
PriorityNode pop(PriorityQueue *pq);
int is_in_priority_queue(PriorityQueue *pq,Node node);
int heuristic(Node a, Node b);
int is_valid(int x, int y);
void reconstruct_path(Node came_from[ROWS][COLS], Node current, Path *path);
void a_star(Node start, Node goal, Path *path);
#endif 