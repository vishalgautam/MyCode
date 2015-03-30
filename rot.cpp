#include<iostream>
#include<map>
using namespace std;
int main()
{
  multimap <char,int> mymm;
  multimap<char,int>::iterator it;
  char c;
  mymm.insert(pair<char,int>('x',50));
  mymm.insert(pair<char,int>('y',100));
  mymm.insert(pair<char,int>('y',150));
  mymm.insert(pair<char,int>('y',200));
  mymm.insert(pair<char,int>('z',250));
  mymm.insert(pair<char,int>('z',250));

  /*for (c='x'; c<='z'; c++)
  {
    cout << "There are " << (int)mymm.count(c);
    cout << " elements with key " << c << ":";
    for (it=mymm.equal_range(c).first; it!=mymm.equal_range(c).second; ++it)
      cout << " " << (*it).second;
    cout << endl;
  }*/
cout<<mymm.size();
  return 0;
}
