#include<iostream>
#include<vector>
using namespace std;

struct Employee {
    string name;
    int age;
    double salary;
};

struct Dept {
    string name;
    vector<Employee> employee_ls;
    float kpi;
};

struct Company {
    string name;
    vector<Dept> department_ls;
    float stock_price;
};

int main() {
    Employee p1 = {
            "Mr. Thomson",
            21,
            200.21
    };

    vector<Employee> emp_ls_IT = {
        p1,
        {
            "Miss James",
            79,
            2003.21
        }
    };

    Dept IT = {
        "IT",
        emp_ls_IT,
        21.3
    };

    vector<Dept> department_ls = {
        IT, 
        {
            "Finance",
            emp_ls_IT,
            21.3
        }
    };

    cout << department_ls[1].name << endl;
    return 0;

}
