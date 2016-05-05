///
///@date   2016-05-03 19:44:45
///
 
 
 
#include <iostream>
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

class String
{
	friend ostream&operator<<(ostream&,const String&);
public:
	class proxy
	{
	public:
		proxy(String&s,int idx)
		:_str(s)
		,_idx(idx)
		{}
		char&operator=(char);
		operator char();
	private:
		String&_str;
		int _idx;
	};
	String();
	String(const char*);
	String(const String&);
	String&operator=(const String&);
	proxy operator[](int idx);
	String(String&&);
	String&operator=(String&&);
	~String();
	int use_count();
private:
	int count();
	void decresecount();
	void incresecount();

private:
	char*_pstr;
};
