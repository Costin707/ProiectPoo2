#include "Exercise.h"

int Exercise::noExercises = 0;

Exercise::Exercise() : id(++noExercises) {
    name = "N/A";
    muscleGroup = "N/A";
    reps = 0;
    weight = 0;
}

Exercise::Exercise(std::string name, std::string muscleGroup, int reps, float weight) : id(++noExercises) {
    this->name = name;
    this->muscleGroup = muscleGroup;
    this->reps = reps;
    this->weight = weight;
}

Exercise::Exercise(const Exercise& obj) : id(++noExercises) {
    name = obj.name;
    muscleGroup = obj.muscleGroup;
    reps = obj.reps;
    weight = obj.weight;
}

Exercise& Exercise::operator=(const Exercise& obj) {
    if (this == &obj)
        return *this;
    name = obj.name;
    muscleGroup = obj.muscleGroup;
    reps = obj.reps;
    weight = obj.weight;
    return *this;
}

Exercise::~Exercise() {}

int Exercise::getId() const { return id; }
std::string Exercise::getName() const { return name; }
std::string Exercise::getMuscleGroup() const { return muscleGroup; }
int Exercise::getReps() const { return reps; }
float Exercise::getWeight() const { return weight; }

void Exercise::setName(const std::string& name) {
    if (name.empty())
        throw std::invalid_argument("Name cannot be empty!");
    this->name = name;
}

void Exercise::setMuscleGroup(const std::string& muscleGroup) {
    if (muscleGroup.empty())
        throw std::invalid_argument("Muscle group cannot be empty!");
    this->muscleGroup = muscleGroup;
}

void Exercise::setReps(int reps) {
    if (reps <= 0)
        throw std::invalid_argument("Reps must be positive!");
    this->reps = reps;
}

void Exercise::setWeight(float weight) {
    if (weight < 0)
        throw std::invalid_argument("Weight cannot be negative!");
    this->weight = weight;
}

std::ostream& operator<<(std::ostream& out, const Exercise& obj) {
    out << "Id: " << obj.id << '\n';
    out << "Type: " << obj.getType() << '\n';
    out << "Name: " << obj.name << '\n';
    out << "Muscle Group: " << obj.muscleGroup << '\n';
    out << "Reps: " << obj.reps << '\n';
    out << "Weight: " << obj.weight << " kg\n";
    out << "Volume: " << obj.calculateVolume() << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, Exercise& obj) {
    std::cout << "Exercise name: ";
    std::getline(in >> std::ws, obj.name);
    std::cout << "Muscle group: ";
    std::getline(in >> std::ws, obj.muscleGroup);
    std::cout << "Reps: ";
    in >> obj.reps;
    std::cout << "Weight (kg, 0 if bodyweight): ";
    in >> obj.weight;
    return in;
}