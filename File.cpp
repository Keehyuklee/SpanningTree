#include "File.h"

File::File(void)
{
}

File::~File(void)
{
}

char* File::read_cities()
{
	ifstream fin;
	char str[200]={0,};
	char* return_str;
	fin.open("mp3.cities.txt");

	if(!fin)
	{
		cout << "Error" << endl;
		return 0;
	}				
	fin.read(str,200);
	
	fin.close();	

	return_str = str;

	return return_str;
}

char* File::read_con()
{
	ifstream fin;
	char str[5000]={0,};
	char *return_str;
	fin.open("mp3.con.txt");
	if(!fin)
	{
		cout << "Error" << endl;
		return 0;
	}							
	fin.read(str,5000);	
	fin.close();			
	return_str=str;
	return return_str;		
}

char* File::read_bid()
{
	ifstream fin;
	char str[5000]={0,};
	char *return_str;
	fin.open("mp3.bid.txt");
	if(!fin)
	{
		cout << "Error" << endl;
		return 0;
	}							
	fin.read(str,5000);	
	fin.close();			
	return_str=str;
	return return_str;	
}


void File::write_file(char* str)
{
	ofstream fout;
	fout.open("mp3.out",ios::app);
	if(!fout)
	{
		cout << "Error" << endl;
		return;
	}
	fout << str;
	fout.close();
}

void File::make_file()
{
	ofstream fout;
	fout.open("mp3.out");
	fout.close();
}