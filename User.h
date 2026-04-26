#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <stdexcept>

class User {
    const int id;
    static long noUsers;
    std::string name;
    float height;
    float weight;
    char gender;
    double BMI;

public:
    User();
    User(std::string name, float height, float weight, char gender);
    User(const User& obj);
    User& operator=(const User& obj);
    ~User();

    int getId() const;
    std::string getName() const;
    float getHeight() const;
    float getWeight() const;
    char getGender() const;
    double getBMI() const;
    std::string getBMICategory() const;

    void setHeight(float height);
    void setWeight(float weight);

    friend std::ostream& operator<<(std::ostream& out, const User& obj);
    friend std::istream& operator>>(std::istream& in, User& obj);

private:
    void calculateBMI();
};

#endif