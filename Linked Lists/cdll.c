// CIRCULAR DOUBLY LINKED LIST
#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start;
struct node *create_cdll(struct node *start);
struct node *insert_beg(struct node *start);
struct node *insert_end(struct node *start);
struct node *insert_before(struct node *start);
struct node *insert_after(struct node *start);
struct node *delete_beg(struct node *start);
struct node *delete_end(struct node *start);
struct node *delete_before(struct node *start);
struct node *delete_after(struct node *start);
struct node *display(struct node *start);
struct node *display_rev(struct node *start);


int main() 
{
    int choice;
    do {
        printf(" \n ***** MAIN MENU **** \n");
        printf(" 1. Create Circular Doubly Linked List \n");
        printf(" 2. Insert Node in the Beginning \n");
        printf(" 3. Insert Node at the End \n");
        printf(" 4. Insert Node Before Another Node \n");
        printf(" 5. Insert Node After Another Node \n");
        printf(" 6. Delete Node From The Beginning \n");
        printf(" 7. Delete Node From The End \n");
        printf(" 8. Delete Node Before Another Node \n");
        printf(" 9. Delete Node After Another Node \n");
        printf(" 10. Display List \n");
        printf(" 11. Display List In Reverse \n");
        printf(" 12. Exit \n");        

        printf("Enter a valid option: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            start = create_cdll(start);
            break;

            case 2:
            start = insert_beg(start);
            break;

            case 3:
            start = insert_end(start);
            break;

            case 4:
            start = insert_before(start);
            break;

            case 5:
            start = insert_after(start);
            break;

            case 6:
            start = delete_beg(start);
            break;

            case 7:
            start = delete_end(start);
            break;

            case 8:
            start = delete_before(start);
            break;

            case 9:
            start = delete_after(start);
            break;

            case 10:
            start = display(start);
            break;

            case 11:
            start = display_rev(start);
            break;

            default:
            printf("Enter a valid option: ");

            break;

        }
    } while( choice != 12);
}

struct node *create_cdll(struct node *start)
{
    struct node *new_node, *ptr;
    int val;
    printf("Enter -1 to exit: \n");
    printf("Enter a value: ");
    scanf("%d", &val);
    while( val != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = val;
        if(start == NULL)
        {
            new_node->next = new_node;
            new_node->prev = new_node;
            start = new_node;
        }
        else 
        {
            ptr = start;
            while (ptr->next != start)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = start;
            start->prev = new_node;
         
        }
        printf("Enter a value: ");
        scanf("%d", &val);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
     printf("%d \n", ptr->data);
     return start;
}

struct node *display_rev(struct node *start)
{
    struct node *ptr, *last_ptr;
    ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    last_ptr = ptr;
    while(ptr->prev != last_ptr)
    {
        printf("\n %d", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n %d", ptr->data);
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

    if (start == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        start = new_node;
    }
    else {
        ptr = start;
        new_node->next = ptr;
        ptr->prev = new_node;
        while (ptr->next != start)
            ptr = ptr->next;
        new_node->prev = ptr;
        ptr->next = new_node;
        start = new_node;
    }
    return start;
}


struct node *insert_end(struct node *start)
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    int val;
    printf("Enter a value: ");
    scanf("%d", &val);
    new_node->data = val;
    if(start == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        start = new_node;
    }   
    else {
        ptr = start;
        while(ptr->next != start)
            ptr=ptr->next;
        ptr->next = new_node;
        new_node->prev = ptr;
        new_node->next = start;
        start->prev = new_node;
    }
    return start;
}

struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    int num, val;
    printf("Enter value of node before which you want to insert node: ");
    scanf("%d", &num);
    printf("Enter value to insert in Node: ");
    scanf("%d", &val);
    new_node->data = val;
    ptr = start;
    while(ptr->data != num)
        ptr = ptr->next;
    ptr->prev->next = new_node;
    new_node->prev = ptr->prev;
    new_node->next = ptr;
    ptr->prev = new_node;
    return start;
}

struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(new_node));
    int val, num;
    printf("Enter value after which you want to insert node: ");
    scanf("%d", &num);
    printf("Enter value to insert in the node: ");
    scanf("%d",&val);
    new_node->data = val;
    ptr = start;
    while(ptr->data != num)
        ptr = ptr->next;
    ptr->next->prev = new_node;
    new_node->prev = ptr;
    new_node->next = ptr->next;
    ptr->next = new_node;

    return start;
}

struct node *delete_beg(struct node *start)
{
    if(start == NULL)
    {
        printf("The List is Empty");
    }
    else 
    {
        struct node *preptr, *ptr;
        preptr = ptr = start;
        while(preptr->next != start)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        ptr->next->prev = preptr;
        start = ptr->next;
        free(ptr);
    }
    return start;
}

struct node *delete_end(struct node *start)
{
    if(start == NULL)
        printf("The List is Empty");
    else
    {
        struct node *preptr, *ptr;
        preptr = ptr = start;
        while(preptr->next != start)
        {
            preptr = ptr;
            ptr=ptr->next;
        }
        preptr->prev->next = start;
        ptr->prev = preptr->prev;
        free(preptr);
        return start;
    }
}

struct node *delete_before(struct node *start)
{
    if(start == NULL)
        printf("The List is Empty");
    else
    {
        struct node *preptr, *ptr;
        preptr = ptr = start;
        int num;
        printf("Enter value before which you wish to delete node: ");
        scanf("%d", &num);
        while(ptr->data != num)
        {
            preptr = ptr;
            ptr=ptr->next;
        }
        ptr->prev = preptr->prev;
        preptr->prev->next = preptr->next;
        free(preptr);
    }
     return start;
}

struct node *delete_after(struct node *start)
{
    if(start == NULL)
        printf("Empty List");
    else 
    {
        struct node *preptr, *ptr;
        preptr = ptr = start;
        int num;
        printf("Enter value after which to delete node: ");
        scanf("%d",&num);
        while(preptr->data != num)
        {
            preptr = ptr;
            ptr=ptr->next;
        }
        preptr->next = ptr->next;
        ptr->next->prev = preptr;
        free(ptr);
    }
          return start;
}

