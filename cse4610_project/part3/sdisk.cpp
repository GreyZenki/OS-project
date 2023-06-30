

//Jose Rodarte 
//005985950
#include <iostream>
#include <fstream>
#include "sdisk.h"
#include <vector>
#include <string>

using namespace std;

Sdisk::Sdisk(string diskname, int numberofblocks, int blocksize)
{
    this->diskname = diskname;
    this->numberofblocks = numberofblocks;
    this->blocksize = blocksize;
    fstream iofile;
    iofile.open(diskname.c_str(), ios::in);
    if (iofile.good()) 
    {
        cout << "checking disk" << endl;
        int count = 0;
        char c;
        iofile.get(c);
        while (iofile.good()) 
        {
            count++;
            iofile.get(c);
        }
        if (count = numberofblocks * blocksize) 
        {
            cout << "disksize is correct" << endl;
        }
    }
    else {
        iofile.close();
        cout << "creating sdisk" << endl;
        iofile.open(diskname.c_str(), ios::out);
        for (int i = 0; i < blocksize * numberofblocks; i++) {
            iofile.put('#');  
        }
        cout << "sdisk has been made" << endl;
    }
    iofile.close();
    return;
}//end constructor

int Sdisk::getblock (int blocknumber, string& buffer)
{
    //error checks
    //eg o < blocknumber < number of blocks
    //return 0
    fstream iofile;
    iofile.open(diskname.c_str(), ios::in | ios:: out);
    char c;
    buffer.clear();
    iofile.seekg(blocknumber * blocksize);
    for(int i = 0; i < blocksize; i++);
    {
        iofile.get(c);
        buffer +=c;
        //buffer = buffer+c;

    }
    return 1;
}

int Sdisk::getblocksize()
{
    return this->blocksize;
}

int Sdisk::getnumberofblocks()
{
    return this->numberofblocks;
}

int Sdisk::putblock(int blocknumber, string buffer)
{
    /*
    check
    1.blocknumber > 0
    2.blocknumber < number of blocks
    3.buffer.length()==blocksize
    */

   fstream iofile;
   iofile.open(diskname.c_str(), ios::in | ios::out);
   iofile.seekg(blocknumber * blocksize);
   for(int i=0; i < blocksize; i++)
   {
    iofile.put(buffer[i]);
   }
   return 1;
}//putback
