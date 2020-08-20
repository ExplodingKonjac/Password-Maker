#ifndef _GLIBCXX_ALGORITHM
#include <algorithm>
#endif

#ifndef _GLIBCXX_RANDOM
#include <random>
#endif

#ifndef _GLIBCXX_FSTREAM
#include <fstream>
#endif

#ifndef _TIME_H_
#include <time.h>
#endif

#ifndef _GLIBCXX_STRING
#include <string>
#endif

#ifndef SETTINGS_H
#define SETTINGS_H

class AppSettings
{
 private:
	char l_letters[27]="abcdefghijklmnopqrstuvwxyz";
	char u_letters[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char numbers[11]="0123456789";
	char symbols[32]="~`!@#$%^&*()_-+={[}]|:;\"\'<,>.?/";
	int basic_seed;
	void output()
	{
		printf("Lower letters: %s\n",l_letters);
		printf("Upper letters: %s\n",u_letters);
		printf("Numbers: %s\n",numbers);
		printf("Symbols: %s\n",symbols);
		printf("Reorder seed: %d\n",basic_seed);
	}
	static void encrypt(char* s,int size)
	{
		for(int i=1;i<=size;i++)
			*(s++)=~(*s);
	}
 public:
	bool ll_chked=false,ul_chked=true,nb_chked=true,sb_chked=false;
	int psw_level=2;
	char app_style[20]="Fusion",app_font[20]="Consolas";
	AppSettings()
	{
		if(!load("./saves/setting.stg"))
			randSetting();
	}
	bool load(std::string file_name)
	{
		bool res=true;
		std::ifstream in(file_name,std::ios::in|std::ios::binary);
		if(in)
		{
			in.read((char*)this,sizeof(*this));
			encrypt((char*)this,sizeof(*this));
		}
		else
			res=false;
		in.close();
		return res;
	}
	void randSetting()
	{
		std::default_random_engine random(basic_seed=time(NULL));
		std::shuffle(l_letters,l_letters+26,random);
		std::shuffle(u_letters,u_letters+26,random);
		std::shuffle(numbers,numbers+10,random);
		std::shuffle(symbols,symbols+31,random);
	}
	void save(std::string file_name)
	{
		std::ofstream out(file_name,std::ios::out|std::ios::binary);
		char s[sizeof(*this)];
		memcpy(s,this,sizeof(s));
		encrypt(s,sizeof(s));
		out.write(s,sizeof(s));
		out.close();
	}
	inline char llAtPos(int pos)	{ return l_letters[pos]; }
	inline char ulAtPos(int pos)	{ return u_letters[pos]; }
	inline char nbAtPos(int pos)	{ return numbers[pos]; }
	inline char sbAtPos(int pos)	{ return symbols[pos]; }
	inline std::default_random_engine reorderFunc(int val)
		{ return std::default_random_engine(basic_seed^val); }
};

#endif // SETTINGS_H
