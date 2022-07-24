#include "bst.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void bstree_create_node_test(void);

int main() {
    bstree_create_node_test();
}
void bstree_create_node_test(void) {
    struct t_btree * root = NULL;
    int a;
    struct t_btree * l, * r;

    root = bstree_create_node(30);
    a = root->elem;
    l = root->nextL;
    r = root->nextR;
    if ((a == 30) && (l == NULL) && (r == NULL)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");}
    free(root);

    root = bstree_create_node(50);
    a = root->elem;
    l = root->nextL;
    r = root->nextR;
    if ((a == 50) && (l == NULL) && (r == NULL)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");}
    free(root);

    root = bstree_create_node(60);
    a = root->elem;
    l = root->nextL;
    r = root->nextR;
    if ((a == 60) && (l == NULL) && (r == NULL)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");}
    free(root);
}
