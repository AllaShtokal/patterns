#include <iostream>
#include <vector>
  using namespace std;
class Voin1
{
  public:
    void info() { 
      cout << "Voin1" << endl; 
    }
};
  
class Voin2
{
  public:
    void info() { 
      cout << "Voin2" << endl; 
    }
};
  
class Voin3
{
  public:        
    void info() { 
      cout << "Voin3" << endl; 
    }
};
  
class Voin4
{
  public:    
    void info() { 
      cout << "Voin4" << endl; 
    }
};
  
class Voin5
{
  public:    
    void info() { 
      cout << "Voin5" << endl; 
    }
};
  
  
// Класс "Армия", содержащий все типы боевых единиц
class Army 
{
  public:
    vector<Voin1>v1; 
    vector<Voin2>v2; 
    vector<Voin3>v3;     
    vector<Voin4>v4;     
    vector<Voin5>v5; 
    void info() {   
      int i;
      for(i=0; i<v1.size(); ++i)  v1[i].info();
      for(i=0; i<v2.size(); ++i)  v2[i].info();
      for(i=0; i<v3.size(); ++i)  v3[i].info();
      for(i=0; i<v4.size(); ++i)  v4[i].info();
      for(i=0; i<v5.size(); ++i)  v5[i].info();
    }
};
  
  
// Базовый класс ArmyBuilder объявляет интерфейс для поэтапного 
// построения армии и предусматривает его реализацию по умолчанию
 
class ArmyBuilder
{
  protected: 
    Army* p;
  public:    
    ArmyBuilder(): p(0) {}
    virtual ~ArmyBuilder() {}
    virtual void createArmy() {}
    virtual void buildVoin1() {}
    virtual void buildVoin2() {}
    virtual void buildVoin3() {}
    virtual void buildVoin4() {}
    virtual void buildVoin5() {}    
    virtual Army* getArmy() { return p; }    
};
  
  
// Римская армия имеет все типы боевых единиц кроме боевых слонов
class FirstArmyBuilder: public ArmyBuilder
{    
  public:    
    void createArmy() { p = new Army; }
    void buildVoin1() { p->v1.push_back( Voin1()); }
    void buildVoin2() { p->v2.push_back( Voin2()); }
    void buildVoin3() { p->v3.push_back( Voin3()); }    
    void buildVoin4() { p->v4.push_back( Voin4()); }
};
  
  
// Армия Карфагена имеет все типы боевых единиц кроме катапульт
class SecondArmyBuilder: public ArmyBuilder
{    
  public:    
    void createArmy() { p = new Army; }
    void buildVoin1() { p->v1.push_back( Voin1()); }
    void buildVoin2() { p->v2.push_back( Voin2()); }
    void buildVoin3() { p->v3.push_back( Voin3()); }    
    void buildVoin5() { p->v5.push_back( Voin5()); }   
};
  
  
// Класс-распорядитель, поэтапно создающий армию той или иной стороны.
// Именно здесь определен алгоритм построения армии.
class Director
{    
  public:    
    Army* createArmy( ArmyBuilder & builder ) 
    { 
        builder.createArmy();
        builder.buildVoin1();
        builder.buildVoin2();
        builder.buildVoin3();
        builder.buildVoin4();
        builder.buildVoin5();
        return( builder.getArmy());
    }
};
  
  
int main()
{   
    Director dir;
    FirstArmyBuilder f_builder;
    SecondArmyBuilder s_builder;
     
    Army * f = dir.createArmy( f_builder);
    Army * s = dir.createArmy( s_builder);
    cout << "First army:" << endl;
    f->info();
    cout << "\nSecond army:" << endl;
    s->info();
    
    return 0;
}
