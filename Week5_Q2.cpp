#include<iostream>
using namespace std;
class time
{
	int hr,min,sec;
	public:
		void constructor()
		{
			hr=min=sec=0;
		}
		void input()
		{
			constructor();
			cout<<"Enter Hour, Minute, Second:"<<endl;
			cin>>hr>>min>>sec;
			cout<<endl;
		}
		void show()
		{
			cout<<hr<<"hr:"<<min<<"min:"<<sec<<"Sec:"<<endl;
		}
		friend time add(time ob1, time ob2);
		friend time sub(time ob1, time ob2);
		friend void comp(time ob1, time ob2);
};
 time add(time ob1, time ob2)
{
	time o, temp;
	o.sec=ob1.sec+ob2.sec;
	temp.sec= o.sec/60;
	o.sec= o.sec % 60;
	o.min=ob1.min + ob2.min + temp.sec;
	temp.min= o.min / 60 ;
	o.min = o.min % 60 ;
	
	o.hr = ob1.hr + ob2.hr + temp.min;
	
	if(o.hr>24)
	{
		o.hr=o.hr/24;
		o.min= o.min + o.hr % 24;
	} 
	 return o;
}
time sub(time ob1, time ob2)
{
	time o;
	o.hr= ob1.hr - ob2.hr; 
	o.min= ob1.min - ob2.min;
	o.sec= ob1.sec - ob2.sec;
	return o;
}
void comp(time ob1, time ob2)
{
	int a=ob1.hr + ob1.min+ ob1.sec;
	int b = ob2.hr+ ob2.min+ ob2.sec;
	
	if (a<b)
	cout<< "Time 1 is small"<<endl;
	else
	cout<<"Time 2 is small"<<endl;
}
int main()
{
	time ob1,ob2,ob;
	ob1.input(); 
	ob2.input();
	ob=add(ob1,ob2);
	ob.show();
	ob=sub(ob1,ob2);
	ob.show();
	comp(ob1,ob2);
}
