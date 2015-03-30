#include<iostream>
template<unsigned int N>
struct binary{
    static const unsigned int value= binary<N/10>::value<<1|N%10;
};
template<>
struct binary<0>{
    static const unsigned int value=0;
};

int main(){
    std::cout<<binary<101010>::value<<std::endl;
    return 0;
}
