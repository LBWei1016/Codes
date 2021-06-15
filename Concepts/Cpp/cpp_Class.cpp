#include <iostream>

using namespace std;

class Animal
{
    private:
        const int id; 
        //private members can only be accessed through "member functions"
        //const variables must be initialized once declared("id" will be initialized when constructor is called)
    public:
        Animal() : id(0){}; //defined inside class
        Animal(string, int); //only declared
        ~Animal(); //destructor; automatically called at the end of a function
        string name;
        int age;
        void Talk();
        void set_id(int t);
        void display();
    
};
Animal::Animal(string name, int age) : id(0) //define constructor, initializing const int "id" simultaneously
{
    this->name = name;
    this->age = age;
}
Animal::~Animal()
{
    cout << "object destructed\n"; 
}
void Animal::Talk()
{
    cout << this->name + "\n";
}
void Animal::display()
{
    cout << id << endl;
}

int main()
{
    Animal dog, cat("CAT", 10);
    dog.name = "DOG";
    dog.Talk();
    dog.display();
    cat.Talk();
    
    return 0;
}
/*
    �B��l�禡����ع�@�覡
        1. �����禡(Member functions)
        ? �ϥ�this�Ө��o�D�n�B�⤸
        ? ��l�B�⤸���ѼƦC�W
        ? �̥��䪺���󫬺A������B��l�����O�ۦP
        ? �p:Date1+Date2, �hDate1��operator+(Date2)�禡�Q�I�s

        2. �D�����禡(Non member functions)
        ? �C�ӹB�⤸�Ҧ��ѼƦC�W
        ? �̥��䪺���󫬺A�i�H��B�⤸�����O���P
        ? �p�n�s��private��protected��Ʀ���,�h�����Ofriend
        ? �p:Date1+Date2, �hoperator+(Date1, Date2)�禡�Q�I�s
*/