/**
I usually done this homework without classes cause in my opinion thats unnecessary
It works well but this one not well
I use so many pointer in this homework when I try to implement with classes
So that i think without classes and without pointer,this work well
**/

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

///class
class SearchText{
    public:
        SearchText();
        ~SearchText();

        void setKeyWord(char*,int);
        void setReadFile(char*,int);
        void setWriteResults(char*,int);
        void enterKeyword();
        void enterReadFile();
        void enterWriteResults();
        bool getInformation();
        void writingResults();
    private:
    char *readfile,*writeresults;
    char *keyword;
    string word1,word2,word3,word4,word5;
    int line;

};


int main()
{

#ifdef TEST
    SearchText testing;
    testing.writingResults();
    testing.setReadFile("reading.txt",11);
    testing.setWriteResults("writing.txt",11);
    testing.writingResults();
#endif

    return 0;
}

///constructor
SearchText::SearchText()
{
    readfile=NULL;
    writeresults=NULL;
    keyword=NULL;
    word1.resize(0);
    word2.resize(0);
    word3.resize(0);
    word4.resize(0);
    word5.resize(0);
    line=0;
}

///destructor needed cause of pointers
SearchText::~SearchText()
{
    delete[] keyword;
    delete[] readfile;
    delete[] writeresults;
}

///setter for keyword
void SearchText::setKeyWord(char* key,int size)
{
    if(keyword!=NULL)
    delete[] keyword;
    keyword=new char[size+1];
    for(int i=0;i<size;++i)
    keyword[i]=key[i];
    keyword[size]=' ';
}

///setter for reading file
void SearchText::setReadFile(char* filename,int size)
{
    if(readfile!=NULL)
    delete[] readfile;
    readfile=new char[size];
    for(int i=0;i<size;++i)
    readfile[i]=filename[i];
}

///setter for writingresultfile
void SearchText::setWriteResults(char* filename,int size)
{
    if(writeresults!=NULL)
    delete[] writeresults;
    writeresults=new char[size];
    for(int i=0;i<size;++i)
    writeresults[i]=filename[i];
}

///getting from user file name for reading
void SearchText::enterReadFile()
{
    char *key;
    int size;
    cout<<"how long your filename"<<endl;
    cin>>size;
    key=new char[size];
    cout<<"enter keyword"<<endl;
    cin>>key;
    setReadFile(key,size);
    delete[] key;
}

///getting from user filename for result
void SearchText::enterWriteResults()
{
    char *key;
    int size;
    cout<<"how long your filename"<<endl;
    cin>>size;
    key=new char[size];
    cout<<"enter keyword"<<endl;
    cin>>key;
    setWriteResults(key,size);
    delete[] key;
}

///getting from user keyword
void SearchText::enterKeyword()
{
    char *key;
    int size;
    cout<<"how long your keyword"<<endl;
    cin>>size;
    key=new char[size];
    cout<<"enter keyword"<<endl;
    cin>>key;
    setKeyWord(key,size);
    delete[] key;
}

///search and return bool if finds or not
bool SearchText::getInformation()
{
    ifstream fin;

    fin.open(readfile);///testing opening
    if(fin.fail())
        return false;

    char next;
    int linee=1;///line number

    while( !fin.eof() )///to ENDOFFILE
    {
        if(keyword==word3)
            return true;
        if(next=='\n')
        {
            next=' ';
            ++linee;
        }

        word5.push_back(next);
        fin.get(next);
        if(next==' ')
        {
            word1=word2;
            word2=word3;
            word3=word4;
            word4=word5;
            word5.clear();
        }
        line=linee;///line number
    }
    fin.close();///closing file

    return true;
}

/// writing results on text
void SearchText::writingResults()
{
    ofstream fout;
    char choice;
    fout.open(writeresults);
    if(fout.fail())
    exit(1);

    fout<<"     KEYWORD   LINE NUMBER       --------KEYWORD       IN        CONTEXT----------"<<endl;


    do{
        enterKeyword();
        if(getInformation())
        {
            fout<<setw(WIDTH)<<keyword
            <<"  "<<setw(WIDTH)<<line
            <<"  "<<setw(WIDTH)<<word1
            <<"  "<<setw(WIDTH)<<word2
            <<"  "<<setw(WIDTH)<<word3
            <<"  "<<setw(WIDTH)<<word4
            <<"  "<<setw(WIDTH)<<word5<<endl;
        }
        cout<<"if you want to exit press E or e"
            <<"or you can type anything for continue"<<endl;
        cin>>choice;
    }while(choice!='e' && choice !='E');


    fout.close();
}
