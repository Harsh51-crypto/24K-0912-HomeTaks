#include <iostream>
using namespace std;
class Box
{

public:
   int *vol;

   Box()
   {
      *vol = 0;
   }

   Box(int volume)
   {

      vol = new int();
      *vol = volume;
   }

   Box(const Box &obj)
   {

      vol = new int();
      *vol = *(obj.vol);
      *vol = 99;
   }
};
int main()
{

   Box b1(4);
   Box b2 = b1;
   cout << "volume of Box 1: " << *(b1.vol) << endl;
   cout << "volume of Box 2: " << *(b2.vol) << endl;

   return 0;
}