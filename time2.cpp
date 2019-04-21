#include <iostream>
using namespace std;



class TIME
{
private:
	int h;
	int p;
	int g;
public:
	TIME()
	{
		h=0;
		p=0;
		g=0;
	}
	TIME(int a)
	{
		h=a;
		p=0;
		g=0;
	}
	TIME(int a,int b)
	{
		h=a;
		p=b;
		g=0;
	}
	TIME(int a,int b,int c)
	{
		h=a;
		p=b;
		g=c;
	}
	friend istream& operator >>(istream&in, TIME &a)
	{
		in>>a.h;
		in>>a.p;
		in>>a.g;
		return in;
	}
	friend ostream& operator<<(ostream& out, TIME a)
	{
		out<<a.h<<":"<<a.p<<":"<<a.g;
		return out;
	}
	int  CountSecond()
	{
		int t;
		t=h*3600+p*60+g;
		return t;
	}
	void advance()
	{
    while(g>=60)
    {
      p=p+1;
      g=g-60;
    }
    while(p>=60)
    {
      h=h+1;
      p=p-60;
    }

    while(h>24)
    {  
    	h=h-24;
    }
    if(h==24)
    {
    	h=0;
    }
	}
	TIME operator +(int b)
	{
		TIME c;
		c.h=h;
		c.p=p;
		c.g=g+b;
		c.advance();
		return c;
	}
	friend TIME operator +(int b,TIME a)
	{
		TIME c;
		c.h=a.h;
		c.p=a.p;
		c.g=a.g+b;
		c.advance();
		return c;
	}
	TIME operator +(TIME b)
	{
		TIME c;
		c.h=h+b.h;
		c.p=p+b.p;
		c.g=g+c.g;
		c.advance();
		return c;
	}
		//  tru gio
	TIME operator -(int b)
	{
		TIME c;
		c.h=h;
		c.p=p;
		c.g=g+b;
		c.advance();
		return c;
	}
	
	friend TIME operator -(int b,TIME a)
	{
		TIME c;
		c.h=a.h;
		c.p=a.p;
		c.g=a.g-b;
		c.advance();
		return c;
	}
	
	TIME operator -(TIME b)
	{
		TIME c;
		c.h=h-b.h;
		c.p=p-b.p;
		c.g=g-c.g;
		c.advance();
		return c;
	}
	
		
	


};
int main(int argc, char const *argv[])
{
	TIME t1(7,30,0),t2(23),t3;
	cout<<t1<<" ; "<<t2<<" : "<<t3<<endl;
	cout<<t1.CountSecond()<<";"<<t2.CountSecond()<<endl;;
	
	t3=t2+120;
	cout<<t3<<endl;
	TIME t4=3601+t2;
	cout<<t4<<endl;

return 0;}