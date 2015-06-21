#ifndef SOURCE_HPP_
#define SOURCE_HPP_

#include <cstdlib>
#include <string>
#include <list>
#include <stack>
#include <sstream>

using namespace std;
using std::string;

typedef struct {
	string name;
	string type;
	string value;
	
	string place;
	int quad;
	
	std::list<int> trueList;
	std::list<int> falseList;
	
}yystype;

#define YYSTYPE yystype

#endif