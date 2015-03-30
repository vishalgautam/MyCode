#include<iostream>
using namespace std;
class april{
    private:
        int count;
    public:
        april():count(0){}
        void display(){
            cout<<count;
        }
};
int main(){
    april mapril;
    mapril.display();
}
