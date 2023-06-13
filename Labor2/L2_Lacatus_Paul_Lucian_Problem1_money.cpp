//
// Created by Paul on 3/16/2023.
//

#include "L2_Lacatus_Paul_Lucian_Problem1_money.h"
#include <iostream>
#include <cmath>

using namespace std;

Money Money::add(Money other) {
    if (this->currency != other.currency)
        other.konversion(this->currency);
    // throw exception();


    double result;
    result = this->value + other.value;
    result = floor(result * 100.0) / 100.0;
    return Money(result, currency);
}

Money Money::substract(Money other) {
    if (this->currency != other.currency)
        other.konversion(this->currency);
    // throw exception();


    double result;
    result = this->value - other.value;
    if (result < 0)
        throw exception();

    result = floor(result * 100.0) / 100.0;
    return Money(result, currency);
}

Money Money::scale(double multiplier) {
    if (multiplier < 0)
        throw exception();

    double result;
    result = this->value * multiplier;
    result = floor(result * 100.0) / 100.0;
    return Money(result, currency);
}

double Money::divide(double divider) {
    if (divider < 0)
        throw exception();

    double result;
    result = this->value / divider;
    result = floor(result * 100.0) / 100.0;
    return result;
}

string Money::text() {
    string string_value = to_string(this->value);
    int pos = string_value.find(".");
    string_value = string_value.substr(0, pos + 3);
    return string_value + " " + currency;
}

short Money::compare(Money other) {
    if (this->currency != other.currency)
        other.konversion(this->currency);
    // throw exception();

    if (this->value > other.value) {
        return 1;
    } else if (this->value < other.value) {
        return -1;
    } else {
        return 0;
    }
}

void Money::konversion(string cur) {
    if (this->currency == "ron") {
        if (cur == "euro") {
            this->value = this->value / 4.92;
            this->value = floor(this->value * 100.0) / 100.0;
        }
        if (cur == "huf") {
            this->value = this->value / 0.01;
            this->value = floor(this->value * 100.0) / 100.0;
        }
    }
    if (this->currency == "euro") {
        if (cur == "ron") {
            this->value = this->value * 4.92;
            this->value = floor(this->value * 100.0) / 100.0;
        }
        if (cur == "huf") {
            this->value = this->value * 384.54;
            this->value = floor(this->value * 100.0) / 100.0;
        }
    }
    if (this->currency == "huf") {
        if (cur == "ron") {
            this->value = this->value * 0.01;
            this->value = floor(this->value * 100.0) / 100.0;
        }
        if (cur == "euro") {
            this->value = this->value / 384.54;
            this->value = floor(this->value * 100.0) / 100.0;
        }
    }
    this->currency = cur;
}