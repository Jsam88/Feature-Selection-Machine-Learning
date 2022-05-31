#include "Node.h"
#include <algorithm>
#include <iostream>
using namespace std;

#ifndef GREEDYSEARCH_H
#define GREEDYSEARCH_H

class greedy_search {
    private:
        Node* no_features;

    public:
        greedy_search() {
            this -> no_features = nullptr;                                      //Constructor for initial 0 features
        }

        void forward_selection(vector<Features*> features_list){                //forward selection takes the parameter of the features given/ feature data
            this -> no_features = new Node();                                   //Starting with 0 features, create a new node with rand acc
            Node* current_node = no_features;

            cout << "Using no features and \"random\" evaluation, I get an accuracy of " << no_features->feature_accuracy << '%' << endl << "Beginning search" << endl;

            while(!features_list.empty()) {                                     //While the features are not empty pushback the next feature greedily and check till empty

                for (int i = 0; i < features_list.size(); i++) {
                    Node* temp = new Node(current_node -> user_features);       //Node starting point pointing to data from features
                    temp -> pushback_feature(features_list.at(i));              //provide the temp node with the added features
                    current_node->pushback_child(temp);                         //Push back the feature onto the child node
                }

                //Initialize  values to hold/keep track of
                int best_index = 0;
                double best_accuracy = 0.0;
                for (int i = 0; i < current_node->child_nodes.size(); i++){     //Greedyily searching best accuracy in child nodes
                    double evaluator_acc = current_node->child_nodes.at(i) -> feature_accuracy;     //Grab accuracy of node
                    cout << "Using feature(s)";
                    current_node->child_nodes.at(i)->print_features();                              //helper print function
                    cout << " = " << evaluator_acc << '%' << endl;
                    if (evaluator_acc > best_accuracy) {
                        best_index = i;                                                             //keep track of best index
                    }
                    best_accuracy = max(best_accuracy, evaluator_acc);                              //Keep highest evaluation accuracy (started at 0.0)
                }

                if (current_node->feature_accuracy > best_accuracy){                                //If a higher accuracy is > than best_accuracy, then we have the node that has the best accuracy

                    cout << endl << "(Warning, Accuracy has decreased!)" << endl
                    << "Finished Search, best feature subset is ";
                    current_node -> print_features();
                    cout << ", which has an accuracy of " << current_node -> feature_accuracy << '%' << endl;

                    return;
                }

                cout << endl << "Feature set ";
                current_node->child_nodes.at(best_index)->print_features(); 
                cout << " was best, accuracy is " << current_node->child_nodes.at(best_index)->feature_accuracy << '%' << endl << endl;

                features_list.erase(features_list.begin() + best_index);                            //Delete elements from a list container

                current_node = current_node -> child_nodes.at(best_index);
            }

            cout << "Finished Search!! The best feature subset is ";
            current_node -> print_features();
            cout << ", which has an accuracy of " << current_node -> feature_accuracy << '%' << endl;

            return;
        }

        void backwards_elimination(vector<Features*> features_list){                //forward selection takes the parameter of the features given/ feature data
            this -> no_features = new Node(features_list);                                   //Starting with all features, create a new node with rand acc
            Node* current_node = no_features;

            cout << "Using all features and \"random\" evaluation, I get an accuracy of " << no_features->feature_accuracy << '%' << endl << "Beginning search" << endl;

            while(!current_node->user_features.empty()) {                                     //While the features are not empty pushback the next feature greedily and check till empty

                for (int i = 0; i < features_list.size(); i++) {
                    current_node->pushback_child(remove_feature(current_node, i));       //Pushback new node with a feature removed
                }

                //Initialize  values to hold/keep track of
                int best_index = 0;
                double best_accuracy = 0.0;
                for (int i = 0; i < current_node->child_nodes.size(); i++){     //Greedyily searching best accuracy in child nodes
                    double evaluator_acc = current_node->child_nodes.at(i) -> feature_accuracy;     //Grab accuracy of node
                    cout << "Using feature(s)";
                    current_node->child_nodes.at(i)->print_features();                              //helper print function
                    cout << " = " << evaluator_acc << '%' << endl;
                    if (evaluator_acc > best_accuracy) {
                        best_index = i;                                                             //keep track of best index
                    }
                    best_accuracy = max(best_accuracy, evaluator_acc);                              //Keep highest evaluation accuracy (started at 0.0)
                }

                if (current_node->feature_accuracy > best_accuracy){                                //If a higher accuracy is > than best_accuracy, then we have the node that has the best accuracy

                    cout << endl << "(Warning, Accuracy has decreased!)" << endl
                    << "Finished Search, best feature subset is ";
                    current_node -> print_features();
                    cout << ", which has an accuracy of " << current_node -> feature_accuracy << '%' << endl;

                    return;
                }

                cout << endl << "Feature set ";
                current_node->child_nodes.at(best_index)->print_features(); 
                cout << " was best, accuracy is " << current_node->child_nodes.at(best_index)->feature_accuracy << '%' << endl << endl;

                features_list.erase(features_list.begin() + best_index);                            //Delete elements from a list container

                current_node = current_node -> child_nodes.at(best_index);
            }

            cout << "Finished Search!! The best feature subset is ";
            current_node -> print_features();
            cout << ", which has an accuracy of " << current_node -> feature_accuracy << '%' << endl;

            return;
        }

        Node* remove_feature(Node* node, int index) {
            Node* temp = new Node(node->user_features);
            temp->user_features.erase(temp->user_features.begin() + index);
            return temp;
        }
};

#endif