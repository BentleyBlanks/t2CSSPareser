#ifndef T2_CSSPARSER_H
#define T2_CSSPARSER_H

#include <iostream>
#include <string>
#include "t2CSSLex.hpp"
#include "t2CSSNode.hpp"

class t2CSSParser
{
public:
	t2CSSParser():root(NULL){}
	
	yyscan_t scaninfo;

	t2CSSNode* root;
};

#endif
