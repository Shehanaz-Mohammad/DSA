#include <stdio.h>
#include <stdlib.h>

//  QUESTION 1

struct node
{
    char data;
    struct node *next;
};

int main()
{
    struct node *head, *char_R, *char_G, *char_U, *char_K, *char_T;
    char_R = (struct node *)malloc(sizeof(struct node));
    char_G = (struct node *)malloc(sizeof(struct node));
    char_U = (struct node *)malloc(sizeof(struct node));
    char_K = (struct node *)malloc(sizeof(struct node));
    char_T = (struct node *)malloc(sizeof(struct node));
    char_R->data = 'R';
    char_G->data = 'G';
    char_U->data = 'U';
    char_K->data = 'K';
    char_T->data = 'T';
    char_R->next = char_G;
    char_G->next = char_U;
    char_U->next = char_K;
    char_K->next = char_T;
    char_T->next = char_R;
    head = char_T;

    struct node *temp = head;
    do
    {
        temp = temp->next;
        printf("%c->", temp->data);

    } while (temp != head);
    printf("NULL");
    return 0;
}



