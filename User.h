#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
using namespace std;

class User {
    const int id;
    string name;
    static long noUsers;
    float height;
    float weight;
    char gender;
    double BMI;

public:
    User();
    User(string name, float height, float weight, char gender);
    User(const User& obj);
    User& operator=(const User& obj);
    ~User();

    int getId() const;
    string getName() const;
    float getHeight() const;
    float getWeight() const;
    char getGender() const;
    double getBMI() const;
    string getBMICategory() const;

    void setHeight(float height);
    void setWeight(float weight);

    friend ostream& operator<<(ostream& out, const User& obj);
    friend istream& operator>>(istream& in, User& obj);

private:
    void calculateBMI();
};

#endif