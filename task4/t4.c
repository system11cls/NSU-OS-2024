#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node;


typedef struct Node {
    char *str;
    int length;
    struct Node* next;
} Node;

typedef struct Head {
    Node *head, *end;
} Head;

void clear(Head main_node);

Node* get_node(int size, Head main_node){
    Node* new_node = NULL;
    new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf("Memmory error: new_node", stderr);
        clear(main_node);
        exit(1);
    }
    
    new_node->length = size;
    new_node->next = NULL;
    new_node->str = NULL;
    new_node->str = malloc((size + 1) * sizeof(char));
    if (new_node->str == NULL) {
        fprintf("Memmory error: new_node->str", stderr);
        free(new_node);
        clear(main_node);
        exit(1);
    }
    return new_node;
}

Head push_back(Head main_node, Node* new_node){
    if (main_node.head == NULL) {
        main_node.head = new_node;
        main_node.end = new_node;
    }
    else {
        main_node.end->next = new_node;
        main_node.end = new_node;
    }
    return main_node;
}

void clear(Head main_node){
    Node* cur_node = main_node.head, *next_node = NULL;
    main_node.head = NULL;
    main_node.end = NULL;

    while (cur_node != NULL) {
        next_node = cur_node->next;
        if (cur_node->str != NULL) free(cur_node->str);
        free(cur_node);
        cur_node = next_node;
    }
}

int main(){
    char str[1001];
    
    Head main_node; 
    main_node.head = NULL;
    main_node.end = NULL;
    
    Node* cur_node;
    
    while (fgets(str, 1000, stdin) != NULL && str[0] != '.') {
        cur_node = get_node(strlen(str), main_node);
        cur_node->str = strcpy(cur_node->str, str);    
        main_node = push_back(main_node, cur_node);
        int a = 5;
    }

    cur_node = main_node.head;
    while (cur_node != NULL) {
        printf("%s", cur_node->str);
        cur_node = cur_node->next;
    }
    
    clear(main_node);

    return 0;
}