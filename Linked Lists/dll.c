/* DOUBLY LINKED LIST */

#include <stdio.h>
#include <stdlib.h> 

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start;
// struct node *create_dll(struct node *start);
struct node *insert_beg(struct node *start);
// struct node *insert_end(struct node *start);
// struct node *insert_before(struct node *start);
// struct node *insert_after(struct node *start);
// struct node *delete_beg(struct node *start);
// struct node *delete_end(struct node *start);
// struct node *delete_before(struct node *start);
// struct node *delete_after(struct node *start);
struct node *display(struct node *start);
// struct node *display_rev(struct node *start);

int main() {
    int choice;
    do {
        printf(" ****** MAIN MENU ****** \n");
        printf(" 1. Create Doubly Linked List \n");
        printf(" 2. Insert Node in the Beginning \n");
        printf(" 3. Insert Node at the End \n");
        printf(" 4. Insert Node Before Another Node \n");
        printf(" 5. Insert Node After Another Node \n");
        printf(" 6. Delete Node From the Beginning \n");
        printf(" 7. Delete Node From the End \n");
        printf(" 8. Delete Node Before Another Node \n");
        printf(" 9. Delete Node After Another Node \n");
        printf(" 10. Display The List \n");
        printf(" 11. Display The List in Reverse \n");

        printf("Enter a choice: ");
        scanf("%d", &choice);
        
        switch(choice) 
        {
            // case 1:
            // start = create_dll(start);
            // break;

            case 2:
            start = insert_beg(start);
            break;

            // case 3:
            // start = insert_end(start);
            // break;

            // case 4:
            // start = insert_before(start);
            // break;

            // case 5:
            // start = insert_after(start);
            // break;

            // case 6:
            // start = delete_beg(start);
            // break;

            // case 7:
            // start = delete_end(start);
            // break;

            // case 8:
            // start = delete_before(start);
            // break;

            // case 9:
            // start = delete_after(start);
            // break;

            case 10:
            start = display(start);
            break;

            // case 11:
            // start = display_rev(start);
            // break;

            default:
            printf("Invalid Option \n ");
            break;

        }
    } while(choice != 12 );
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    int val;
    printf("Enter a value: ");
    scanf("%d", &val);
    new_node->data = val;

    if(start == NULL)
    {
        new_node->prev = NULL;
        new_node->next = NULL;
        start = new_node;
    }

    else {
        ptr = start;
        ptr->prev = new_node;
        new_node->prev = NULL;
        new_node->next = ptr;
        start = new_node;
    }

    return start;
}


struct node *display(struct node *start)
{
    struct node *ptr;
    if(start == NULL)
        printf("The List is Empty");
    else 
    {
            ptr = start;
            while( ptr->next != NULL)
            {
                printf("%d \n", ptr->data);
                ptr=ptr->next;
            }
             printf("%d \n", ptr->data);
    }
    return start;
}

