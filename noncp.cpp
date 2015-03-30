#include<iostream>
using namespace std;
class copy{
	protected:
		copy(){}
		~copy(){}
	private:
		copy(copy& c){}
		copy& operator=(const copy&){}
};
class noncopy:private copy{
	public:
	int i;
	noncopy():i(0){}
	//noncopy(int j=0):i(j){}
	//noncopy(const noncopy& n){this->i=n.i;}

};
int main(){
	noncopy obj1();
	noncopy obj2(obj1);
}
