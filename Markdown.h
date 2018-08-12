#ifndef MARKDOWN_H
#define MARKDOWN_H

#include <iostream>
#include <fstream>
#include "Table.h"
#include "Cmdline.h"
#include "Utility.h"

using namespace std;

class Markdown
{
public:
    Table t;
    Utility util;
    Markdown();
    virtual ~Markdown();
    int ReadFile(string fname);
    void Debug(bool enable);
    void Verbose(bool enable);
protected:
private:
    bool bTable;
    bool bVerbose;
    bool bDebug;
    int iHeader;
    void EndOfTable();
};

#endif // MARKDOWN_H
