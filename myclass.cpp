#include<iostream>
using namespace std;
class myclass {
	private:
		int num;
		int gun(){}
	public:
		int i;
		int j;
		myclass():i(0),j(0){}
		int get(){
			return i;
		}
		void set(int k=0){
			i=j=k;
		}
		static int numi(){return 1;}
};
int main(){
	myclass obj;
	obj.numi();
	obj.get();
	obj.set(1);
	obj.set(2);
	obj.i=1;



}
