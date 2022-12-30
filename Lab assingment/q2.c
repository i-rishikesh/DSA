#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ONE_YEAR_IN_SECONDS 31536000

// Lists
struct ShoppingCard {
    int ID,
        points;
    char custName[100],
        address[100];
    time_t DOB, 
        lastTrans;

    struct ShoppingCard *next;
};

// Points per 100 Rs spent
typedef enum { 
    GROCERY = 1, 
    GARMENTS = 5, 
    ELECTRONICS = 10 
} ItemCategory;
struct Item {
    int ID, qty;
    float price;
    char name[100];
    ItemCategory cat;

    struct Item *next;
};

// Header
struct ShoppingMall {
    int totalCards, totalItems;
    // ===================================
    // INCREMENT-ONLY vals
    int lastCardID, lastItemID;
    // DISCOUNT RELATED
    // Stores the remaining entries for discount
    int last10DisID, last15DisID;
    // ===================================
    struct ShoppingCard *cards;
    struct Item *items;
};

// Header related stuff
struct ShoppingMall* initMall();
void display( struct ShoppingMall* );
void give10d( struct ShoppingMall* );
void give15d( struct ShoppingMall* );
// Mall related stuff, includes both Item/Card
void purchaseItem( struct ShoppingMall*, struct Item*, struct ShoppingCard*, int );

// Item related
void addItem( struct ShoppingMall*, ItemCategory, int, float, char[] );
void displayItems( struct ShoppingMall* );
int inStock( struct Item* );
// Find item by ID
struct Item* findItem( struct ShoppingMall*, int );

// Card related
void addCard( struct ShoppingMall*, char*, char*, time_t );
void displayCards( struct ShoppingMall* );
void updateAddr( struct ShoppingCard*, char* );
void displayCard( struct ShoppingCard* );
void delOld( struct ShoppingMall* );
// Find card by ID
struct ShoppingCard* findCard( struct ShoppingMall*, int );

struct ShoppingMall* initMall(){
    struct ShoppingMall *sm = (struct ShoppingMall*)malloc( sizeof( struct ShoppingMall ) );
    sm->totalCards = 0;
    sm->totalItems = 0;
    sm->lastItemID = -1;
    sm->lastCardID = -1;
    sm->cards = NULL;
    sm->items = NULL;
}

void display( struct ShoppingMall* sm ){
    printf("==== SHOPPING MALL DETAILS ===\n");
    printf("Total cards: %d\nTotal items: %d\n\n", sm->totalCards, sm->totalItems );
}

void purchaseItem( struct ShoppingMall *sm, struct Item* i, struct ShoppingCard* c, int qty ){
    if( i == NULL || c == NULL ){
        printf("Item or card doesn't exist.");
        return;
    }
    if( !inStock(i) ){
        printf("Item is out of stock.\n");
        return;
    }
    if( qty > i->qty ){
        printf("You can't buy more than what's available.");
        return;
    }
    int points = ( (i->cat)*(i->price)*qty / 100);
    // 10% discount if points over 1000
    if( c->points > 1000 && sm->last10DisID > 0 ){
        sm->last10DisID--;
        points *= 0.9;
        // 15% discount if points over 1000 and age over 60
        if( time(NULL) - c->DOB > ONE_YEAR_IN_SECONDS*60 )
            points *= 0.85;
    }

    // Decrease quantity
    i->qty -= qty;
    // Add points
    c->points += points;
    c->lastTrans = time(NULL);
}

void give10d( struct ShoppingMall *sm ){
    sm->last10DisID += 10;
}

void give15d( struct ShoppingMall *sm ){
    sm->last15DisID += 5;
}

void addItem( struct ShoppingMall* sm, ItemCategory cat, int qty, float price, char* name ){
    struct Item *i = (struct Item*)malloc( sizeof( struct Item ) );
    // Details
    i->qty = qty;
    i->price = price;
    i->cat = cat;
    strcpy( i->name, name );
    i->next = NULL;
    // Set ID
    sm->lastItemID++;
    i->ID = sm->lastItemID;

    if( sm->totalItems == 0 ){
        sm->items = i;
        sm->totalItems++;
        return;
    }

    struct Item *temp = sm->items;
    while( temp->next != NULL )
        temp = temp->next;
    
    temp->next = i;
    sm->totalItems++;
}

void displayItems( struct ShoppingMall* sm ){
    struct Item *i = sm->items;
    printf("\n=== ITEM LIST START ===");
    while( i != NULL ){
        printf("\nID: %d\n", i->ID);
        printf("Name: %s\nPrice: %.2f\nStock: %d\n", i->name, i->price, i->qty);
        printf("Category: ");
        switch( i->cat ){
            case GROCERY:
                printf("Grocery");
                break;
            case GARMENTS:
                printf("Garments");
                break;
            case ELECTRONICS:
                printf("Electronics");
                break;
        }
        printf("\n");

        i = i->next;
    }
    printf("\n=== ITEM LIST END ===\n");
}

int inStock( struct Item* i ){
    return (i->qty!=0);
}

struct Item* findItem( struct ShoppingMall* sm, int id ){
    struct Item* i = sm->items;
    while( i != NULL ){
        if( id == i->ID )
            return i;
        if( i->ID > id )
            return NULL;
        i = i->next;
    }
}

void addCard( struct ShoppingMall* sm, char* name, char* addr, time_t DOB ){
    struct ShoppingCard *c = (struct ShoppingCard*)malloc( sizeof( struct ShoppingCard ) );
    // Details
    strcpy( c->custName, name );
    strcpy( c->address, addr );
    c->DOB = DOB;
    c->next = NULL;
    // Set ID
    sm->lastCardID++;
    c->ID = sm->lastCardID;

    if( sm->totalCards == 0 ){
        sm->cards = c;
        sm->totalCards++;
        return;
    }

    struct ShoppingCard *temp = sm->cards;
    while( temp->next != NULL )
        temp = temp->next;
    
    temp->next = c;
    sm->totalCards++;
}

void displayCards( struct ShoppingMall* sm){
    struct ShoppingCard *c = sm->cards;
    printf("\n=== CARD LIST START ===");
    while( c != NULL ){
        displayCard(c);
        c = c->next;
    }
    printf("\n=== CARD LIST END ===\n");
}

void displayCard( struct ShoppingCard *c ){
    
    printf("\nID: %d\nName: %s", c->ID, c->custName);
    printf("\nPoints: %d\nAddress: %s", c->points, c->address);
    {
        struct tm *p = gmtime(&c->DOB);
        printf("\nDOB: %s", asctime(p));
    }
    {
        struct tm *p2 = gmtime(&c->lastTrans);
        printf("Last transaction: %s", asctime(p2));
    }
}

void updateAddr( struct ShoppingCard* c, char *addr){
    strcpy( c->address, addr );
}

void delOld( struct ShoppingMall* sm ){
    struct ShoppingCard *c = sm->cards, *par;
    while( c->next != NULL ){
        par = c;
        c = c->next;
        time_t t = time(NULL);
        if( t - c->lastTrans > ONE_YEAR_IN_SECONDS ){
            par->next = c->next;
        }
    }
}

struct ShoppingCard* findCard( struct ShoppingMall* sm, int id ){
    struct ShoppingCard *c = sm->cards;
    while( c != NULL ){
        if( id == c->ID )
            return c;
        if( c->ID > id )
            return NULL;
        c = c->next;
    }
}

int main(){
    struct ShoppingMall *sm = initMall();
    addItem(sm, ELECTRONICS, 10,100.0,"Test");
    addItem(sm, ELECTRONICS, 10,100.0,"Test");
    addCard(sm, "Sat", "Golden", time(NULL) );
    display(sm);
    displayItems( sm );
    displayCards( sm );
    while(1){
        int in;
        printf("1. Create card\n2. Create item\n3. List cards\n");
        printf("4. List items\n5. Buy item\n6. Show details\n");
        printf("7. Delete unused customers\n8. Apply 10%% discount\n");
        printf("9. Apply 15%% discount for senior citizens\n");
        printf("10. Display shopping mall info\n11. Exit\nYour choice: ");
        scanf("%d", &in);

        // INPUTS:
        char name[100], addr[100];
        long dob;
        int id, qty;
        float price;

        switch( in ){
            case 1:
                printf("Enter name, address, DOB: ");
                scanf("%s %s %ld", name, addr, &dob);
                addCard( sm, name, addr, dob);
                break;
            
            case 2:
                printf("Category IDs:\n%d - Grocery\n%d - Garments",
                        GROCERY,
                        GARMENTS
                    );
                printf("\n%d - Electronics\n", ELECTRONICS);
                printf("Enter category ID, qty, price, item name: ");
                scanf("%d %d %f %s", &id, &qty, &price, name);
                addItem( sm, id, qty, price, name );
                break;
            
            case 3:
                displayCards( sm );
                break;
            
            case 4:
                displayItems( sm );
                break;
            
            case 5:
                printf("Enter item ID, card ID and quantity: ");
                int iID, cID;
                scanf("%d %d %d", &iID, &cID, &qty);
                purchaseItem( sm, findItem( sm, iID ), findCard( sm, cID ), qty );
                break;
            
            case 6:
                printf("Enter card ID: ");
                scanf("%d", &id);
                struct ShoppingCard *c = findCard( sm, id );
                if( c == NULL )
                    printf("Invalid card details.\n");
                else
                    displayCard( c );
                
                break;

            case 7:
                delOld( sm );
                printf("Deleted old customers.\n");
                break;
            
            case 8:
                give10d( sm );
                printf("Applied 10%% discount for customers.\n");
                break;

            case 9:
                give15d( sm );
                printf("Applied 15%% discount for senior citizens.\n");
                break;
            
            case 10:
                display( sm );
                break;
            
            case 11: exit(0);
        }
    }
}