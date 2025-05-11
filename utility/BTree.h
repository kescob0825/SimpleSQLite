#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char* data;
    struct node* left;
    struct node* right;
} node;

node* create_node(const char* data);

node* insert_node(node* root, const char* data);

node* delete_node(node* root, const char* data);

node* get_node(node* root, const char* data);

void display_database(node* root);

void delete_tree(node* root);
#endif //BTREE_H
