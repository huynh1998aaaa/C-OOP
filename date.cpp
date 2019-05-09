#include <iostream>
using namespace std;
class date
{
private:
	int ngay;
	int thang;
	int nam;
public:

	date()
	{
		ngay=1;
		thang=1;
		nam=1;

	}
	date(int a)
	{
		ngay=a;
		thang=1;
		nam=1;

	}
	date(int a,int b)
	{
		ngay=a;
		thang=b;
		nam=1;
	}
	date(int a,int b,int c)
	{
		ngay=a;
		thang=b;
		nam=c;
	}
	friend istream& operator >>(istream &in, date a)
	{
		in>>a.ngay;
		in>>a.thang;
		in>>a.nam;
		return in;
	}
	friend ostream& operator <<(ostream &out,date a)
	{
		out<<a.ngay<<"/"<<a.thang<<"/"<<a.nam;
		return out;
	}
	void advance()
	{
		if(ngay>31 and (thang ==1 or thang==3 or thang==5 or thang==7 or thang==8 or thang==10 or thang==12))
		{
			thang=thang+1;
			ngay=ngay-31;
		}
		if(ngay>30 and (thang==4 or thang== 6  or thang==9 or thang==11))
		{
			thang=thang+1;
			ngay=ngay-30;
		}
		if(ngay==31 and thang ==12)
		{
			nam=nam+1;
			thang=1;
			ngay=1;
		}
	}
	date operator ++ (int )
	{
		date b;
		ngay=ngay+1;
		advance();
		return *this;
	}
	friend date operator -=( date a, date b)
	{
		a.ngay=a.ngay-b.ngay;
		a.thang=a.thang-b.thang;
		a.nam=a.nam-b.nam;
		a.advance();
	}

};
int main(int argc, char const *argv[])
{
	date ng1, ng2(3),ng3(4,5),ng4(1,1,2019),ng5;
	ng4++;
	cout<<ng4;
	return 0;
}