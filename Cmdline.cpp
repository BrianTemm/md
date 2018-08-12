#include "Cmdline.h"
///constuctor
Cmdline::Cmdline()
{
    bVerbose = false;
    bDebug =   false;
    //bLine =    false;

    str="";
    count =0;

}
///destructor
Cmdline::~Cmdline()
{
}
/***
\brief command line help
*/
void Cmdline::Help()
{
    cout<< "help"<< endl;
    cout <<"----"<< endl;
    cout <<"Usage: markdown [options] <file name>"<< endl;
    cout <<"Description: cleans up a mark down file."<< endl;
    cout <<"    -v --verbose       enable verebose mode"<< endl;
    cout <<"    -d --debug         enable debug mode"<< endl;
    cout <<"    -h --help          display the help screen"<< endl;
    cout <<"    -n                 show line number" << endl;
    cout <<"    -o                 show object files"<< endl;
    cout << endl<<endl;
    exit(1);
}
/***
\brief process command line arguments
\param argc -c argument count
\param agcv - each argument
*/
void Cmdline::Args(int argc,char * argv[])
{
    if (argc<2) Help();
    for (int x=1 ; ( x<argc) ; x++) {
        if ((argv[x][0]=='-')& (argv[x][1]=='-')) Double(x,argv);
        else if ((argv[x][0]=='-')& (argv[x][1]!='-')) Single(x,argv);
        else {
            str = argv[x];
            //str += " ";
        }
    }// for
    Options();
}//Args
/// process single cmd line arguments
void Cmdline::Single(int item,char *argv[])
{
    // cout << "Single: "<< item<< " "<<argv[item] << endl;
    for (int y=1; y< (int)strlen(argv[item]);  y++) {
        if (argv[item][y]=='v') {
            bVerbose=true;
        } else if (argv[item][y]=='d') {
            bDebug=true;
        } else if (argv[item][y]=='h') {
            Help();
        } else {
            cout << "Error: Unknown option - " << argv[item][y]<< endl<< endl;
            Help();
        }
    }// for
}
/// process double cmd line arguments
void Cmdline::Double(int item,char *argv[])
{
    // cout << "Double: "<< item<< " "<<argv[item] << endl;
    if (strcmp(argv[item],"--verbose")==0)      bVerbose = true;
    else if (strcmp(argv[item],"--debuge")==0)  bDebug =  true;
    else if (strcmp(argv[item],"--help")==0)    Help();
    else {
        cout << "Error: Unknown option - " << argv[item]<< endl<< endl;
        Help();
    }
}
/**
*
*/
void Cmdline::Options()
{
    if (bDebug) bVerbose = true;
    if (bVerbose) {
        if (bVerbose) cout << "Verbose enabled"<< endl;
        if (bDebug)   cout << "Debug enabled" << endl;
    }
}
/**
*
*/
bool Cmdline::Debug(void)
{
    return bDebug;
}
/**
*
*/
bool Cmdline::Verbose(void)
{
    return bVerbose;
}
