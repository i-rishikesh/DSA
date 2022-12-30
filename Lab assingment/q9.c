/*Suppose the locations of ATMs of different banks are represented by nodes in a
graph with information: &lt;ATM ID, BANK ID, CITY ID, LOCATION ID&gt;. Write a pseudo
code/ algorithm to find the nearest ATM of a given Bank from a given location. Then,
find the subsequent neighbouring ATMSs as per user’s requirement.*/
#include <stdio.h>
#include <stdlib.h>

struct ATM {
    int atmID, bankID, cityID, locationID;
};

// Forward declaration
struct Edge;

struct Graph {
    // data is the data stored
    struct ATM *data;
    // status is the processed state
    int status;
    // edges of each graph
    struct Edge *edgeList;
    // link to next element
    struct Graph *next;
};

struct Edge {
    struct Graph *link;
    struct Edge *next;
};

struct Graph* crG( struct ATM *data ){
    struct Graph *new = (struct Graph*)malloc( sizeof(struct Graph) );
    new->data = data;
    new->status = 1;
    new->edgeList = NULL;
    new->next = NULL;
    return new;
}

struct Edge* crE( struct Graph* link ){
    struct Edge *new = (struct Edge*)malloc( sizeof(struct Edge) );
    new->link = link;
    new->next = NULL;
    return new;
}

struct ATM* crA( int atmID, int bankID, int cityID, int locationID ){
    struct ATM *n = (struct ATM*)malloc( sizeof( struct ATM ) );
    n->atmID = atmID;
    n->bankID = bankID;
    n->cityID = cityID;
    n->locationID = locationID;
    return n;
}

void displayATM( struct ATM *node ){
    printf("ATM ID: %d\nBank ID: %d\n", node->atmID, node->bankID);
    printf("City ID: %d\nLocation ID: %d\n", node->cityID, node->locationID);
}

void BFS( struct Graph* g ){
    // Queue
    // ========================================================================
    struct Graph *Q[100];
    int f = 0, r = 0;
    Q[r++] = g;
    g->status = 2;
    // ========================================================================
    while( f != r ){
        g = Q[f++];
        displayATM( g->data );
        g->status = 3;
        // Add edges
        struct Edge *list = g->edgeList;
        while( list != NULL ){
            if( list->link->status == 1 ){
                Q[r++] = list->link;
                list->link->status = 2;
            }
            list = list->next;
        }
    }
}


int main(){
    // Graph creation
    struct Graph *g = crG( crA( 0, 0, 0, 0 ) );
    g->next = crG( crA( 1, 0, 1, 1 ) );
    g->edgeList = crE(g->next);

    // BFS
    printf("Nearby reachable ATMs: \n");
    BFS(g);
    printf("\n");
}
