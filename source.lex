%{
	#include <stdio.h>
	#include <iostream>
	#include <string>
	#include "source.hpp"
	#include "symbol_table.hpp"
	#include "source.tab.hpp"
		
    using namespace std;
	int debuger = 0; // 1- debuger ON | 0- debuger OFF
	void print4Debug(const char* str);
	extern void errLex();
%}

%option yylineno
%option noyywrap

whitespace	([ \t\n\r])
everyThing (.)
%%

foreach					{print4Debug("FOREACH");return FOREACH;}
in						{print4Debug("IN");return IN;}
int						{print4Debug("TYPE_INT");return TYPE_INT;}
matrix					{print4Debug("TYPE_MATRIX");return TYPE_MATRIX;}
print					{print4Debug("PRINT");return PRINT;}
read					{print4Debug("READ");return READ;}
if                      {print4Debug("IF");return IF;}
else                    {print4Debug("ELSE");return ELSE;}
true                    {print4Debug("TRUE");yylval.value = yytext; yylval.type = "BOOL";return TRUE;}
false                   {print4Debug("FALSE");yylval.value = yytext; yylval.type = "BOOL";return FALSE;}
0|[1-9][0-9]*           {print4Debug("NUM");yylval.value = yytext; yylval.type = "INT";return NUM;}
\"[^"]*\" 				{print4Debug("STRING");yylval.value = yytext; yylval.type = "STRING";return STRING;}
[a-zA-Z]+			    {print4Debug("ID");yylval.value = yytext; 
							yylval.name = yytext; 
							yylval.type = "STRING";return ID;}
"=="					{print4Debug("REL_EQUAL");return REL_EQUAL;}
"!="					{print4Debug("REL_NOT_EQUAL");return REL_NOT_EQUAL;}
"<="					{print4Debug("REL_LESS_EQUAL");return REL_LESS_EQUAL;}
">="					{print4Debug("REL_GREATER_EQUAL");return REL_GREATER_EQUAL;}
"<"						{print4Debug("REL_LESS");return REL_LESS;}
">" 					{print4Debug("REL_GREATER");return REL_GREATER;}
"&&"					{print4Debug("LOGIC_AND");return LOGIC_AND;}
"||"               		{print4Debug("LOGIC_OR");return LOGIC_OR;}
\!						{print4Debug("LOGIC_NOT");return LOGIC_NOT;}
\+ 						{print4Debug("PLUS");return PLUS;}
\- 						{print4Debug("MINUS");return MINUS;}
\* 						{print4Debug("MULT");return MULT;}
\/ 						{print4Debug("DIV");return DIV;}
"="                     {print4Debug("ASSIGN");return ASSIGN;}
";"                     {print4Debug("SC");return SC;}
\(                      { print4Debug("LP");return LP;}
\)                      {print4Debug("RP");return RP;}
\{						{print4Debug("LC");return LC;}
\}						{print4Debug("RC");return RC;}
\[						{print4Debug("LB");return LB;}
\]						{print4Debug("RB");return RB;}
\,						{print4Debug("CS");return CS;}
"//"{everyThing}*		; /* comment */
{whitespace}            ;
. {
	errLex();
}

%%

void print4Debug(const char* str){	
	if (debuger==1){
		printf("|%s| (%s) \n", str, yytext);	
	}
}