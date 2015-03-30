#include<iostream>
using namespace std;
class myclass{
	static const int size=10;
	int array[size];
	const int i;
	public:

	inline myclass(int k=0):i(k){
		for(int it=0,itt=0;it<size;array[it++]=itt++);
	}
	static int k;
	static void prints(){
		std::cout<<k;
	}
	inline void print(){
		for(int i=0;i<size;i++)
			std::cout<<array[i];
		cout<<endl;
		prints();
	}
};
int myclass::k=5;
void fun(){
	struct mycls{
		int i;
		mycls():i(0){}
	};
	mycls array[10];
	for(int i=0;i<10;i++)
		cout<<array[i].i;

}
int main(){
	myclass obj;
	obj.print();
	myclass::prints();
	cout<<"function start here";
	fun();
	
}
