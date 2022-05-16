//Part I: Implementing the greedy search algorithms only (No need to implement the classifier or the leave-one-out validator). As input, you only need total number of features (not the data file)
#include "Node.h"
#include "GreedySearch.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

int num_features;
int user_input;
vector<Features*> features_list;

cout << "Welcome to Jordan Sam's Feature Selection Algorithm." << endl;
cout << "Please enter total number of features: ";
cin >> num_features;

    while(num_features > 0){
        Features* temp = new Features(num_features);
        features_list.push_back(temp);
        num_features--;
    }

cout << "Type the number of the algorithm you want to run." << endl << "1) Forward Selection" << endl << "2) Backward Elimination" << endl;
cin >> user_input;

cout << "Using no features and 'random' evaluation, I get an accuracy of xx.x%" << endl;

if(user_input == 1){
    greedy_search->forward_selection(features_list);
}

else if(user_input == 2){
    greedy_search -> backward_elimination(features_list);
}

else {
    cout << "No algorithm selected. Please try again." << endl;
    return -1;
}

    return 0;
}