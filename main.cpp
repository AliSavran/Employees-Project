#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int id;
    double salary;
    string expertise;

public:
    Employee(const string &name = "", int id = 0, double salary = 0.0, const string &expertise = "") {
        this->name = name;
        this->id = id;
        this->salary = salary;
        this->expertise = expertise;
    }

    string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    double getSalary() const {
        return salary;
    }

    string getExpertise() const {
        return expertise;
    }

    void setSalary(double newSalary) {
        salary = newSalary;
    }
};

class Company {
private:
    Employee *employees;
    int capacity;
    int employeecount;

    void expand() {
        int newCapacity = capacity * 2;
        Employee *newEmployees = new Employee[newCapacity];
        for (int i = 0; i < employeecount; i++) {
            newEmployees[i] = employees[i];
        }
        delete[] employees;
        employees = newEmployees;
        capacity = newCapacity;
    }

public:
    Company(int initialcapacity = 10) {
        capacity = initialcapacity;
        employeecount = 0;
        employees = new Employee[capacity];
    }

    ~Company() {
        delete[] employees;
    }

    void addEmployee(const string &name, int id, double salary, const string &expertise) {
        if (employeecount == capacity) {
            expand();
        }
        employees[employeecount++] = Employee(name, id, salary, expertise);
    }

    void updateSalary(int id, double newSalary) {
        for (int i = 0; i < employeecount; i++) {
            if (employees[i].getId() == id) {
                employees[i].setSalary(newSalary);
                cout << employees[i].getName() << " maasi guncellendi: " << newSalary << endl;
                return;
            }
        }
        cout << "Calisan bulunamadi: ID " << id << endl;
    }

    void printSalaries() const {
        for (int i = 0; i < employeecount; i++) {
            cout << "Calisan Adi: " << employees[i].getName() << endl;
            cout << "Calisan ID: " << employees[i].getId() << endl;
            cout << "Calisan Maas: " << employees[i].getSalary() << endl;
            cout << "Calisan Uzmanlik: " << employees[i].getExpertise() << endl;
        }
    }
};

int main() {
    Company company;

    company.addEmployee("Ali", 458, 20000, "Game Developer\n");
    company.addEmployee("Mehmet", 753, 15000, "Yapay Zeka\n");
    company.addEmployee("Burcu", 246, 10000, "Sound Designer\n");

    cout << "Baslangic Maaslari:\n" << endl;
    company.printSalaries();

    company.updateSalary(458, 30000);
    company.updateSalary(753, 25000);

    cout << "\nGuncellenmis Maaslar:" << endl;
    company.printSalaries();

    return 0;
}
