/* Circular Linked List */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start;
struct node *create_cll(struct node *start);
struct node *insert_beg(struct node *start);
// struct node *insert_end(struct node *start);
// struct node *insert_before(struct node *start);
// struct node *insert_after(struct node *start);
// struct node *delete_beg(struct node *start);
// struct node *delete_end(struct node *start);
// struct node *delete_after(struct node *start);
struct node *display(struct node *start);

int main() 
{
    int choice;
    do 
    {
        printf(" ***** Main Menu ****** \n");
        printf(" 1. Create Circular Linked List \n");
        printf(" 2. Insert Node in the Beginning \n");
        printf(" 3. Insert Node in the end \n");
        printf(" 4. Insert Node Before Another Node \n");
        printf(" 5. Insert Node After Another Node \n");
        printf(" 6. Delete Node From the Beginning \n");
        printf(" 7. Delete a Node From the End \n");
        printf(" 8. Delete a Node After Another Node: \n");
        printf(" 9. Display the List \n");
        printf(" 10. Exit \n");

        printf(" Enter a valid choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
            start = create_cll(start);
            break;

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
            // start = delete_after(start);
            // break;

            case 9:
            start = display(start);
            break;

            default:
            printf("Invalid choice: \n");

        }
    } while( choice != 10);
}

struct node *create_cll(struct node *start)
{
    struct node *new_node, *ptr;
    int val;
    printf("Enter -1 to exit \n");
    printf("Enter a value: ");
    scanf("%d", &val);
    while( val != -1) 
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = val;
        if(start == NULL)
        {
            start = new_node;
            new_node->next = start;
        }
        else 
        {
            ptr = start;
            while(ptr->next != start)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = start;
        }
    printf("Enter a value: ");
    scanf("%d", &val);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    if (start == NULL)
    {
        printf(" List is Empty");
        return start;
    }
    ptr = start;
    while( ptr->next != start)
    {
        printf("%d \n", ptr->data);
        ptr=ptr->next;
    }
     printf("%d \n", ptr->data);
    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    int val;
    printf("Enter a value: ");
    scanf("%d", &val);
    new_node->data = val;
    if( start == NULL)
    {
        new_node ->next = new_node;
        start = new_node;
    }
    else
    {
    ptr = start;
    while(ptr->next != start)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->next = start;
    start = new_node;
    }

    return start;
}

