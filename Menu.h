#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <vector>
#include <fstream>
#include <exception>
#include <stdexcept>
#include "User.h"
#include "Workout.h"
#include "CalisthenicsExercise.h"
#include "WeightExercise.h"

class Menu {
    std::vector<User> users;
    int activeUserIndex;
    int activeWorkoutIndex;

public:
    Menu();
    ~Menu();

    void run();

private:
    void mainMenu();
    void userMenu();
    void workoutMenu();

    void selectUser();
    void createUser();

    void selectWorkout();
    void createWorkout();
    void deleteWorkout();

    void viewExercises();
    void addExercise();
    void removeExercise();

    void saveData();
    void loadData();
};

#endif