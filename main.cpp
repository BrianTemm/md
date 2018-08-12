#include <iostream>
#include "Cmdline.h"
#include "Markdown.h"

using namespace std;

Cmdline cmd;
Markdown md;

/**
*
*/
int main(int argc, char* argv[])
{
    if (argc<1) cmd.Help();
    cmd.Args(argc,argv);
    md.Debug(cmd.Debug());
    md.Verbose(cmd.Verbose());
    md.ReadFile(cmd.str);
    return 0;
}
