#include <vector>
#include <iostream>
using namespace std;

class Product
{

public:
   string name;
   double price;
   bool avail;

   Product(string name, double price, bool avil) : name(name), price(price), avail(avil) {}
};

int partition(Product *p, int left, int right)
{

   int pivot = p[left].price;

   int count = 0;
   for (int i = left + 1; i <= right; ++i)
   {
      if (p[i].price < pivot)
         count++;
   }

   int pivotindex = left + count;

   swap(p[left], p[pivotindex]);

   int i = left, j = right;
   while (i < pivotindex && j > pivotindex)
   {

      while (p[i].price < pivot)
         ++i;

      while (p[j].price >= pivot)
         --j;

      if (i < pivotindex && j > pivotindex)
         swap(p[i].price, p[j].price);
   }

   return pivotindex;
}

void quicksort(Product *p, int left, int right)
{
   if (left >= right)
      return;

   int k = partition(p, left, right);

   quicksort(p, left, k - 1);
   quicksort(p, k + 1, right);
}

int main()
{

   Product p[3] = {{"lays", 1000, true}, {"cakes", 540, false}, {"biscuits", 3400, true}};

   quicksort(p, 0, 2);

   for (int i = 0; i < 3; ++i)
   {
      cout << "Product " << i + 1 << " name: " << p[i].name << endl;
      cout << "Price: " << p[i].price << endl;
      if (p[i].avail)
         cout << "In stock: " << endl;
      else
         cout << "Out of Stock: " << endl;
   }

   return 0;
}