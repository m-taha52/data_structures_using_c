#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start;
struct node *create_ll(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
// struct node *insert_before(struct node *);
// struct node *insert_after(struct node *);
// struct node *delete_beg(struct node *);
// struct node *delete_end(struct node *);
// struct node *delete_after(struct node *);
struct node *display(struct node *);

int main() {
    int choice;
    do {
        
        printf(" ******* MAIN MENU *******\n");
        printf(" 1. Create a Linked List\n");
        printf(" 2. Insert a node in the beginning\n");
        printf(" 3. Insert a node in the end\n");
        printf(" 4. Insert a node before another node\n");
        printf(" 5. Insert a node after another node\n");
        printf(" 6. Delete a node from the beginning\n");
        printf(" 7. Delete a node from the end\n");
        printf(" 8. Delete a node after another node\n");
        printf(" 9. Display the list\n");
        printf(" 10. Exit\n");

        printf("Enter a value: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                    start = create_ll(start);
                    break;
            case 2:
                    start = insert_beg(start);
                    break;
            case 3: 
                    start = insert_end(start);
                    break;
            // case 4: 
            //         start = insert_before(start);
            //         break;
            // case 5: 
            //         start = insert_after(start);
            //         break;
            // case 6: 
            //         start = delete_beg(start);
            //         break;
            // case 7:
            //         start = delete_end(start);
            //         break;
            // case 8:
            //         start = delete_after(start);
            //         break;
            case 9: 
                    start = display(start);
                    break;
            default: 
                    printf("Enter a valid choice: ");
                    break;
        }
    } while (choice != 10);

    return 0; 
}

struct node *create_ll(struct node *start) {
    struct node *new_node, *ptr;
    int val;
    printf("\n");
    printf(" Enter -1 to exit \n");
    printf("Enter a value: ");
    scanf("%d", &val);

    while( val != -1 ) {
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;

    if( start == NULL) {
        start = new_node;
        new_node->next = NULL;
    }
    else {
        ptr = start;
        while ( ptr->next != NULL) 
            ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = NULL;
    }

    printf("Enter a value: ");
    scanf("%d", &val);

    }

    return start;
}

struct node *display(struct node *start) 
{
    struct node *ptr;
    if( start == NULL) {
        printf("List is Empty");
    }
    else {
        ptr = start;
        while( ptr != NULL)
            {
                printf("%d \n", ptr->data);
                ptr = ptr->next;
            }
    }

    return start;
}

struct node *insert_beg(struct node *start) 
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    int val;
    printf("Enter a value: ");
    scanf("%d", &val);
    new_node->data = val;
    new_node->next = start;
    start = new_node;
}

struct node *insert_end(struct node *start)
{
    struct node *new_node, *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    int val;
    printf("Enter a value: ");
    scanf("%d", &val);
    new_node->data = val;
    ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->next = NULL;
    return start;
}