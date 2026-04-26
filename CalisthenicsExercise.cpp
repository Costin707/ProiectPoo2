#include "CalisthenicsExercise.h"

CalisthenicsExercise::CalisthenicsExercise() : Exercise() {
    difficulty = "beginner";
    requiresEquipment = false;
    userWeight = 0;
}

CalisthenicsExercise::CalisthenicsExercise(std::string name, std::string muscleGroup, int reps, float weight,
                                           std::string difficulty, bool requiresEquipment, float userWeight)
    : Exercise(name, muscleGroup, reps, weight) {
    this->difficulty = difficulty;
    this->requiresEquipment = requiresEquipment;
    this->userWeight = userWeight;
}

CalisthenicsExercise::CalisthenicsExercise(const CalisthenicsExercise& obj) : Exercise(obj) {
    difficulty = obj.difficulty;
    requiresEquipment = obj.requiresEquipment;
    userWeight = obj.userWeight;
}

CalisthenicsExercise& CalisthenicsExercise::operator=(const CalisthenicsExercise& obj) {
    if (this == &obj)
        return *this;
    Exercise::operator=(obj);
    difficulty = obj.difficulty;
    requiresEquipment = obj.requiresEquipment;
    userWeight = obj.userWeight;
    return *this;
}

CalisthenicsExercise::~CalisthenicsExercise() {}

std::string CalisthenicsExercise::getDifficulty() const { return difficulty; }
bool CalisthenicsExercise::getRequiresEquipment() const { return requiresEquipment; }
float CalisthenicsExercise::getUserWeight() const { return userWeight; }

void CalisthenicsExercise::setDifficulty(const std::string& difficulty) {
    if (difficulty != "beginner" && difficulty != "intermediate" && difficulty != "advanced")
        throw std::invalid_argument("Difficulty must be: beginner, intermediate or advanced!");
    this->difficulty = difficulty;
}

void CalisthenicsExercise::setRequiresEquipment(bool requiresEquipment) {
    this->requiresEquipment = requiresEquipment;
}

void CalisthenicsExercise::setUserWeight(float userWeight) {
    if (userWeight <= 0)
        throw std::invalid_argument("User weight must be positive!");
    this->userWeight = userWeight;
}

double CalisthenicsExercise::calculateVolume() const {
    return getReps() * (userWeight + getWeight());
}

std::string CalisthenicsExercise::getType() const {
    return "Calisthenics";
}

std::ostream& operator<<(std::ostream& out, const CalisthenicsExercise& obj) {
    out << static_cast<const Exercise&>(obj);
    out << "Difficulty: " << obj.difficulty << '\n';
    out << "Requires Equipment: " << (obj.requiresEquipment ? "Yes" : "No") << '\n';
    out << "User Weight: " << obj.userWeight << " kg\n";
    return out;
}

std::istream& operator>>(std::istream& in, CalisthenicsExercise& obj) {
    in >> static_cast<Exercise&>(obj);
    std::cout << "Difficulty (beginner/intermediate/advanced): ";
    std::getline(in >> std::ws, obj.difficulty);
    std::cout << "Requires equipment? (1/0): ";
    in >> obj.requiresEquipment;
    return in;
}
