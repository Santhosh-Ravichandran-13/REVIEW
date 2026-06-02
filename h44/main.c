#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char songName[50];
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
} CircularPlaylist;

void initPlaylist(CircularPlaylist *playlist)
{
    playlist->head = NULL;
}

Node *createSongNode(char *songName)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->songName, songName);
    newNode->next = NULL;
    return newNode;
}

void addSong(CircularPlaylist *playlist, char *songName)
{
    Node *newNode = createSongNode(songName);
    
    if (playlist->head == NULL)
    {
        playlist->head = newNode;
        newNode->next = newNode;  
        printf("Added first song: %s\n", songName);
    }
    else
    {
        Node *current = playlist->head;
        
        while (current->next != playlist->head)
        {
            current = current->next;
        }
       
        current->next = newNode;
        newNode->next = playlist->head;
        printf("Added song: %s\n", songName);
    }
}

void removeSong(CircularPlaylist *playlist, char *songName)
{
    if (playlist->head == NULL)
    {
        printf("Playlist is empty\n");
        return;
    }
    
    Node *current = playlist->head;
    Node *previous = NULL;
    int found = 0;
 
    if (strcmp(playlist->head->songName, songName) == 0)
    {
        if (playlist->head->next == playlist->head)
        {
         
            free(playlist->head);
            playlist->head = NULL;
            printf("Removed song: %s (playlist now empty)\n", songName);
        }
        else
        {
            Node *temp = playlist->head;
            
            Node *last = playlist->head;
            while (last->next != playlist->head)
            {
                last = last->next;
            }
            
            playlist->head = playlist->head->next;
            last->next = playlist->head;
            free(temp);
            printf("Removed song: %s\n", songName);
        }
        return;
    }

    previous = current;
    current = current->next;
    
    while (current != playlist->head)
    {
        if (strcmp(current->songName, songName) == 0)
        {
            previous->next = current->next;
            free(current);
            printf("Removed song: %s\n", songName);
            found = 1;
            break;
        }
        previous = current;
        current = current->next;
    }
    
    if (!found)
    {
        printf("Song not found: %s\n", songName);
    }
}
void traversePlaylist(CircularPlaylist *playlist, int iterations)
{
    if (playlist->head == NULL)
    {
        printf("Playlist is empty\n");
        return;
    }
    
    Node *current = playlist->head;
    int count = 0;
    int songCount = 0;
    int currentIter = 1;
    Node *temp = playlist->head;
    do
    {
        songCount++;
        temp = temp->next;
    } while (temp != playlist->head);
    
    printf("\nPlaying playlist for %d iterations (%d songs total):\n", 
           iterations, songCount);
    printf("================\n");
    
    for (count = 0; count < iterations * songCount; count++)
    {
        if (count > 0 && count % songCount == 0)
        {
            printf("--- Iteration %d ---\n", ++currentIter);
        }
        
        printf("%d. [Iteration %d] Now Playing: %s\n", 
               count + 1, currentIter, current->songName);
        current = current->next;
    }
}

void displayPlaylist(CircularPlaylist *playlist)
{
    if (playlist->head == NULL)
    {
        printf("Playlist is empty\n");
        return;
    }
    
    Node *current = playlist->head;
    int position = 1;
    
    printf("\nCurrent Playlist:\n");
    printf("================\n");
    
    do
    {
        printf("%d. %s\n", position, current->songName);
        current = current->next;
        position++;
    } while (current != playlist->head);
}

int main()
{
    CircularPlaylist playlist;
    initPlaylist(&playlist);
    
    printf("Music Player - Circular Linked List (Runtime Input)\n");
    printf("==================================================\n\n");
    
    int choice;
    char songName[50];
    int iterations;
    
    while (1)
    {
        printf("\n--- Menu ---\n");
        printf("1. Add song to end\n");
        printf("2. Remove song by name\n");
        printf("3. Display playlist\n");
        printf("4. Play playlist (k iterations)\n");
        printf("5. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);
        getchar(); 
        
        switch (choice)
        {
            case 1:
                printf("Enter song name: ");
                fgets(songName, sizeof(songName), stdin);
                if (songName[strlen(songName) - 1] == '\n')
                    songName[strlen(songName) - 1] = '\0';
                addSong(&playlist, songName);
                break;
                
            case 2:
                printf("Enter song name to remove: ");
                fgets(songName, sizeof(songName), stdin);
                if (songName[strlen(songName) - 1] == '\n')
                    songName[strlen(songName) - 1] = '\0';
                removeSong(&playlist, songName);
                break;
                
            case 3:
                displayPlaylist(&playlist);
                break;
                
            case 4:
                printf("Enter number of iterations: ");
                scanf("%d", &iterations);
                traversePlaylist(&playlist, iterations);
                break;
                
            case 5:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid option!\n");
        }
    }
    
    return 0;
}
