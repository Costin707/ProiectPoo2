#ifndef WORKOUT_H
#define WORKOUT_H
#include <iostream>
#include <string>
#include <vector>
#include "Exercise.h"

class Workout {
    const int id;
    static int noWorkouts;
    std::string name;
    std::vector<Exercise*> exercises;

public:
    Workout();
    Workout(std::string name);
    Workout(const Workout& obj);
    Workout& operator=(const Workout& obj);
    ~Workout();

    int getId() const;
    std::string getName() const;
    void setName(const std::string& name);
    std::vector<Exercise*>& getExercises();

    void addExercise(Exercise* exercise);
    void removeExercise(int id);
    void editExercise(int id);
    double calculateTotalVolume() const;

    friend std::ostream& operator<<(std::ostream& out, const Workout& obj);
    friend std::istream& operator>>(std::istream& in, Workout& obj);
};

#endif