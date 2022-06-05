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
    greedy_search* search_selector = new greedy_search();
    vector<Features*> features_list;

    cout << "Welcome to Jordan Sam's Feature Selection Algorithm." << endl;
    cout << "Which file would you like to to test? Enter 1 or 2: " << endl 
    << "1. Small Dataset (10 features)" << endl << "or" << endl
    << "2. Large Dataset (40 features)" << endl;

    cin >> user_input;

    if (user_input == 1) {
        file_in = "small-test-dataset.txt";
    }
    else if (user_input == 2) {
        file_in = "Large-test-dataset.txt";
    }
    else {
        cout << "Please try again." << endl;
        return 0;
    }

    cout << "Normalizing the data:" << endl;
    data_normalization(file_in, train_instances, train_labels);


    Validator* validator = new Validator(train_instances, train_labels);

    if (user_input == 1) {
        vector<int> small_test = {3, 5, 7};
        cout << "Using features subset {3, 5, 7}" << endl;
        validator -> leave_one_out_validation(small_test);        //Accuracy of 3,5,7
    }

    else if (user_input == 2) {
        vector<int> large_test = {1, 15, 27};
        cout << "Using features subset {1, 15, 27}" << endl;
        validator -> leave_one_out_validation(large_test);        //Accuracy of 1,15,27
    }

    return 0;
}