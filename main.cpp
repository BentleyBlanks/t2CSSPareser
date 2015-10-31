#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "t2CSSBison.hpp"
#include "t2CSSLex.h"
#include "t2CSSAST.h"

extern int yyparse(t2CSSAST* parser);

void printAsDot(t2CSSNode* root);

void traversal(t2CSSNode* root);

void traversalAsDot(t2CSSNode* root);

void yyerror(const char *s) 
{ 
	// va_list ap;
	// va_start(ap, s);

	// fprintf(stderr, "%d: error: ", yyget_lineno(parser->scaninfo));
	// vfprintf(stderr, s, ap);
	// fprintf(stderr, "\n");
	printf("Error: %s", s);
}

int main(int argc, char **argv) 
{
	t2CSSAST* parser = new t2CSSAST();

	if(yylex_init_extra(parser, &parser->scaninfo)){
		perror("Inti alloc failed");
		return 1;
	}

    FILE *f = fopen("./demo.css", "r");

	/* 文件打开失败 */
	if(!f){
		printf("打开文件失败\n");
		return 0;
	}

	printf("------------------------------\n"); 

	//YY_BUFFER_STATE bs = yy_create_buffer(f, YY_BUF_SIZE);
	//yy_switch_to_buffer(bs);

    yyset_in(f, parser->scaninfo);

	//while(yylex());

	//yylex(parser->scaninfo);

	yyparse(parser);

    printAsDot(parser->root);

    fclose(f);

    return 0;
}

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

  if (l != NULL) printf("_%p -> _%p\n", root, l);
  if (r != NULL) printf("_%p -> _%p\n", root, r);

  traversalAsDot(l);
  traversalAsDot(r);
}