#ifndef WEIGHTEXERCISE_H
#define WEIGHTEXERCISE_H
#include "Exercise.h"

class WeightExercise : public Exercise {
    std::string equipmentType;

public:
    WeightExercise();
    WeightExercise(std::string name, std::string muscleGroup, int reps, float weight,std::string equipmentType);
    WeightExercise(const WeightExercise& obj);
    WeightExercise& operator=(const WeightExercise& obj);
    ~WeightExercise();

    std::string getEquipmentType() const;
    void setEquipmentType(const std::string& equipmentType);

    double calculateVolume() const override;
    std::string getType() const override;

    friend std::ostream& operator<<(std::ostream& out, const WeightExercise& obj);
    friend std::istream& operator>>(std::istream& in, WeightExercise& obj);
};

#endif