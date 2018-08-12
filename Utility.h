#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

///
class Utility
{
public:
    bool bDebug;
    bool bVerbose;
    Utility();
    virtual ~Utility();


    char *  trim(string str);
    char * rtrim(string str);
    char * ltrim(string str);


    char *  trim(char *p);
    char * rtrim(char *p);
    char * ltrim(char *p);


protected:
private:
    char Buffer[256];
    };

#endif // CMDLINE_H
