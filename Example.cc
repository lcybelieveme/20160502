///
///@date   2016-05-03 23:36:06
///
 
 
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template<typename T>
class RAII
{
	public:
		RAII(T*p);
		~RAII();
		T*operator*();
		T*operator->()
		{
			return _p;
		}
	private:
		T*_p;
};

template<typename T>
T*RAII<T>::operator*()
{
	return _p;
}



	template<typename T>
	RAII<T>::RAII(T*p)
:_p(p)
{
}

	template<typename T>
RAII<T>::~RAII()
{
	if(_p)
	{
		cout<<"~RAII()"<<endl;
		delete _p;
	}
}



class resource
{
	public:
		resource()
			:data(new char[1024])
		{}
		~resource()
		{
			cout<<"~resource"<<endl;
			delete data;
		}

		void display()
		{
			cout<<"display"<<endl;
		}
	private:
		char *data;
};

class example
{
	public:
		example()
			:_p1(new resource())          //构造函数
			 ,_p2(new resource())
	{
	}
		void display()
		{
			_p1->display();
			_p2->display();
		}
	private:
		RAII<resource> _p1;           //模板类对象
		RAII<resource> _p2;
};

int main()
{
	example ex;
	ex.display();
	
}
