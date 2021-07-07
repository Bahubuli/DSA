#include<iostream>
using namespace std;
//#include "student.cpp"

class student
{
public:
    int roll;
    int age;

    void display()
    {
        cout << " roll no is " << roll << " age is " << age << endl;
    }
};


int main()
{
    //create objects statically
    student s1;
    student s2;
    s1.age = 23;
    s1.roll = 20534;

    //create objects dynamically
    student *s3 = new student;

    (*s3).age = 19;
    (*s3).roll = 546547;
    //both are same
    s3->roll = 345234;

    //same syntex for functions
    s3->display();



}
