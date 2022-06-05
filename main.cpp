//Part I: Implementing the greedy search algorithms only (No need to implement the classifier or the leave-one-out validator). As input, you only need total number of features (not the data file)
#include "Node.h"
#include "GreedySearch.h"
#include "Classifier.h"
#include "Validator.h"
#include "StringToNum.h"
#include "DataNormalizer.h"
#include <iostream>

using namespace std;

int main(){
    vector<vector<double>> train_instances;
    vector<double> train_labels;
    string file_in;
    int user_input;
    Validator* validator = new Validator(train_instances, train_labels);
    greedy_search* search_selector = new greedy_search(validator);
    vector<Features*> features_list;

    cout << "Welcome to Jordan Sam's Feature Selection Algorithm." << endl;

    cout << "Type in the name of the file to test: " << endl;
    cin >> file_in;

    cout << "Type the number of the algorithm you want to run:" << endl
    << "1) Forward Selection" << endl << "2) Backward Elimination" << endl;

    cin >> user_input;

    // if (user_input == 1) {
    //     file_in = "small-test-dataset.txt";
    // }
    // else if (user_input == 2) {
    //     file_in = "Large-test-dataset.txt";
    // }
    // else {
    //     cout << "Please try again." << endl;
    //     return 0;
    // }

    cout << "Please wait while I normal the data..." << endl;
    data_normalization(file_in, train_instances, train_labels);
    cout <<"Done normalizing data!" << endl;

    for(int i = 0; i < train_instances.at(0).size(); i++) {
        Features* temp = new Features(i + 1);
        features_list.push_back(temp);
    }

    if (user_input == 1) {
        search_selector -> forward_selection(features_list);
    }

    else if (user_input == 2) {
        search_selector -> backwards_elimination(features_list);       //Accuracy of 1,15,27
    }

    else {
        cout << "No algorithm selected. Please try again." << endl;
        return -1;
    }

    return 0;
}