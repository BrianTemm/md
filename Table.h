#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <map>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>


using namespace std;
#define MAX_NUM_COLUMNS 20


class Table
{
public:
    //bool bDebug;
    //bool bVerbose;
    map<string,string> m;
    map<string,string>::iterator it;
    int row, col, MaxCol;
    int colSize[MAX_NUM_COLUMNS];
    Table();
    virtual ~Table();
    void New();
    bool Add(const string s);
    string ToString(int index);
    void Verbose(bool enable);
    void Debug(bool enable);

protected:
private:
    bool bDebug;
    bool bVerbose;
};

#endif // Table_H
