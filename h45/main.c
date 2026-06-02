
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int compartmentNumber;
    int seatCount;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
} Railway;

void initRailway(Railway *railway)
{
    railway->head = NULL;
}

Node *createCompartment(int compartmentNumber, int seatCount)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->compartmentNumber = compartmentNumber;
    newNode->seatCount = seatCount;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addAtFront(Railway *railway, int compartmentNumber, int seatCount)
{
    Node *newNode = createCompartment(compartmentNumber, seatCount);
    
    if (railway->head == NULL)
    {
        railway->head = newNode;
        printf("Added compartment %d at front (Seats: %d)\n", 
               compartmentNumber, seatCount);
    }
    else
    {
        newNode->next = railway->head;
        railway->head->prev = newNode;
        railway->head = newNode;
        printf("Added compartment %d at front (Seats: %d)\n", 
               compartmentNumber, seatCount);
    }
}

void addAtEnd(Railway *railway, int compartmentNumber, int seatCount)
{
    Node *newNode = createCompartment(compartmentNumber, seatCount);
    
    if (railway->head == NULL)
    {
        railway->head = newNode;
        printf("Added compartment %d at end (Seats: %d)\n", 
               compartmentNumber, seatCount);
    }
    else
    {
        Node *current = railway->head;
        
        while (current->next != NULL)
        {
            current = current->next;
        }
        
  
        current->next = newNode;
        newNode->prev = current;
        printf("Added compartment %d at end (Seats: %d)\n", 
               compartmentNumber, seatCount);
    }
}
void removeCompartment(Railway *railway, int compartmentNumber)
{
    if (railway->head == NULL)
    {
        printf("Railway is empty\n");
        return;
    }
    
    Node *current = railway->head;
    while (current != NULL)
    {
        if (current->compartmentNumber == compartmentNumber)
        {
         
            if (current->prev == NULL && current->next == NULL)
            {

                railway->head = NULL;
            }
            else if (current->prev == NULL)
            {
                railway->head = current->next;
                current->next->prev = NULL;
            }
            else if (current->next == NULL)
            {

                current->prev->next = NULL;
            }
            else
            {
                
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            
            printf("Removed compartment %d (Seats: %d)\n", 
                   compartmentNumber, current->seatCount);
            free(current);
            return;
        }
        
        current = current->next;
    }
    
    printf("Compartment %d not found\n", compartmentNumber);
}

void displayForward(Railway *railway)
{
    if (railway->head == NULL)
    {
        printf("Railway is empty\n");
        return;
    }
    
    Node *current = railway->head;
    printf("Forward: ");
    
    while (current != NULL)
    {
        printf("[Comp-%d: %d seats] <-> ", 
               current->compartmentNumber, current->seatCount);
        current = current->next;
    }
    printf("NULL\n");
}

void displayBackward(Railway *railway)
{
    if (railway->head == NULL)
    {
        printf("Railway is empty\n");
        return;
    }

    Node *current = railway->head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    
    printf("Backward: NULL");
    
    while (current != NULL)
    {
        printf(" <-> [Comp-%d: %d seats]", 
               current->compartmentNumber, current->seatCount);
        current = current->prev;
    }
    printf("\n");
}

void displayDetails(Railway *railway)
{
    if (railway->head == NULL)
    {
        printf("Railway is empty\n");
        return;
    }
    
    Node *current = railway->head;
    int position = 1;
    
    printf("\nRailway Compartments Details:\n");
    printf("============================\n");
    
    while (current != NULL)
    {
        printf("Position %d: Compartment %d | Seats: %d\n", 
               position, current->compartmentNumber, current->seatCount);
        current = current->next;
        position++;
    }
    printf("\n");
}

int main()
{
    Railway railway;
    initRailway(&railway);
    
    printf("Railway System - Compartment Management (Runtime Input)\n");
    printf("==============================================\n\n");
    
    int choice;
    int compartmentNum;
    int seatCount;
    
    while (1)
    {
        printf("\n--- Menu ---\n");
        printf("1. Add compartment at front\n");
        printf("2. Add compartment at end\n");
        printf("3. Remove compartment by number\n");
        printf("4. Display all compartments (details)\n");
        printf("5. Display forward and backward\n");
        printf("6. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                printf("Enter compartment number: ");
                scanf("%d", &compartmentNum);
                printf("Enter seat count: ");
                scanf("%d", &seatCount);
                addAtFront(&railway, compartmentNum, seatCount);
                break;
                
            case 2:
                printf("Enter compartment number: ");
                scanf("%d", &compartmentNum);
                printf("Enter seat count: ");
                scanf("%d", &seatCount);
                addAtEnd(&railway, compartmentNum, seatCount);
                break;
                
            case 3:
                printf("Enter compartment number to remove: ");
                scanf("%d", &compartmentNum);
                removeCompartment(&railway, compartmentNum);
                break;
                
            case 4:
                displayDetails(&railway);
                break;
                
            case 5:
                displayForward(&railway);
                displayBackward(&railway);
                break;
                
            case 6:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid option!\n");
        }
    }
    
    return 0;
}
