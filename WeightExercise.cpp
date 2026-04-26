#include "WeightExercise.h"

WeightExercise::WeightExercise() : Exercise() {
    equipmentType = "N/A";
}

WeightExercise::WeightExercise(std::string name, std::string muscleGroup, int reps, float weight,std::string equipmentType)
    : Exercise(name, muscleGroup, reps, weight) {
    this->equipmentType = equipmentType;
}

WeightExercise::WeightExercise(const WeightExercise& obj) : Exercise(obj) {
    equipmentType = obj.equipmentType;
}

WeightExercise& WeightExercise::operator=(const WeightExercise& obj) {
    if (this == &obj)
        return *this;
    Exercise::operator=(obj);
    equipmentType = obj.equipmentType;
    return *this;
}

WeightExercise::~WeightExercise() {}

std::string WeightExercise::getEquipmentType() const {
    return equipmentType;
}

void WeightExercise::setEquipmentType(const std::string& equipmentType) {
    if (equipmentType != "barbell" && equipmentType != "dumbbell" && equipmentType != "machine")
        throw std::invalid_argument("Equipment type must be: barbell, dumbbell or machine!");
    this->equipmentType = equipmentType;
}

double WeightExercise::calculateVolume() const {
    return getReps() * getWeight();
}

std::string WeightExercise::getType() const {
    return "Weights";
}

std::ostream& operator<<(std::ostream& out, const WeightExercise& obj) {
    out << static_cast<const Exercise&>(obj);
    out << "Equipment Type: " << obj.equipmentType << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, WeightExercise& obj) {
    in >> static_cast<Exercise&>(obj);
    std::cout << "Equipment type (barbell/dumbbell/machine): ";
    std::getline(in >> std::ws, obj.equipmentType);
    return in;
}