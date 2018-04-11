#include <iostream>
 using namespace std;
class Image
{
    int m_id;
    static int s_next;
  public:
    Image()
    {
        m_id = s_next++;
        cout << "constructor: " << m_id << '\n';
    }
    ~Image()
    {
        cout << "  destructor: " << m_id << '\n';
    }
    void draw()
    {
        cout << " maluvaty " << m_id << '\n';
    }
};
int Image::s_next = 1;
 
int main()
{
  Image images[5];
 
  for (int i; true;)
  {
    cout << "Vyhid[0], Zobrazhenia[1-5]: ";
    cin >> i;
    if (i == 0)
      break;
    images[i - 1].draw();
  }
}
