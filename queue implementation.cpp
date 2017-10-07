
#include <iostream>       
#include <queue>          
using namespace std;

int main ()
{
  queue<int> myqueue;
  int myint;

  cout << "enter nos"<<endl;;

  do {
    cin >> myint;
    myqueue.push (myint);
  } while (myint);

  cout << "myqueue contains: ";
  while (!myqueue.empty())
  {
    cout << ' ' << myqueue.front();
    myqueue.pop();
  }
  

  
}
