cmake_minimum_required(VERSION 4.1)
project(poo2)

set(CMAKE_CXX_STANDARD 20)

add_executable(poo2 main.cpp
        User.h
        User.cpp
        Exercise.h
        Exercise.cpp
        CalisthenicsExercise.h
        CalisthenicsExercise.cpp
        WeightExercise.h
        WeightExercise.cpp
        Workout.h
        Workout.cpp)
