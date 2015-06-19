#ifndef __HW5_H
#define __HW5_H

#include <iostream>
#include <stdlib.h>

using namespace std;


void errLex(){
    cout << "LEXICAL ERROR" << endl;
    exit(0);
}

void errSyn(){
    cout << "SYNTACTIC ERROR" << endl;
    exit(0);
}

void errSem(){
    cout << "SEMANTIC ERROR" << endl;
    exit(0);
}


#endif