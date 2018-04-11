#include <iostream>
#include <vector>
  using namespace std;

class Voin
{
  public:   
    virtual  Voin* clone() = 0;
    virtual void info() = 0;        
    virtual ~Voin() {}
};
class Voin1: public Voin
{
    friend class PrototypeFactory;
  public:   
    Voin* clone() { 
      return new Voin1( *this); 
    }
    void info() { 
      cout << "Voin1" << endl; 
    } 
  private:
    Infantryman() {}    
};
  
class Voin2: public Voin
{
    friend class PrototypeFactory;
  public:   
    Voin* clone() { 
      return new Voin2( *this); 
    }  
    void info() { 
      cout << "Voin2" << endl; 
    }
  private:  
    Voin2() {} 
};
  
class Voin3: public Voin
{
    friend class PrototypeFactory;
  public:    
    Voin* clone() { 
      return new Voin3( *this); 
    }
    void info() { 
      cout << "Voin3" << endl; 
    }
  private:  
    Voin3() {}
};

class PrototypeFactory
{
  public:   
    Voin* createVoin1() {       
      static Voin1 prototype;
      return prototype.clone();
    }
    Voin* createVoin2() {       
      static Voin2 prototype;
      return prototype.clone();
    }
    Voin* createVoin3() {     
      static Voin3 prototype;
      return prototype.clone();
    }
};
  
  
int main()
{    
  PrototypeFactory factory;
  vector<Voin*> v;
  v.push_back( factory.createVoin1());
  v.push_back( factory.createVoin2());
  v.push_back( factory.createVoin3());   
  
  for(int i=0; i<v.size(); i++)
    v[i]->info();
    // ...
}
