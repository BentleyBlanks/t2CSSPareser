#ifndef T2_CSSAST_H
#define T2_CSSAST_H

#include <iostream>
#include <string>
#include "t2CSSBison.hpp"
#include "t2CSSLex.h"

#include "t2CSSNode.h"

class t2CSSAST
{
public:
    t2CSSAST() :root(NULL) {}

	yyscan_t scaninfo;

	t2CSSNode* root;

    void printAsDot() { printAsDot(root); }

    void traversal() { traversal(root); }

    void traversalAsDot() { traversalAsDot(root); }

protected:
    void printAsDot(t2CSSNode* root)
    {
        traversal(root);

        printf("\n--------------------Graphviz--------------------\n");

        printf("digraph G {\n");
        printf("node[shape=rect]\n");

        traversalAsDot(root);

        printf("}\n");

        printf("------------------------------------------------\n");
    }

    void traversal(t2CSSNode* root)
    {
        if(!root) return;

        t2CSSNode *l = root->leftChild();
        t2CSSNode *r = root->rightChild();

        traversal(l);
        root->node();
        traversal(r);
    }

    void traversalAsDot(t2CSSNode* root)
    {
        if(!root) return;

        printf("_%p[label=%s]\n", root, root->nodeName.c_str());

        t2CSSNode *l = root->leftChild();
        t2CSSNode *r = root->rightChild();

        if(l != NULL) printf("_%p -> _%p\n", root, l);
        if(r != NULL) printf("_%p -> _%p\n", root, r);

        traversalAsDot(l);
        traversalAsDot(r);
    }
};

#endif
