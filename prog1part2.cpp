#include <Eigen/Dense>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <regex>
using namespace Eigen;
using namespace std;

// Files used
#include "Classifier.cpp"
#include "box-muller.cpp"

// Function used to write to results folder
void samplesFile(const char* fileName, vector<Vector2f> data)
{
    // Open file
    ofstream output;
    output.open(fileName);

    output << "x,y\n";

    // Output and separate the vectors by spaces
    for(unsigned int i = 0; i < data.size(); i++)
    {
        output << data[i](0) << ",";
        output << data[i](1) << "\n";
    }

    // Close file
    output.close();
}

int main()
{
    // Begin
    Classifier classifier;
    int size1 = 60000;
    int size2 = 140000;

    // Vectors used
    vector<Vector2f> one;
    vector<Vector2f> two;
    vector<Vector2f> misclassified1;
    vector<Vector2f> misclassified2;

    // Sigma/Mu
    Matrix2f sigmaOne;
    Vector2f muOne;
    Matrix2f sigmaTwo;
    Vector2f muTwo;

    //Part 2, set up parameters
    muOne << 1, 1;
    sigmaOne << 1, 0, 0, 1;
    muTwo << 4, 4;
    sigmaTwo << 4, 0, 0, 8;

    // Variables
    float priorOne = 0.5;
    float priorTwo = 0.5;
    float misclassOne = 0;
    float misclassTwo = 0;

    one = classifier.generateSamples(muOne, sigmaOne, size1);
    two = classifier.generateSamples(muTwo, sigmaTwo, size2);


    //Create Dataset File
    samplesFile("SetOneB.csv", one);
    samplesFile("SetTwoB.csv", two);

    // question 2
    for(int i = 0; i < size1; i++)
    {
        if(classifier.caseThree(one[i], muOne, muTwo, sigmaOne, sigmaTwo, priorOne, priorTwo) == 2)
        {
            misclassOne++;
            misclassified1.push_back(one[i]);
        }
    }
    for(int i = 0; i < size2; i++)
    {
        if(classifier.caseThree(two[i], muOne, muTwo, sigmaOne, sigmaTwo, priorOne, priorTwo) == 1)
        {
            misclassTwo++;
            misclassified2.push_back(two[i]);
        }
    }

    // Write to file
    samplesFile("2A-Misclassified1.csv", misclassified1);
    samplesFile("2A-Misclassified2.csv", misclassified2);

    // Answer questions
    cout << "Question 2:" << endl;
    cout << "(a) Design a Bayes classifier for minimum error - DONE" << endl;
    cout << "(c) Classify all 200,000 samples and report (i) the misclassification rate for each class separately..... "  << endl;
    cout << "\tSamples from the first 2D Gaussian misclassified: " << misclassOne << endl;
    cout << "\tmisclassified %:" << (misclassOne/ size1 * 100) << endl;
    cout << "\tSamples from second 2D Gaussian misclassified: " << misclassTwo << endl;
    cout << "\tmisclassified %:" << (misclassTwo/ size2 * 100) << endl;
    cout << "\tTotal misclassified: " << misclassOne + misclassTwo << endl;
    cout << "\tmisclassified %:" << ((misclassOne + misclassTwo)/ (size1 + size2) * 100) << endl;
    cout << "(d) Calculate the theoretical probability error" << endl;
    cout << "\tBhattacharyya error %:" << classifier.bhattacharyyaBound(muOne, muTwo, sigmaOne, sigmaTwo) << endl;

    return(0);
}