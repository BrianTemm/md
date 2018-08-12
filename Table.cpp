#include "Table.h"


/*
*
*/
Table::Table()
{
    bDebug =false;
    bVerbose = false;
    New();
}
/*
*
*/
Table::~Table()
{
    //dtor
}
/*
*
*/
void Table::New()
{
    m.clear();
    row = 0;
    col = 0;
    MaxCol =0;
    for (int x=0; x<MAX_NUM_COLUMNS; x++)
        colSize[x] =0;
}
/*
*
*/
bool Table::Add(const string s)
{
    row++;
    col=0;
    char stemp[30];
    char buffer[1000];
    strcpy(buffer,s.c_str());
    if (bDebug)cout<< "Adding to the map - " << s<< endl;
    char *pch=strtok(buffer,":");
    while (pch != NULL) {
        col++;                        // the col count
        if (col > MaxCol) MaxCol=col;  // set the max number of colums
        if ((int)strlen(pch)>(int)colSize[(int)col])
            colSize[(int)col]=(int)strlen(pch);
        sprintf(stemp,"R%dC%d",row,col);
        m[stemp]=pch;                 // add the Table
        pch = strtok (NULL, ":");     // get the next col data

    }
    return true;
}
/*
*
*/
string Table::ToString(int index)
{
    if (bDebug)cout <<"ToString" << endl;
    stringstream ssReturn;
    col =0;
    it = m.begin();
    ssReturn<<setw(index)<<" ";
    for(; it!=m.end(); it++) {
        col++;
        // cout << it->first<<" ----- "<<iSize<<"  "<<setw(iSize)<< left <<it->second <<"|"<<endl;
        ssReturn<<":"<<left<< setw(colSize[(int)col]+1)<<it->second;

        if (bDebug)ssReturn << "(" << colSize[(int)col] << ")"; // add the with of the column

        if (col==MaxCol) {
            col=0;
            ssReturn << ":"<<endl;
            if (it!=m.end())
                ssReturn<<setw(index)<<" ";
        }
    }
    //string sReturn = ssReturn;
    return  ssReturn.str();
}
/*
*
*/
void Table::Verbose(bool enable)
{
    bVerbose = enable;
}
/*
*
*/
void Table::Debug(bool enable)
{
    bDebug = enable;
}
