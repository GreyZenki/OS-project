#ifndef TABLE_H
#define TABLE_H

#include "filesys.h"



class Table : public Filesys
{
public :
Table(string diskname,int blocksize,int numberofblocks, string flatfile, string indexfile);
int Build_Table(string input_file);
int Search(string key);
private :
string flatfile;
string indexfile;
int IndexSearch(string key);
};

#endif