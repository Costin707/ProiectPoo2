#include "User.h"

long User::noUsers = 0;



User::User() : id(++noUsers) {
    name = "N/A";
    height = 0;
    weight = 0;
    gender = 'N';
    BMI = 0;
}
User::User(std::string name, float height, float weight, char gender):id(++noUsers) {
    this->name = name;
    this->height = height;
    this->weight = weight;
    this->gender = gender;
    calculateBMI();
}

void User::addWorkout(const Workout& workout) {
    workouts.push_back(workout);
}

void User::removeWorkout(int id) {
    for (int i = 0; i < workouts.size(); i++) {
        if (workouts[i].getId() == id) {
            workouts.erase(workouts.begin() + i);
            return;
        }
    }
    throw std::runtime_error("Workout not found!");
}

std::vector<Workout>& User::getWorkouts() {
    return workouts;
}

void User::calculateBMI() {
    if (height > 0 && weight > 0  )
        BMI = weight / (height * height);
    else
        BMI = 0;
}
int User::getId() const {
    return id;
}

std::string User::getName() const {
    return name;
}

float User::getHeight() const {
    return height;
}
float User::getWeight() const {
    return weight;
}

char User::getGender() const {
    return gender;
}
void User::setWeight(float weight) {
    this->weight = weight;
    calculateBMI();
}

void User::setHeight(float height) {
    this->height = height;
    calculateBMI();
}

double User::getBMI() const {
    return BMI;
}

std::string User::getBMICategory() const {
    if (BMI <= 0)
        return "N/A";
    else if (BMI < 18.5)
        return "Underweight";
    else if (BMI < 25)
        return "Normal weight";
    else if (BMI < 30)
        return "Overweight";
    else
        return "Obese";
}
User::~User() {

}
User::User(const User& obj) : id(++noUsers) {
    name = obj.name;
    height = obj.height;
    weight = obj.weight;
    gender = obj.gender;
    BMI = obj.BMI;
}

User& User::operator=(const User& obj) {
    if (this == &obj)
        return *this;

    name = obj.name;
    height = obj.height;
    weight = obj.weight;
    gender = obj.gender;
    BMI = obj.BMI;
    return *this;
}

std::istream& operator>>(std::istream& in, User& obj) {
    std::cout << "Your name: ";
    in >> obj.name;
    std::cout << "Your height (cm): ";
    in >> obj.height;
    std::cout << "Your weight (kg): ";
    in >> obj.weight;
    std::cout << "Your gender (M/F): ";
    in >> obj.gender;
    obj.calculateBMI();

    std::cout << "Account created successfully!\n";
    return in;
}

std::ostream& operator<<(std::ostream& out, const User& obj) {
    out << "Id: " << obj.id << '\n';
    out << "Name: " << obj.name<<'\n';
    out << "Height: " << obj.height << '\n';
    out << "Weight: " << obj.weight << '\n';
    out << "Gender: " << obj.gender << '\n';
    out << "BMI: " << obj.BMI << '\n';
    out << "BMI Category: " << obj.getBMICategory() << '\n';
    return out;
}

