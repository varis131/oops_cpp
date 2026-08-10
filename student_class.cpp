#include <bits/stdc++.h>
using namespace std;
class Student{
    public:
    //attributes
    int id;
    int age;
    string name;
    int nos;
    float *gpa;

    // Default :constructor
    Student(){
        cout<< "default constructor called..."<<endl;
    }

    // Parameterised :constructor
    Student(int id,int age,string name,int nos,float gpa){
        cout<< "parameterised constructor called..."<<endl;
        this->id=id;
        this->age=age;
        this->name=name;
        this->nos=nos;
        this->gpa=new float(gpa);
    }

    // copy :constructor ( Student C=A )
    Student(const Student &srcobj){
        cout<< "Student copy constructor called..."<<endl;
        this->id=srcobj.id;
        this->age=srcobj.age;
        this->name=srcobj.name;
        this->nos=srcobj.nos;
    }

    

    //behaviour/mathods
    void sleep(){
        cout<<this->name<<" "<<"sleeping"<<endl;
    }
    void study(){
        cout<<this->name<<" "<<"studying"<<endl;
    }
    void bunk(){
        cout<<this->name<<" "<<"bunking"<<endl;
    }

    //destructor
    // ye memory leak wagaira me help karta hai 
    // maan lo tum dynamic memory allocate karte ho like int *gpa; to ise delete gpa; likhna hoga destructor me 
    ~Student(){
        cout<< "default destructor called..."<<endl;
        delete gpa;
    }



};
int main(){

    // 1-> sabse basic way 

    // Student A;
    // A.id=1;
    // A.age=21;
    // A.name="varis";
    // A.nos=6;
    // A.study();

    // Student B;
    // B.id=1;
    // B.age=21;
    // B.name="ishek";
    // B.nos=6;
    // B.bunk();


    //2-> parameterised way

    // Student A(1,21,"varis",6);
    // Student B(2,20,"ishek",5);
    // cout<<A.name<<" "<<A.age<<" "<<endl;
    // cout<<B.name<<" "<<B.age<<" "<<endl;
    // A.study();
    // B.study();

    //3-> copy constructor wala tarika 

    // Student C=A;
    // Student C(A);
    // cout<<C.name<<" "<< A.name<<endl;

    //4-> Dynamic allocation or student pointer 

    Student *A=new Student(1,21,"varis",6,8.2);
    cout<<A->name<<" "<<A->age<<" "<<*A->gpa<<endl;
    A->study();
    A->bunk();
    delete A;//dynamic allocatin me khud se hi allocated memory ko delete karna padta  hai 





    return 0;
}