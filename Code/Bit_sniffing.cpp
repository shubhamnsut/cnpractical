// Enter size: 10 
// Enter bits: 1 0 1 0 1 1 1 1 1 1 
// frame sent: 1 0 1 0 1 1 1 1 1 0 1
// Received Output: 1 0 1 0 1 1 1 1 1 1

#include<iostream>
using namespace std;
class stuffing
{
	int *a,sum,sz,i;
	public:
		stuffing(int n)
		{
			sz=n,sum=0;
			a=new int[n];
		}
		void input()
		{
			cout<<"Enter Bits:";
			for(i=0;i<sz;i++)
			{
				cin>>a[i];
				if(a[i]!=0 && a[i]!=1)
				{
					cout<<"\nWrong Input\n";
					//exit(0);
				}
			}
		}
		void count(int x)
		{
			sum=0;
			for(i=0;i<sz;i++)
			{
				if(a[i]==1)
					sum++;
				if(a[i]==0)
					sum=0;
				if(sum==5)
					if(x==1)
					{
						for(int j=sz;j>(i+1);j--)
							a[j]=a[j-1];
						a[i+1]=0;
						sz++;
						sum=0;
					}
					else
					{
						for(int j=i+1;j<sz;j++)
							a[j]=a[j+1];
						sz--;
						sum=0;
					}
			}
		}
		void display()
		{
		//	cout<<" SZ:"<<sz;
			for(i=0;i<sz;i++)
				cout<<a[i]<<" ";
			cout<<endl;
			sum=0;
		}
};
int main()
{
	int sz;
	cout<<"Enter Size:";
	cin>>sz;
	stuffing s(sz);
	s.input();
	s.count(1);
	cout<<"\nFream sent:";
	s.display();
	cout<<"\n\nReceived Output:";
	s.count(2);
	s.display();
	return 0;
}
