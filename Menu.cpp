#include "Menu.h"

Menu::Menu() {
    activeUserIndex = -1;
    activeWorkoutIndex = -1;
}

Menu::~Menu() {}

void Menu::run() {
    try {
        loadData();
    } catch(std::exception& e) {
        std::cout << "Error loading data: " << e.what() << '\n';
    }

    mainMenu();

    try {
        saveData();
    } catch(std::exception& e) {
        std::cout << "Error saving data: " << e.what() << '\n';
    }
}

void Menu::mainMenu() {
    int option;
    do {
        std::cout << "\n=== GYM TRACKER ===\n";
        std::cout << "1. Select user\n";
        std::cout << "2. Create new user\n";
        std::cout << "0. Exit\n";
        std::cout << "Option: ";
        std::cin >> option;

        try {
            switch(option) {
                case 1: selectUser(); break;
                case 2: createUser(); break;
                case 0: std::cout << "Goodbye!\n"; break;
                default: std::cout << "Invalid option!\n";
            }
        } catch(std::exception& e) {
            std::cout << "Error: " << e.what() << '\n';
        }
    } while(option != 0);
}

void Menu::selectUser() {
    if (users.empty()) {
        std::cout << "No users found!\n";
        return;
    }
    std::cout << "\n=== SELECT USER ===\n";
    for (int i = 0; i < (int)users.size(); i++) {
        std::cout << i + 1 << ". " << users[i].getName() << '\n';
    }
    std::cout << "Option: ";
    int option;
    std::cin >> option;
    if (option < 1 || option > (int)users.size())
        throw std::invalid_argument("Invalid option!");
    activeUserIndex = option - 1;
    userMenu();
}

void Menu::createUser() {
    User user;
    std::cin >> user;
    for (int i = 0; i < (int)users.size(); i++) {
        if (users[i].getName() == user.getName())
            throw std::runtime_error("User with this name already exists!");
    }
    users.push_back(user);
    std::cout << "User created successfully!\n";
}

void Menu::userMenu() {
    int option;
    do {
        std::cout << "\n=== Welcome, " << users[activeUserIndex].getName() << " ===\n";
        std::cout << "1. View my workouts\n";
        std::cout << "2. Create new workout\n";
        std::cout << "3. Delete workout\n";
        std::cout << "4. View profile\n";
        std::cout << "0. Back\n";
        std::cout << "Option: ";
        std::cin >> option;

        try {
            switch(option) {
                case 1: selectWorkout(); break;
                case 2: createWorkout(); break;
                case 3: deleteWorkout(); break;
                case 4: std::cout << users[activeUserIndex]; break;
                case 0: break;
                default: std::cout << "Invalid option!\n";
            }
        } catch(std::exception& e) {
            std::cout << "Error: " << e.what() << '\n';
        }
    } while(option != 0);
}

void Menu::selectWorkout() {
    if (users[activeUserIndex].getWorkouts().empty()) {
        std::cout << "No workouts found!\n";
        return;
    }
    std::cout << "\n=== SELECT WORKOUT ===\n";
    for (int i = 0; i < (int)users[activeUserIndex].getWorkouts().size(); i++) {
        std::cout << i + 1 << ". " << users[activeUserIndex].getWorkouts()[i].getName() << '\n';
    }
    std::cout << "Option: ";
    int option;
    std::cin >> option;
    if (option < 1 || option > (int)users[activeUserIndex].getWorkouts().size())
        throw std::invalid_argument("Invalid option!");
    activeWorkoutIndex = option - 1;
    workoutMenu();
}

void Menu::createWorkout() {
    Workout workout;
    std::cin >> workout;
    for (int i = 0; i < (int)users[activeUserIndex].getWorkouts().size(); i++) {
        if (users[activeUserIndex].getWorkouts()[i].getName() == workout.getName())
            throw std::runtime_error("Workout with this name already exists!");
    }
    users[activeUserIndex].addWorkout(workout);
    std::cout << "Workout created successfully!\n";
}

void Menu::deleteWorkout() {
    if (users[activeUserIndex].getWorkouts().empty()) {
        std::cout << "No workouts found!\n";
        return;
    }
    std::cout << "\n=== DELETE WORKOUT ===\n";
    for (int i = 0; i < (int)users[activeUserIndex].getWorkouts().size(); i++) {
        std::cout << i + 1 << ". " << users[activeUserIndex].getWorkouts()[i].getName() << '\n';
    }
    std::cout << "Option: ";
    int option;
    std::cin >> option;
    if (option < 1 || option > (int)users[activeUserIndex].getWorkouts().size())
        throw std::invalid_argument("Invalid option!");
    users[activeUserIndex].removeWorkout(users[activeUserIndex].getWorkouts()[option - 1].getId());
    std::cout << "Workout deleted successfully!\n";
}

void Menu::workoutMenu() {
    int option;
    do {
        std::cout << "\n=== " << users[activeUserIndex].getWorkouts()[activeWorkoutIndex].getName() << " ===\n";
        std::cout << "1. View exercises\n";
        std::cout << "2. Add exercise\n";
        std::cout << "3. Remove exercise\n";
        std::cout << "0. Back\n";
        std::cout << "Option: ";
        std::cin >> option;

        try {
            switch(option) {
                case 1: viewExercises(); break;
                case 2: addExercise(); break;
                case 3: removeExercise(); break;
                case 0: break;
                default: std::cout << "Invalid option!\n";
            }
        } catch(std::exception& e) {
            std::cout << "Error: " << e.what() << '\n';
        }
    } while(option != 0);
}

void Menu::viewExercises() {
    std::vector<Exercise*>& exercises = users[activeUserIndex].getWorkouts()[activeWorkoutIndex].getExercises();
    if (exercises.empty()) {
        std::cout << "No exercises found!\n";
        return;
    }
    std::cout << "\n=== EXERCISES ===\n";
    for (Exercise* ex : exercises) {
        std::cout << *ex << '\n';
    }
    std::cout << "Total volume: " << users[activeUserIndex].getWorkouts()[activeWorkoutIndex].calculateTotalVolume() << '\n';
}

void Menu::addExercise() {
    std::cout << "\n=== ADD EXERCISE ===\n";
    std::cout << "1. Calisthenics\n";
    std::cout << "2. Weight\n";
    std::cout << "Option: ";
    int option;
    std::cin >> option;

    Exercise* ex = nullptr;
    try {
        if (option == 1) {
            ex = new CalisthenicsExercise();
            std::cin >> *ex;
            static_cast<CalisthenicsExercise*>(ex)->setUserWeight(users[activeUserIndex].getWeight());
        } else if (option == 2) {
            ex = new WeightExercise();
            std::cin >> *ex;
        } else {
            throw std::invalid_argument("Invalid option!");
        }

        std::vector<Exercise*>& exercises = users[activeUserIndex].getWorkouts()[activeWorkoutIndex].getExercises();
        for (Exercise* e : exercises) {
            if (e->getName() == ex->getName()) {
                delete ex;
                throw std::runtime_error("Exercise with this name already exists!");
            }
        }

        users[activeUserIndex].getWorkouts()[activeWorkoutIndex].addExercise(ex);
        std::cout << "Exercise added successfully!\n";
    } catch(std::exception& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
}

void Menu::removeExercise() {
    std::vector<Exercise*>& exercises = users[activeUserIndex].getWorkouts()[activeWorkoutIndex].getExercises();
    if (exercises.empty()) {
        std::cout << "No exercises found!\n";
        return;
    }
    std::cout << "\n=== REMOVE EXERCISE ===\n";
    for (Exercise* ex : exercises) {
        std::cout << ex->getId() << ". " << ex->getName() << '\n';
    }
    std::cout << "Exercise id: ";
    int id;
    std::cin >> id;
    users[activeUserIndex].getWorkouts()[activeWorkoutIndex].removeExercise(id);
    std::cout << "Exercise removed successfully!\n";
}

void Menu::saveData() {
    std::ofstream file("users.txt");
    if (!file.is_open())
        throw std::runtime_error("Could not open file for saving!");

    file << users.size() << '\n';
    for (User& user : users) {
        file << user.getName() << '\n';
        file << user.getHeight() << '\n';
        file << user.getWeight() << '\n';
        file << user.getGender() << '\n';
        file << user.getWorkouts().size() << '\n';
        for (Workout& workout : user.getWorkouts()) {
            file << workout.getName() << '\n';
            file << workout.getExercises().size() << '\n';
            for (Exercise* ex : workout.getExercises()) {
                file << ex->getType() << '\n';
                file << ex->getName() << '\n';
                file << ex->getMuscleGroup() << '\n';
                file << ex->getReps() << '\n';
                file << ex->getWeight() << '\n';
                if (ex->getType() == "Calisthenics") {
                    CalisthenicsExercise* c = static_cast<CalisthenicsExercise*>(ex);
                    file << c->getDifficulty() << '\n';
                    file << c->getRequiresEquipment() << '\n';
                    file << c->getUserWeight() << '\n';
                } else if (ex->getType() == "Weights") {
                    WeightExercise* w = static_cast<WeightExercise*>(ex);
                    file << w->getEquipmentType() << '\n';
                }
            }
        }
    }
    file.close();
}

void Menu::loadData() {
    std::cout << "Loading data...\n";
    std::ifstream file("users.txt");
    if (!file.is_open()) {
        std::cout << "File not found!\n";
        return;
    }
        int noUsers;
    file >> noUsers;
    file.ignore();

    for (int i = 0; i < noUsers; i++) {
        std::string name;
        float height, weight;
        char gender;

        std::getline(file, name);
        file >> height >> weight >> gender;
        file.ignore();

        User user(name, height, weight, gender);

        int noWorkouts;
        file >> noWorkouts;
        file.ignore();
        std::cout << "Number of workouts: " << noWorkouts << '\n';

        for (int j = 0; j < noWorkouts; j++) {
            std::string workoutName;
            std::getline(file >> std::ws, workoutName);
            std::cout << "Found workout: " << workoutName << '\n';
            Workout workout(workoutName);

            int noExercises;
            file >> noExercises;
            std::cout << "Exercises: " << noExercises << '\n';
            file.ignore();

            for (int k = 0; k < noExercises; k++) {
                std::string type, exName, muscleGroup;
                int reps;
                float exWeight;

                std::getline(file >> std::ws, type);
                std::getline(file >> std::ws, exName);
                std::getline(file >> std::ws, muscleGroup);
                file >> reps >> exWeight;
                file.ignore();

                if (type == "Calisthenics") {
                    std::string difficulty;
                    bool requiresEquipment;
                    float userWeight;
                    std::getline(file >> std::ws, difficulty);
                    file >> requiresEquipment >> userWeight;
                    file.ignore();
                    workout.addExercise(new CalisthenicsExercise(exName, muscleGroup, reps, exWeight,
                                                                  difficulty, requiresEquipment, userWeight));
                } else if (type == "Weights") {
                    std::string equipmentType;
                    std::getline(file >> std::ws, equipmentType);
                    workout.addExercise(new WeightExercise(exName, muscleGroup, reps, exWeight, equipmentType));
                }
            }
            user.addWorkout(workout);
            std::cout << "Added workout: " << workout.getName() << '\n';
        }
        std::cout << "User workouts: " << user.getWorkouts().size() << '\n';
        users.push_back(user);
    }
    file.close();
}