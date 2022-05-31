//Part I: Implementing the greedy search algorithms only (No need to implement the classifier or the leave-one-out validator). As input, you only need total number of features (not the data file)
#include "Node.h"
#include "GreedySearch.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

greedy_search* search_selector = new greedy_search();
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

if(user_input == 1){
    search_selector -> forward_selection(features_list);
}

else if(user_input == 2){
    // search_selector -> backward_elimination(features_list);
    cout << "not ready" << endl;
}

else {
    cout << "No algorithm selected. Please try again." << endl;
    return -1;
}

    return 0;
}