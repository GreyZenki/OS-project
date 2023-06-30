//Jose Rodarte 
//005985950
#include <iostream>
#include "sdisk.h"
#include "filesys.h"
#include "shell.h"
#include "block.h"
#include <vector>
#include <string>

using namespace std;

Shell::Shell(string filename, int numberofblocks, int blocksize):Filesys(filename, numberofblocks, blocksize)
{
    
}
int Shell::dir()
{
    vector<string> flist=ls();
    for (int i=0; i<flist.size(); i++)
    {
        cout << flist[i] << endl;
    }
    return 1;
}

int Shell::add(string file,string buffer)
{
    int errorcode=newfile(file);
    if(errorcode == 0)
    {
        //file cannot be created
        return 0;
    }
    vector<string>blocks=block(buffer,getblocksize());
    for(int i=0; i<blocks.size(); i++)
    {
        errorcode=addblock(file,blocks[i]);
    }
    return 1;
}

int Shell::del(string file)
{
    int b = getfirstblock(file);
    if(b==-1)
    {
        return 0;
    }
     if(b==0)
    {
        return 1;
    }
    while(b!=0)
    {
        delblock(file,b);
        b=getfirstblock(file);
    }
    rmfile(file);
    return 1;
}
/* //did this one without looking but also in my notes the line before i did return 1 i dont know if its that way or the one above need to double check
int Shell::add(string file, string buffer)
{
    int errorcode = newfile(file);
    if(errorcode == 0)
    {
        //file cannot be created
        return 0;
    }
    vector<string> blocks=block(buffer, getblocksize());
    for (int i=0; i<blocks.size(); i++)
    {
        addblock(file,blocks[i]); // = errorcode
    }
    return 1;
}
*/
int Shell::type(string file)
{
    string buffer1;
    string buffer2;
    int b=getfirstblock(file);
    if(b==-1)
    {
        //no file
        cout<<"no such file";
        return -1;
    }
    if(b==0)
    {
        cout << buffer2;
    }
    while(b!=0)
    {
        readblock(file, b, buffer1);
        buffer2 += buffer1;
        b = nextblock(file,b);
        cout << buffer2 << " ";
    }
    cout<<buffer2;
    return 1;
}

int Shell::copy(string file1, string file2)
{
    int b1 = getfirstblock(file1);
    //error checks
    int b2 = newfile(file2);
    //if file 2 exist exit
    string buffer;
    while (b1!=0)
    {
        readblock(file1,b1,buffer);
        b1=nextblock(file1,b1);
        addblock(file2,buffer);
    }
    return 1;
}

