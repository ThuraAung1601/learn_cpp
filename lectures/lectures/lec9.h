#include <string>
using namespace std;

enum Grade {
    A, B, C
};

class People {
    protected: 
        string name; int age;
    public:
        People() {}
        virtual ~People() {}
        People(string name, int age);
        virtual void setAge(int age) = 0;
        virtual int getAge() const = 0;
};

class Student : public People {
    private:
        Grade grade; 
    public:
        Student() {}
        Student(string name, int age, Grade grade);
        void setAge(int age) override;
        int getAge() const override;
        Grade getGrade() const;
};