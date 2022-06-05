#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include <vector>
#include <string>
#include <fstream>
#include "Node.h"
#include <sstream>
#include <cmath>

using namespace std;

class Classifier {
    public:
        vector<vector<double>> train_instances;
        vector<double> train_labels;
        int class_id = 0;

    public: 
        Classifier() {}
            //1,2 2,3
            //distance = sqrt((x2-x1)^2+(y2-y1)^2) in this case, I removed SQRT so that
            //it does not have to calculate it (In effort to speed up the process since proportions stay the same).
            double euclidean_distance(vector<double> lhs, vector<double> rhs){       //Euclidean distance function to compute the distance between two points in n-dimensional space
            double sum = 0;                                                          //between two points in an n-dimensional space (n = #features)
            for (int i = 0; i < lhs.size(); i++){                                    //Take the nromalized distance from the trained and test instance at i
                sum += pow((lhs.at(i) - rhs.at(i)), 2);                              //square it and add it to the sum. The val you return is the square root of the sum
            }
            return sqrt(sum);
            // return sum;
        }

        //The input to the Train method is the set of training instances (or their IDs), no output for this method. 
        //Note that the class label for each instance is provided along wh the feature vector.

        void train(vector<vector<double>> train_instances, vector<double> train_labels) {
            this->train_instances = train_instances;
            this->train_labels = train_labels;
            // for(int i = 0; i < train_labels.size(); i++){
            //     cout << train_labels.at(i) << endl;
            // }
            // exit(0);
        }

        //The input to the Test method is a test instance (or its ID) and the output is the predicted class label.
        //Code for nearest neighbor classifier
        double test(vector<double> test_instance) {
            double predicted_label = INT_MAX;
            double nearest_neighbor = INT_MAX;                      //Start off with the largest #
        
            // int count = 0;
            for (int i = 0; i < train_instances.size(); i++) {
                double distance = euclidean_distance(train_instances.at(i), test_instance);
                // count++;
                // cout << "Count: " << count << " Distance: " << distance << endl;
                if (nearest_neighbor > distance) {                  //If the # is greater than the euclidean distance, set the nearest_neighbor to the closer distance
                    nearest_neighbor = distance;
                    predicted_label = train_labels.at(i);           //The predicted label at i is either 1 or 2
                }
            }
            // exit(0);
            cout << "Class ID " << class_id << " The Nearest Neighbor found is " << nearest_neighbor << " away from " << predicted_label << endl << endl;
            class_id++;
            return predicted_label;            //Output the predicted class label
        }
};

#endif