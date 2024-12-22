#include <bits/stdc++.h>
using namespace std;
class A{
   public: 
       char*data;
       A(const char*val){
           data=new char[strlen(val)+1];
           strcpy(data,val);
       }
       A(const A&obj){
        //    data=new char[strlen(obj.data)+1];
        //    strcpy(data,obj.data);
        data=obj.data;
       }
       void display(){
           cout<<data<<endl;
       }
       ~A(){

       }
};
int main() {
    A a("hello");
    A b=a;
    a.display();
    b.display();
 
    a.data[0]='g';
    a.display();
    b.display();
 
}
