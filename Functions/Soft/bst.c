#include <stdlib.h>
#include "bst.h"

struct t_btree * bstree_create_node(int item) {
        struct t_btree * root;
        root = malloc(sizeof(struct t_btree));
        root->elem = item;
        root->nextL = NULL;
        root->nextR = NULL;
        return root;
}

void bstree_insert(struct t_btree *root, int item, int (*cmpf)(int, int)) {
    if ((*cmpf)(root->elem, item)) {
        if (root->nextL != NULL) {
            bstree_insert(root->nextL, item, cmpf);
        } else {
            root->nextL = bstree_create_node(item);}
    } else {
        if (root->nextR != NULL) {
            bstree_insert(root->nextR, item, cmpf);
        } else {
            root->nextR = bstree_create_node(item);}}
}

void bstree_destroy(struct t_btree *root) {
    if (root != NULL) {
        bstree_destroy(root->nextL);
        bstree_destroy(root->nextR);
        free(root);}
}

/*
infix - элементы отобразятся по возрастанию
(левое поддерево -> корень -> правое поддерево);
prefix - элементы отобразятся в том же порядке, что хранятся
(корень -> левое поддерево -> правое поддерево);
postfix - элементы отобразятся по убыванию
(правое поддерево -> корень -> левое поддерево).
Сигнатуры функций выглядят следующим образом и все они должны быть реализованы в src/bst.c: */

void bstree_apply_infix(struct t_btree *root, void (*applyf)(int)) {
if (root->nextL != NULL) {
    bstree_apply_infix(root->nextL, applyf);}
(*applyf)(root->elem);
if (root->nextR !=  NULL) {
    bstree_apply_infix(root->nextR, applyf);}
}

void bstree_apply_prefix(struct t_btree *root, void (*applyf)(int)) {
(*applyf)(root->elem);
if (root->nextL != NULL) {
    bstree_apply_infix(root->nextL, applyf);}
if (root->nextR !=  NULL) {
    bstree_apply_infix(root->nextR, applyf);}
}


void bstree_apply_postfix(struct t_btree *root, void (*applyf)(int)) {
if (root->nextR != NULL) {
    bstree_apply_infix(root->nextR, applyf);}
(*applyf)(root->elem);
if (root->nextL !=  NULL) {
    bstree_apply_infix(root->nextL, applyf);}
}
