#ifndef EXERCISE_H
#define EXERCISE_H
#include <iostream>
#include <string>
#include <stdexcept>

class Exercise {
    const int id;
    static int noExercises;
    std::string name;
    std::string muscleGroup;
    int reps;
    float weight;

public:
    Exercise();
    Exercise(std::string name, std::string muscleGroup, int reps, float weight);
    Exercise(const Exercise& obj);
    Exercise& operator=(const Exercise& obj);
    virtual ~Exercise();

    int getId() const;
    std::string getName() const;
    std::string getMuscleGroup() const;
    int getReps() const;
    float getWeight() const;

    void setName(const std::string& name);
    void setMuscleGroup(const std::string& muscleGroup);
    void setReps(int reps);
    void setWeight(float weight);

    virtual double calculateVolume() const = 0;
    virtual std::string getType() const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Exercise& obj);
    friend std::istream& operator>>(std::istream& in, Exercise& obj);
};

#endif