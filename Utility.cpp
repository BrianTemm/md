#include "Utility.h"
///
Utility::Utility()
{
}
///
Utility::~Utility()
{
}
/**
* overload - removes white  charactor from both ends of the string
*/
char *  Utility::trim(string str)
{
    strcpy(Buffer,str.c_str());
    return trim(Buffer);
}
/**
* overload - removes white  charactor from right side of a string
*/
char * Utility::rtrim(string str)
{
    strcpy(Buffer,str.c_str());
    return rtrim(Buffer);
}
/**
*overload - removes white  charactor from left side of a string
*/
char * Utility::ltrim(string str)
{
    strcpy(Buffer,str.c_str());
    return ltrim(Buffer);
}
/**
* overload - removes white  charactor from both ends of the string
*/
char*  Utility::trim(char *p)
{
    return ltrim(rtrim(p));
}
/**
*overload - removes white  charactor from right side of a string
*/
char * Utility::rtrim(char *p)
{
    for (int x= (strlen(p)-1); x>-1; x--) {
        switch(p[x]) {
        case 0x20:
        case '\t':
        case '\n':
        case '\r':
            p[x]=0x00;
            break;
        case 0x00:
            return p;
        default:
            return p;
        }//switch
    }// for loop
    return NULL;
}
/**
*overload - removes white  charactor from left side of a string
*/
char * Utility::ltrim(char *p)
{

    while (p!=NULL) {
        switch(*p) {
        case 0x20:
        case '\t':
        case '\n':
        case '\r':
            p++;
            break;
        default:
            return p;
        }//switch
    }
    return NULL;
}
