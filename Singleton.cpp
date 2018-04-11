#include <iostream>
using namespace std;
class Singleton
{
    private: 
    static Singleton* instance;
    Singleton() {}
    Singleton( const Singleton& );  
    Singleton& operator=( Singleton& );
    public:
        static Singleton* getInstance();
};
Singleton* Singleton::instance = 0;
Singleton* Singleton::getInstance()
{
    if (instance == 0)
    {
        instance = new Singleton();
    }

    return instance;
}
int main()
{
    
    Singleton* a = Singleton::getInstance(); 
    Singleton* b = Singleton::getInstance();
    cout<<"adresy odnakovi"<<endl;
    cout << a<< std::endl;
    cout << b << std::endl;
}
