#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

struct node* node_create(int data)
{
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    return p;
}

struct node* node_insert_front(struct node* head_node, int data)
{
    struct node* current_node = node_create(data);
    if(NULL == head_node)
    {
        head_node = current_node;
    }
    else
    {
        current_node->next = head_node;
        head_node = current_node;
    }
    return head_node;
}

struct node* node_insert_end(struct node* head_node, int data)
{
    struct node* current_node = node_create(data);
    struct node* last_node = head_node;
    if(NULL == head_node)
    {
        head_node = current_node;
        return head_node;
    }
    else
    {
        while (NULL != last_node->next)
        {
            last_node = last_node->next;
        }
        last_node->next = current_node;
        return head_node;
    }
}

struct node* node_insert_after(struct node* pre_node, int data)
{
    struct node* current_node = node_create(data);
    if(NULL == pre_node)
    {
        pre_node = current_node;
        return pre_node;
    }
    else
    {
        current_node->next = pre_node ->next;
        pre_node->next = current_node;
        return pre_node;
    }
}

struct node* node_delete(struct node* head_node, int position)
{
    int i;
    if(NULL == head_node)
    {
        return NULL;
    }
    struct node* temp_node = head_node;
    if(0 == position)
    {
        head_node = temp_node->next;
        free(temp_node);
        return head_node;
    }
    /* temp_node -> delete_node -> next_node */
    for(i = 0; i < (position-1); i++)
    {
        temp_node = temp_node->next;
        if(NULL == temp_node->next) return head_node;
    }
    struct node* next_node = temp_node->next->next;
    free(temp_node->next);
    temp_node->next = next_node;
    return head_node;
}

int node_search(struct node* head_node, int data)
{
    struct node* current_node = head_node;
    int i = 0;
    while (NULL != current_node)
    {
        if(current_node->data == data)
        {
            return i;
        }
        current_node = current_node->next;
        i++;
    }
    return -1;
    
}

int node_search_count(struct node* head, int x) 
{ 
    if (NULL == head) 
        return 0; 
      
    if (x == head->data) 
        return node_search_count(head->next, x) + 1; 
  
    return node_search_count(head->next, x); 
} 


void node_print_list(struct node* current_node) 
{ 
	while (NULL != current_node) 
    {
        printf("Node addr: %p "   ,current_node);
		printf("Node.data = %d "  , current_node->data); 
        printf("Node.next = %p \n", current_node->next);
		current_node = current_node->next; 
	} 
    return;
} 

int main(int argc, char const *argv[])
{
    if (argc ==1){
        head = node_insert_end(head,0);
        head = node_insert_end(head,3);
        head = node_insert_end(head,3);
        head = node_insert_end(head,1);
        head = node_insert_end(head,2);
        head = node_insert_end(head,3);
        head = node_insert_end(head,2);
        head = node_insert_end(head,3);
        head = node_insert_end(head,2);
        head = node_insert_end(head,1);
        // node_print_list(head);
        printf("%d\n",node_search_count(head,3));
        return 0;
    }
    else if (argc == 2){
        if(strcmp(argv[1],"-l") == 0){
        }
        else if(strcmp(argv[1],"-a") == 0){
        }
        else if(strcmp(argv[1],"-la") == 0){
        }
        else{
            printf("Unknow comand\n");
            return -1;
        }
        return 0;
    }
    else{
        printf("Unknow comand\n");
        return -1;
    }
}