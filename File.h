#ifndef File_H_
#define File_H_

#include <iostream>
#include <fstream>

using namespace std;

class File
{
public:
	File(void);
	~File(void);
	char* read_cities();
	char* read_con();
	char* read_bid();
	void write_file(char* str);
	void make_file();			
};

#endif