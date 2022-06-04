#ifndef DATANORMALIZER_H
#define DATANORMALIZER_H
#include "StringToNum.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void data_normalization(string file_in, vector<vector<double>>& train_instances, vector<double>& train_labels) {
    ifstream input_file_system;

    input_file_system.open(file_in);

    if (input_file_system.is_open()){                                           //If the file is open, read the row and add it to the training labels/instances, else restart
        stringstream in_string_stream;
        string row;

        while(getline(input_file_system, row)){                                 //Using while loop to grab row of data
            in_string_stream << row;
            string temp;
            in_string_stream >> temp;
            train_labels.push_back(string_to_IEEE(temp));                       //add IEEE to the training labels after converting it from string to double

            vector<double> poop;
            while (in_string_stream >> temp) {
                poop.push_back(string_to_IEEE(temp));
            }
            train_instances.push_back(poop);
            poop.clear();
            in_string_stream.clear();
        }

    vector<double> average(train_instances.at(0).size(), 0.0);
    vector<double> std_dev(train_instances.at(0).size(), 0.0);

    //average (used in calculation for normalization)
    //https://www.tutorialspoint.com/mean-and-median-of-a-matrix-in-cplusplus
    for (int i = 0; i < train_instances.size(); i++){
        for (int j = 0; j < train_instances.at(i).size(); j++) {
            average.at(j) += train_instances.at(i).at(j);
        }
    }
    for (int i = 0; i < average.size(); i++){
        average.at(i) = average.at(i) / train_instances.size();
    }

    //Standard deviation (used in calculation for normalization)
    //https://www.tutorialspoint.com/cplusplus-program-to-calculate-standard-deviation
    for (int i = 0; i < train_instances.size(); i++){
        for (int j = 0; j < train_instances.at(i).size(); j++) {
            std_dev.at(j) += pow((train_instances.at(i).at(j) - average.at(j)), 2);
        }
    }
    for (int i = 0; i < std_dev.size(); i++) {
        std_dev.at(i) = sqrt(std_dev.at(i) / train_instances.size());
    }

    //NORMALIZATION = x = (x - mean(x)) / std(x)
    //https://www.statology.org/z-score-normalization/
    for (int i = 0; i < train_instances.size(); i++){
        for (int j = 0; j < train_instances.at(i).size(); j++) {
            train_instances.at(i).at(j) = (train_instances.at(i).at(j) - average.at(j)) / std_dev.at(j);
        }
    }
    }

     else{
        cout << "Could not open data set " << file_in << endl << "Please try running the program again.";
        return;
    }
}
#endif

//https://stats.stackexchange.com/questions/495357/why-do-we-normalize-test-data-on-the-parameters-of-the-training-data