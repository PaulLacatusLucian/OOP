//
// Created by Paul on 3/30/2023.
//

#ifndef LAB3_OOP_L3_LACATUS_PAUL_DSM_H
#define LAB3_OOP_L3_LACATUS_PAUL_DSM_H

#include <iostream>

using namespace std;


class DSM {
private:
    int elementCount;
    string *elementNamen;
    int **matrix;

public:
    DSM(int elemCount) {
        if(elemCount < 0)
            throw exception();
        this->elementCount = elemCount;
        matrix = new int *[elementCount];
        for (int i = 0; i < elementCount; i++) {
            matrix[i] = new int[elementCount];
            for (int j = 0; j < elementCount; j++)
                matrix[i][j] = 0;
        }
        this->elementNamen = new string[elementCount];
    }

    DSM(string elementNames[], int elementCount) {
        if(elementCount < 0)
            throw exception();
        this->elementNamen = new string[elementCount];
        for (int i = 0; i < elementCount; i++)
            this->elementNamen[i] = elementNames[i];
        this->elementCount = elementCount;

        matrix = new int *[elementCount];
        for (int i = 0; i < elementCount; i++) {
            matrix[i] = new int[elementCount];
            for (int j = 0; j < elementCount; j++)
                matrix[i][j] = 0;
        }
    }

    DSM(const DSM& other) {
        //cleanup
        delete[] this->elementNamen;
        for(int i = 0; i<elementCount; i++)
            delete matrix[i];
        delete[] matrix;

        //copy
        elementCount = other.elementCount;
        elementNamen = new string[elementCount];

        for (int i = 0; i < elementCount; i++) {
            elementNamen[i] = other.elementNamen[i];
        }

        matrix = new int*[elementCount];
        for (int i = 0; i < elementCount; i++) {
            matrix[i] = new int[elementCount];
        }

        for (int i = 0; i < elementCount; i++) {
            for (int j = 0; j < elementCount; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    void printDSM();

    int size() const;

    string getName(int index) const;

    void setElementName(int index, const string &elementName);

    int getIndex(const string& name);

    void addLink(const string& fromElement, const string& toElement, int weight);

    void deleteLink(const string& fromElement, const string& toElement);

    bool hasLink(const string& fromElement, const string& toElement);

    int linkWeight(const string& fromElement, const string& toElement);

    int countToLinks(const string& elementName);

    int countFromLinks(const string& elementName);

    int countAllLinks() const;

    void resizeUpMatrix();

    void resizeUpNames();

    void readFromFile(const string& dateiName);

    void writeToFile(const string& dateiName);

    ~DSM();
};

#endif //LAB3_OOP_L3_LACATUS_PAUL_DSM_H
