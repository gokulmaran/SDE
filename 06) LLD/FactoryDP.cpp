//factory design pattern
#include <iostream>
using namespace std;
//Absract interface
class A{
  public:
      virtual void draw()=0;    
};
//concrete class 1
class circle:public A{
    public:
      void draw(){
          cout<< "circle displayed"<<endl;
      }
};
//concrete class 2
class square:public A{
    public:
       void draw(){
           cout<<"square displayed"<<endl;
       }
};
//factory interface
class Shapefactory{
    public:
  static A*createShape(string type){
      if(type=="circle"){
          return new circle();
      }
      if(type=="square"){
          return new square();
      }
      return nullptr;
   }
};
int main() {
    A *a=Shapefactory::createShape("square");
    if(a){
        a->draw();
    }
}
