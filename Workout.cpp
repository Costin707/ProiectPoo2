#include "Workout.h"

int Workout::noWorkouts = 0;

Workout::Workout() : id(++noWorkouts) {
    name = "N/A";
}

Workout::Workout(std::string name) : id(++noWorkouts) {
    this->name = name;
}

Workout::Workout(const Workout& obj) : id(++noWorkouts) {
    name = obj.name;
    for (Exercise* ex : obj.exercises) {
        exercises.push_back(ex);
    }
}

Workout& Workout::operator=(const Workout& obj) {
    if (this == &obj)
        return *this;
    name = obj.name;
    exercises.clear();
    for (Exercise* ex : obj.exercises) {
        exercises.push_back(ex);
    }
    return *this;
}

Workout::~Workout() {
    for (Exercise* ex : exercises) {
        delete ex;
    }
    exercises.clear();
}

int Workout::getId() const { return id; }
std::string Workout::getName() const { return name; }

void Workout::setName(const std::string& name) {
    if (name.empty())
        throw std::invalid_argument("Workout name cannot be empty!");
    this->name = name;
}

void Workout::addExercise(Exercise* exercise) {
    if (exercise == nullptr)
        throw std::invalid_argument("Exercise cannot be null!");
    exercises.push_back(exercise);
}

void Workout::removeExercise(int id) {
    for (int i = 0; i < exercises.size(); i++) {
        if (exercises[i]->getId() == id) {
            delete exercises[i];
            exercises.erase(exercises.begin() + i);
            return;
        }
    }
    throw std::runtime_error("Exercise not found!");
}

double Workout::calculateTotalVolume() const {
    double total = 0;
    for (Exercise* ex : exercises) {
        total += ex->calculateVolume(); // polimorfism!
    }
    return total;
}

std::ostream& operator<<(std::ostream& out, const Workout& obj) {
    out << "Id: " << obj.id << '\n';
    out << "Name: " << obj.name << '\n';
    out << "Exercises: " << obj.exercises.size() << '\n';
    out << "Total Volume: " << obj.calculateTotalVolume() << '\n';
    out << "------------------------\n";
    for (Exercise* ex : obj.exercises) {
        out << *ex << '\n';
    }
    return out;
}

std::istream& operator>>(std::istream& in, Workout& obj) {
    std::cout << "Workout name: ";
    std::getline(in >> std::ws, obj.name);
    return in;
}