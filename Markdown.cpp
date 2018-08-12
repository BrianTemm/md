#include "Markdown.h"
/**
*
*/
Markdown::Markdown()
{
    //ctor
    bTable  = false;
    bDebug  = false;
    iHeader = -1;
}
/**
*
*/
Markdown::~Markdown()
{
    //dtor
}
/**
*
*/
void Markdown::EndOfTable()
{
    if (!bTable) return;
    cout << t.ToString(iHeader);
    cout << endl;
    bTable = false;
}
/**
*
*/
int Markdown::ReadFile(string fname)
{
    fname=util.trim(fname.c_str());
    if (bDebug)cout <<"|"<< fname <<"|  ReadFile"<<endl;

    ifstream in(fname.c_str());

    if(!in) {
        cout << "*** Error: Cannot open input file. - \n";
        cout << fname<< endl;
        return 1;
    }
    string line;
    char str[255];
    while(in) {
        in.getline(str, 255);  // delim defaults to '\n'
        if (strlen(str)==0) {
            cout << endl;
            continue;
        }
        if(in) {
            line =util.trim(str);
            switch(line.at(0)) {
            case '=':
                break;
            case '#':
                EndOfTable();
                iHeader=-1;
                for (int x=0; x<7; x++) {
                    if (line.at(x)=='#')
                        iHeader ++;
                    else
                        break;
                }

                cout <<setw(iHeader)<< " "<< line << endl;
                break;
            case ':':
                if (!bTable) t.New();
                bTable =true;
                t.Add(line);
                break;
            case '-':
                EndOfTable();
                cout<<setw(iHeader)<< " "<< line << endl;
                break;
            default:
                EndOfTable();
                cout<< setw(iHeader)<< " "<< line<< endl;
                break;
            }// switch
        }// if in file
    }
    in.close();
    return 0;
}
/**
*
*/
void Markdown::Debug(bool enable)
{
    bDebug=enable;
}
/**
*
*/
void Markdown::Verbose(bool enable)
{
    bVerbose=enable;
}
