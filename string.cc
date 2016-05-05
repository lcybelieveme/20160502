///
///@date   2016-05-03 20:00:43
///
 
 
#include "string.hh" 
#include <iostream>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;

int String::count()
{
	return strlen(_pstr);
}

void String::decresecount()
{
	--_pstr[count()+1];
}

void String::incresecount()
{
	++_pstr[count()+1];
}

int String::use_count()
{
	return _pstr[count()+1];
}

String::String()
{
	_pstr=new char[2];
	_pstr[1]=1;
}

String::String(const char*s)
{
	cout<<"String(const char*s)"<<endl;
	_pstr=new char[strlen(s)+2];
	strcpy(_pstr,s);
	_pstr[strlen(s)+1]=1;
}

String::String(const String&s)
{
	cout<<"String(const String&)"<<endl;
	_pstr=s._pstr;
//	cout<<_pstr<<endl;
	incresecount();	
}

String&String::operator=(const String&s)
{
//	cout<<"operator=(const String&)"<<endl;
	if(this != &s)
	{
		if(use_count()==1)
		{
			delete _pstr;
		}
		else
		{
			decresecount();
		}
		_pstr=s._pstr;
		++_pstr[count()+1];
	}
	return *this;
}

String::~String()
{
	cout<<"~String()"<<endl;
	if((use_count())==1)
	{
		delete _pstr;
	}
	--_pstr[count()+1];
}

String::proxy String::operator[](int idx)
{
	return proxy(*this,idx);
}
#if 0
String::proxy::proxy(String&s,int idx)
:_str(s)
,_idx(idx)
{}
#endif

char&String::proxy::operator=(char s)
{
	_str.decresecount();
	if(_str.count()!=0)
	{
		char *temp=new char[_str.count()+2];
		strcpy(temp,_str._pstr);
		temp[_str.count()+1]=1;
		_str._pstr=temp;
		_str._pstr[_idx]=s;
		return _str._pstr[_idx];
	}
	_str.incresecount();
	_str._pstr[_idx]=s;
	return _str._pstr[_idx];
}

String::proxy::operator char()
{
	return _str._pstr[_idx];
}

ostream&operator<<(ostream&os,const String&s)
{
	os<<s._pstr;
	return os;
}

String::String(String&&s)
:_pstr(s._pstr)
{
	cout<<"String(String&&)"<<endl;
//	cout<<_pstr<<endl;
//	cout<<use_count()<<endl;
	incresecount();
//	s._pstr=NULL;
}

String&String::operator=(String&&s)
{
	cout<<"operator=(String&&)"<<endl;
	if(use_count()==1)
	{
		delete _pstr;
	}else
	{
		decresecount();
	}
	_pstr=s._pstr;
	incresecount();
	return *this;
}


int main()
{
	String s0="Hello";
//	cout<<s0.use_count()<<endl;
//	String s1(std::move(s0));
//	cout<<s1.use_count()<<endl;
//	cout<<s1<<endl;
}


