//LEAVE-ONE-OUT VALIDATOR
#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <vector>
#include <string>
#include <fstream>
#include "Classifier.h"
#include <sstream>

using namespace std;

class Validator {
    public:
        vector<vector<double>> num_instances;
        vector<double> labels;
        Classifier* classifier_object;                                                  //Pointer to classifier

    public:
        Validator(vector<vector<double>> num_instances, vector<double> labels) {        //Parameters take in a vector of vectors for the to be trained instances and trained labels
            this->classifier_object = new Classifier();                                 //new classifier object to call train and test functions
            this->num_instances = num_instances;                                        //Total # of tests to be done
            this-> labels = labels;
        }
        //(updated in part 3) actually needs double to return
        double leave_one_out_validation(vector<int> feature_subset) {                   //Parameter is the vector of features (Call this on the features that we want to use and eventually the best features)

            vector<vector<double>> filtered_instances;                                  //Vector of vectors needed for which instances we went through

            for (int i = 0; i < num_instances.size(); i++) {                            //Small data set has 100 instances... Therefore the number of folds/learning is 100 times
                vector<double> temp;
                for (int j = 0; j < feature_subset.size(); j++) {
                    temp.push_back(num_instances.at(i).at(feature_subset.at(j) - 1));
                }
                filtered_instances.push_back(temp);                                     //Pushing value into matrix (vector of a vector)
            }
            int counter = 0;

            for (int i = 0; i < num_instances.size(); i++) {

                vector<vector<double>> instance_holder = filtered_instances;              //Set up temprary place holder to erase that 1 value at i,
                vector<double> k_fold_label = labels;

                instance_holder.erase(instance_holder.begin() + i);                       //Since its a matrix, increment up by 1 to move along, erase it, and test/train that row
                k_fold_label.erase(k_fold_label.begin() + i);
                
                vector<double> test_instance = filtered_instances.at(i);
                double test_label = labels.at(i);
                
                classifier_object -> train(instance_holder, k_fold_label);                   

                double classification = classifier_object -> test(test_instance);         //Set the classification and check the label
                
                if (classification == test_label) {                                                                 //IF we classify correctly, increase the # predicted correctly
                    counter++;
                }
            }

            cout << endl << "Number of correct predictions are: " << counter << endl;
            cout << "The total number of predictions are: " << (num_instances.size()) << endl;               //Take the vector of vectors size to 
            // cout << "Number of data instances: " << (double)(num_instances.size()) << endl;                       //Test to confirm # of rows in data set
            cout << "Accuracy is: " << counter / (double)(num_instances.size()) << endl;                                        //cast necessary to convert int to double since the accuracy is double in main...
            return counter / (double)(num_instances.size());
        }
};
#endif


            // for(int i = 0; i < filtered_instances.size(); i++){
            //     for(int j = 0; j < filtered_instances.at(i).size(); j++){
            //         cout << filtered_instances.at(i).at(j) << endl; 
            // }
            // }
// exit(0);