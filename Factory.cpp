#include <iostream>
#include <vector>
using namespace std;
class Voin
{
  public:
    virtual void info() = 0;     
    virtual ~Voin() {}
};
class Voin1 :public Voin
{
     void info()
     {
     	cout<<"Voin1"<<endl;
	 };
	 
};
class Voin2 :public Voin
{
     void info()
     {
     	cout<<"Voin2"<<endl;
	 };
	 
};
class Voin3 :public Voin
{
     void info()
     {
     	cout<<"Voin3"<<endl;
	 };
	 
};

class Fabryka {
	public:
	virtual Voin* createVoin()=0;
	virtual ~Fabryka() {};
	};
class Fabryka1: public Fabryka {
	public:
		Voin* createVoin()
		{
			return new Voin1;
		}
	
};
class Fabryka2: public Fabryka {
	public:
		Voin* createVoin()
		{
			return new Voin2;
		}
	
};
class Fabryka3: public Fabryka {
	public:
		Voin* createVoin()
		{
			return new Voin3;
		}
	
};	
int main()
{

Fabryka1* fabryka1 = new Fabryka1;
Fabryka2* fabryka2 = new Fabryka2;
Fabryka3* fabryka3 = new Fabryka3;

vector<Voin*>v;
v.push_back(fabryka1->createVoin())	;
v.push_back(fabryka2->createVoin())	;
v.push_back(fabryka2->createVoin())	;

for(int i =0;i<v.size();i++)
v[i]->info();
	
}
