#include "L3_Lacatus_Paul_DSM.h"
#include <fstream>

void DSM::printDSM() {
    for (int i = 0; i < elementCount; i++) {
        cout << endl;
        for (int j = 0; j < elementCount; j++)
            cout << matrix[i][j] << " ";
    }
}

int DSM::size() const {
    return this->elementCount;
}

void DSM::resizeUpMatrix() {
    int **newMatrix = new int *[this->elementCount + 1];
    for (int i = 0; i < this->elementCount + 1; i++) {
        newMatrix[i] = new int[this->elementCount + 1];
    }

    for (int i = 0; i < this->elementCount; i++) {
        for (int j = 0; j < this->elementCount; j++) {
            newMatrix[i][j] = this->matrix[i][j];
        }
    }

    for (int i = 0; i < this->elementCount + 1; i++) {
        newMatrix[i][this->elementCount] = 0;
    }

    for (int i = 0; i < this->elementCount; i++) {
        delete[] this->matrix[i];
    }
    delete[] this->matrix;

    this->matrix = newMatrix;
    this->elementCount++;

    resizeUpNames();
}

void DSM::resizeUpNames() {
    auto *newNames = new string[elementCount];
    for (int i = 0; i < this->elementCount - 1; i++) {
        newNames[i] = this->elementNamen[i];
    }
    newNames[elementCount - 1] = "";
    delete[] this->elementNamen;

    this->elementNamen = newNames;
}


string DSM::getName(int index) const {
    if (index < 0 || index > elementCount)
        throw exception();
    return elementNamen[index];
}

void DSM::setElementName(int index, const string &elementName) {
    if (index > elementCount || index < 0)
        throw exception();
    elementNamen[index] = elementName;
}

int DSM::getIndex(const string &name) {
    for (int i = 0; i < elementCount; i++)
        if (elementNamen[i] == name)
            return i;
    return -1;
}

void DSM::addLink(const string &fromElement, const string &toElement, int weight) {
    int fromIndex = getIndex(fromElement);
    if (fromIndex == -1) {
        resizeUpMatrix();
        fromIndex = elementCount - 1;
        elementNamen[fromIndex] = fromElement;
    }

    int toIndex = getIndex(toElement);
    if (toIndex == -1) {
        resizeUpMatrix();
        toIndex = elementCount - 1;
        elementNamen[toIndex] = toElement;
    }
    matrix[fromIndex][toIndex] = weight;
}

void DSM::deleteLink(const string &fromElement, const string &toElement) {
    if (getIndex(fromElement) == -1 || getIndex(toElement) == -1)
        throw exception();
    matrix[getIndex(fromElement)][getIndex(toElement)] = 0;
}

bool DSM::hasLink(const string &fromElement, const string &toElement) {
    if (getIndex(fromElement) == -1 || getIndex(toElement) == -1)
        throw exception();

    if (matrix[getIndex(fromElement)][getIndex(toElement)] != 0)
        return true;
    return false;
}

int DSM::linkWeight(const string &fromElement, const string &toElement) {
    if (getIndex(fromElement) == -1 || getIndex(toElement) == -1)
        throw exception();
    return matrix[getIndex(fromElement)][getIndex(toElement)];
}

int DSM::countToLinks(const string &elementName) {
    if (getIndex(elementName) == -1)
        throw exception();
    int contor = 0;
    for (int i = 0; i < elementCount; i++)
        if (matrix[getIndex(elementName)][i] != 0)
            contor++;
    return contor;
}

int DSM::countFromLinks(const string &elementName) {
    if (getIndex(elementName) == -1)
        throw exception();
    int contor = 0;
    for (int i = 0; i < elementCount; i++)
        if (matrix[i][getIndex(elementName)] != 0)
            contor++;
    return contor;
}

int DSM::countAllLinks() const {
    int contor = 0;
    for (int i = 0; i < elementCount; i++) {
        for (int j = 0; j < elementCount; j++) {
            if (matrix[i][j] != 0)
                contor++;
        }
    }
    return contor;
}

void DSM::readFromFile(const string &dateiName) {
    ifstream file(dateiName);
    string fromElem, toElem;
    int relation;

    if (this->elementCount != 0)
        throw exception();

    if (file.is_open()) {
        while (file >> fromElem >> relation >> toElem) {
            this->addLink(fromElem, toElem, relation);
        }
        file.close();
    } else {
        throw exception();
    }
}

void DSM::writeToFile(const string &dateiName) {
    ofstream file(dateiName);
    for (int i = 0; i < elementCount; i++) {
        if (i != 0)
            file << endl;
        for (int j = 0; j < elementCount; j++)
            file << getName(i) << " " << matrix[i][j] << " " << getName(j) << endl;

    }
    file.close();
}

DSM::~DSM() {
    delete[] this->elementNamen;
    for (int i = 0; i < this->elementCount; i++) {
        delete[] this->matrix[i];
    }
    delete[] this->matrix;
}
