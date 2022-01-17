#include "Vectop.h"
int main()
{
    
    Vector ar;
    ar.Print();
    ar.RandomFill();
    ar.Print();
    ar.Shuffle();
    ar.Print();
    ar.Reverse();
    ar.Print();
    ar.SortAsc();
    ar.Print();
    ar.SortDesc();
    ar.Print();
  //  ar.ClearZero();
  //  ar.Print();
   // ar.Clear();
   // ar.Print();
    cout <<"Capacity: " << ar.GetCapacity() << "\n";
    ar.PushBack(77);
    ar.Print();
    cout <<"Capacity: " << ar.GetCapacity() << "\n";
    ar.PushFront(99);
    ar.Print();
    cout <<"Capacity: " << ar.GetCapacity() << "\n";

    ar.Insert(78, 55);
    ar.Print();
    ar.Insert(7, 55);
    ar.Print();

    ar.RemoveAt(7, 55);
    ar.Print();

    ar.PopBack();
    ar.Print();

    ar.PopFront();
    ar.Print();

    ar.Insert(8, 67);// для проверки удаления нескольких одинаковых елементов
    ar.Print();
    ar.Remove(67);
    ar.Print();
    cout << ar.IndexOf(58) << "\n";
    cout << ar.LastIndexOf(69) << "\n";
    cout << ar.GetElementAt(5) << "\n";
    cout<< ar[2]<<"\n";


    cout << "===========================\n";
    Vector ar1;
    ar1.Print();
    ar1 = ar;
    ar1.Print();
    if (ar == ar1) cout << "true\n";

    cout << ar<<"\n";
    cin >> ar1;
    ar1.Print();
  
    system("pause>> NUL");
}


