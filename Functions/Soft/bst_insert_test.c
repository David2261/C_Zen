#include "bst.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void bst_insert_test(void);
int cmp(int a, int b);

int main() {
    bst_insert_test();
}
void bst_insert_test(void) {
    struct t_btree * root = NULL;
    int a;
    struct t_btree * l, * r;

    root = bstree_create_node(5);
    bstree_insert(root, 3, &cmp);
    l = root->nextL;
    r = root->nextR;
    a = l->elem;

    if ((a == 3) && (r == NULL) && (l != NULL)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");}

    bstree_insert(root, 6, &cmp);
    l = root->nextL;
    r = root->nextR;
    a = r->elem;

    if ((a == 6) && (r != NULL) && (l != NULL)) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");}

    bstree_destroy(root);
     printf("SUCCESS\n");
}

int cmp(int a, int b) {
    return (a > b);
}
