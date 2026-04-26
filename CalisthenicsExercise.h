#ifndef CALISTHENICSEXERCISE_H
#define CALISTHENICSEXERCISE_H
#include "Exercise.h"

class CalisthenicsExercise : public Exercise {
    std::string difficulty;
    bool requiresEquipment;
    float userWeight;

public:
    CalisthenicsExercise();
    CalisthenicsExercise(std::string name, std::string muscleGroup, int reps, float weight,std::string difficulty, bool requiresEquipment, float userWeight);
    CalisthenicsExercise(const CalisthenicsExercise& obj);
    CalisthenicsExercise& operator=(const CalisthenicsExercise& obj);
    ~CalisthenicsExercise();

    std::string getDifficulty() const;
    bool getRequiresEquipment() const;
    float getUserWeight() const;

    void setDifficulty(const std::string& difficulty);
    void setRequiresEquipment(bool requiresEquipment);
    void setUserWeight(float userWeight);

    double calculateVolume() const override;
    std::string getType() const override;

    friend std::ostream& operator<<(std::ostream& out, const CalisthenicsExercise& obj);
    friend std::istream& operator>>(std::istream& in, CalisthenicsExercise& obj);
};

#endif