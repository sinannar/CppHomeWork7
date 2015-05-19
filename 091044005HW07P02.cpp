
///headers
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <string>
#include <iomanip>

///define const
#define WIDTH 12

///define's
#define TEST

///namespace
using namespace std;

///function that open a file and search key if found return true,on the other hand return false
bool getInformation(char* filename,int *line,string key,string *word1,string *word2,string *word3,string *word4,string *word5);

int main(void)
{
#ifdef TEST
    ofstream fout;
    string word1,word2,word3,word4,word5;
    char *keylist[6]={" access"," arrays"," bytes"," char"," cHar"," conversions"};
    int line;

    fout.open("output.txt");
    if(fout.fail())
    return false;

    fout<<"     KEYWORD   LINE NUMBER       --------KEYWORD       IN        CONTEXT----------"<<endl;

    for(int i=0;i<6;++i)
    if(getInformation("reading.txt",&line,keylist[i],&word1,&word2,&word3,&word4,&word5))
    {
        fout<<setw(WIDTH)<<keylist[i]
        <<"  "<<setw(WIDTH)<<line
        <<"  "<<setw(WIDTH)<<word1
        <<"  "<<setw(WIDTH)<<word2
        <<"  "<<setw(WIDTH)<<word3
        <<"  "<<setw(WIDTH)<<word4
        <<"  "<<setw(WIDTH)<<word5<<endl;
    }

    fout.close();
#endif

	return 0;
}

bool getInformation(char* filename,int *line,string key,string *word1,string *word2,string *word3,string *word4,string *word5)
{
    ifstream fin;

    fin.open(filename);
    if(fin.fail())
        return false;

    char next;
    int n=1;

    while( !fin.eof() )
    {
        if(key==*word3)
            return true;
        if(next=='\n')
        {
            next=' ';
            ++n;
        }

        word5->push_back(next);
        fin.get(next);
        if(next==' ')
        {
            *word1=*word2;
            *word2=*word3;
            *word3=*word4;
            *word4=*word5;
            word5->clear();
        }
        *line=n;
    }
    fin.close();

    return true;
}
