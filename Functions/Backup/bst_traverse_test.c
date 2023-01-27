#include "bst.h"
#include <stddef.h>
#include <stdio.h>

int cmp(int a, int b);

void applyf(int a);

int main() {
    struct t_btree * root = NULL;

    root = bstree_create_node(5);
    bstree_insert(root, 3, &cmp);
    bstree_insert(root, 6, &cmp);

    bstree_apply_infix(root, &applyf);
    printf("\n");
    bstree_apply_prefix(root, &applyf);
    printf("\n");
    bstree_apply_postfix(root, &applyf);
    printf("\n");
    bstree_destroy(root);

    printf("\n");

    root = bstree_create_node(5);
    bstree_insert(root, 3, &cmp);
    bstree_insert(root, 6, &cmp);
    bstree_insert(root, 4, &cmp);

    bstree_apply_infix(root, &applyf);
    printf("\n");
    bstree_apply_prefix(root, &applyf);
    printf("\n");
    bstree_apply_postfix(root, &applyf);
    printf("\n");
    bstree_destroy(root);

    return 0;
}

int cmp(int a, int b) {
    return (a > b);
}

void applyf(int a) {
    printf("%d |", a);
}
