#ifndef CMDLINE_H
#define CMDLINE_H

#include <iostream>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>


using namespace std;

/// handles the command line
class Cmdline
{
    public:
        string str;   //file name
        Cmdline();
        virtual ~Cmdline();
        void Help();
        void Args(int argc,char * argv[]);
        bool Debug();
        bool Verbose();
    protected:
    private:
        int count;
        void Options();
        void Single(int item,char *argv[]);
        void Double(int item,char *argv[]);
        bool bDebug;
        bool bVerbose;
};

#endif // CMDLINE_H
