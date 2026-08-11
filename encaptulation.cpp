#include <bits/stdc++.h>
using namespace std;
class Student{
public:
    //attributes
    int id;
    int age;
    string name;
    int nos;

    void setGpa(float a){
        *this->gpa=a;
    }
    float getGpa(){
        if(gpa != nullptr){
            return *gpa;
        }
        return 0.0f;
        
    }

     // Default :constructor
    Student(){
        cout<< "default constructor called..."<<endl;
        gpa = nullptr;
    }

    // Parameterised :constructor
    Student(int id,int age,string name,int nos,float gpa,string gf){
        cout<< "parameterised constructor called..."<<endl;
        this->id=id;
        this->age=age;
        this->name=name;
        this->nos=nos;
        this->gpa=new float(gpa);
        this->gf=gf;
    }

    // copy :constructor ( Student C=A )
    Student(const Student &srcobj) {
        this->id = srcobj.id;
        this->age = srcobj.age;
        this->name = srcobj.name;
        this->nos = srcobj.nos;
        this->gpa = new float(*srcobj.gpa);
        this->gf = srcobj.gf;
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

private:
    float *gpa;
    string gf;

    void gfChatting(){
        cout<<this->name<<" "<<"chatting with gf.."<<endl;
    }


};
int main(){
    Student A(1, 19, "Jai", 6, 7.46, "Sneha");
    //A.gfChatting(); ->access nahi kar sakte kyuki ye private hai)
    //A.study(); ->direct access possible kyuki ye public hai 

    cout<<A.getGpa()<<endl;
    A.setGpa(7.8);
    cout<<A.getGpa()<<endl;
    

    return 0;
}