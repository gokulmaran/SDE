//function template
#include <iostream>
using namespace std;
template<typename T>
T sum(T a,T b){
    return a+b;
}
int main() {
    cout<<sum(5,6);
}
//class template
#include <iostream>
using namespace std;
template<typename T>
class A{
   public:
      T num1,num2;
   A(T a,T b) :num1(a),num2(b) {};
   T add(){
       return num1+num2;
   }
   T sub(){
       return num1-num2;
   }
};
int main(){
    A<int> intCal(4,5);
    cout<< intCal.add();
    cout<< intCal.sub();
}