#include <vector>
#include <iostream>

using namespace std;

#ifndef NODE_H
#define NODE_H

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
    
    double feature_evaluator(){                                 //Part 1: Need to utilize dummy evaluator that produces a random value as of now
        double random_val = 1.0 + (rand() % 100); 
        return random_val;
    }

    Node() {                                                    //Provide the accuracy of the starting node if there are no features
        feature_accuracy = feature_evaluator();
    }

    void pushback_feature(Features* new_feature){               //Push back new feature onto the list of user features
        this->user_features.push_back(new_feature);
    }

    void pushback_child(Node* new_child){                       //Push back new child node onto the list of child nodes
        this->child_nodes.push_back(new_child);
    }

    Node(vector<Features*> user_features){                      //Return accuracy of some combination of features
        for (int i = 0; i < user_features.size(); i++){
            this->user_features.push_back(user_features.at(i));
        }
        feature_accuracy = feature_evaluator();
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