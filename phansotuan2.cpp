#include <iostream>
using namespace std;
class phanso
{
private:
	int tuso;
	int mauso;
public:
	phanso()
	{
		tuso=1;
		mauso=1;
	}
	phanso(int a)
	{
		tuso=a;
		mauso=1;
	}
	phanso(int a, int b)
	{
		tuso=a;
		mauso=b;
	}
	phanso(phanso &ps)
	{
		tuso=ps.tuso;
		mauso=ps.mauso;
	}
	
	void datts(int ts)
	{
		tuso=ts;

	}
	void datms(int ms)
	{
		mauso=ms;
	}
	int layts()
	{
		return tuso;
	}
	int layms()
	{
		return mauso;
	}
	void inPS()
	{
		cout<<layts()<<"/"<<layms()<<endl;
	}
	int UCLN(int a,int b){
	//tim uoc chung lon nhat
		while(a!=b)
		{
			if(a>b)
			{
				a=a-b;
			}
			if(b>a)
			{
				b=b-a;
			}

		}
		return a;
	}
	phanso rutgon()
	{
		//tim uoc chung lon nhat
		int a=UCLN(tuso,mauso);
		tuso=tuso/a;
		mauso=mauso/a;
		
	}
	phanso congps(phanso a)
	{
		phanso t;
		t.tuso=tuso*a.mauso+a.tuso*mauso;
		t.mauso=mauso*a.mauso;
		return t;
	}
};
int main(int argc, char const *argv[])
{
	phanso a,b(2),c(2,6),d;
	c.inPS();

	//c.rutgon();
	c.inPS();
	d=b.congps(c);
	d.inPS();
	d.rutgon();
	d.inPS();
	return 0;
}