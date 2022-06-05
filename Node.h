#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>

#include "Validator.h"

using namespace std;

class Features {
    public:
        int data;
        Features(int data) {
        this -> data = data;
        }
};

class Node {
    public:
        vector<Node*> child_nodes;
        vector<Features*> user_features;
        double feature_accuracy;
        Validator* validator;                                   //UPDATED IN PART 3 (added validator pointer to access class)
    
    public:
    //UPDATED IN PART 3
    Node(Validator* validator) {
            this->validator = validator;
        }

    //UPDATED IN PART 3
    void feature_evaluator(){                                 //utilizing validator for accuracy (Not randomizer)
        vector<int> accuracy_subset;
        double feature_accuracy = 0;
            for (int i = 0; i < user_features.size(); i++) {
                int data = user_features.at(i)->data;
                accuracy_subset.push_back(data);
            }
            feature_accuracy = this -> validator -> leave_one_out_validation(accuracy_subset);
            this->feature_accuracy = feature_accuracy * 100.0;
    }

    // Node() {                                                    //Provide the accuracy of the starting node if there are no features
    //     feature_accuracy = feature_evaluator();
    // }

    void pushback_feature(Features* new_feature){               //Push back new feature onto the list of user features
        this->user_features.push_back(new_feature);
    }

    void pushback_child(Node* new_child){                       //Push back new child node onto the list of child nodes
        this->child_nodes.push_back(new_child);
    }

    Node(vector<Features*> user_features, Validator* validator){        //UPDATED IN PART 3
            for (int i = 0; i < user_features.size(); i++){
                this->user_features.push_back(user_features.at(i));
            }
            // feature_accuracy = evaluator();
            this->validator = validator;
        }

    void print_features(){                                      //helper function to print out current features
        int num_features;
        cout << "{ ";
        for (int i = 0; i < user_features.size(); i++){         //Get # of features in vector
            cout << user_features.at(i)->data << " ";
        }
        cout << "}";
    }
};

#endif