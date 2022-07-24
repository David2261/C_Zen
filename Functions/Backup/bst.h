#ifndef SRC_BST_H_
#define SRC_BST_H_

struct t_btree {
    int elem;
    struct t_btree * nextL;
    struct t_btree * nextR;
};

struct t_btree *bstree_create_node(int item);
void bstree_insert(struct t_btree *root, int item, int (*cmpf)(int, int));
void bstree_destroy(struct t_btree *root);

void bstree_apply_infix(struct t_btree *root, void (*applyf)(int));
void bstree_apply_prefix(struct t_btree *root, void (*applyf)(int));
void bstree_apply_postfix(struct t_btree *root, void (*applyf)(int));

#endif  //  SRC_BST_H_
