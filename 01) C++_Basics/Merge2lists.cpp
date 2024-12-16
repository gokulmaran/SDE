#include <bits/stdc++.h>
using namespace std;
class Node{
  public: 
     int data;
     Node*next;
     Node(int data){
         this->data=data;
         this->next=NULL;
     }
};
Node* merge2lists(Node*head1,Node*head2){
   vector<int>v;
   while(head1!=NULL){
       v.push_back(head1->data);
       head1=head1->next;
   }
   while(head2!=NULL){
       v.push_back(head2->data);
       head2=head2->next;
   }
   sort(v.begin(),v.end());
   
   Node*temp=new Node(-1);
   Node*head=temp;
   for(int i=0;i<v.size();i++){
       temp->next=new Node(v[i]);
       temp=temp->next;
   }
   head=head->next;
   return head;
}
void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
    }
}
int main() {
    //creata 
    Node*head=new Node(2);
    head->next=new Node(4);
    head->next->next=new Node(8);
    head->next->next->next=new Node(9);

    Node*head2=new Node(1);
    head2->next=new Node(3);
     head2->next->next=new Node(8);
      head2->next->next->next=new Node(10);
      Node*temp=merge2lists(head,head2);
    print(temp);
}

