//
// Created by Paul on 3/16/2023.
//

#ifndef LAB2_OOB_L2_LACATUS_PAUL_LUCIAN_PROBLEM1_MONEY_H
#define LAB2_OOB_L2_LACATUS_PAUL_LUCIAN_PROBLEM1_MONEY_H

#include <iostream>
#include <string>

using namespace std;

class Money {
public:
    Money(double value, string currency) {
        this->value = value;
        this->currency = currency;
    }

private:
    double value;
    string currency;


public:

    void set_value(double amount) { value = amount; }

    void set_currency(string type) { currency = type; }

    double get_value() { return value; }

    string get_currency() { return currency; }

    Money add(Money other);

    Money substract(Money other);

    Money scale(double multiplier);

    double divide(double divider);

    string text();

    short compare(Money amount);

    void konversion(string currency);

    Money operator+(Money other) {
        if (this->currency != other.currency)
            other.konversion(this->currency);
        double result = this->value + other.value;
        return Money(result, currency);
    }

    Money operator-(Money other) {
        if (this->currency != other.currency)
            other.konversion(this->currency);
        double result = this->value - other.value;
        if (result < 0)
            throw exception();
        return Money(result, currency);
    }

    Money operator*(Money other) {
        if (this->currency != other.currency)
            other.konversion(this->currency);
        double result = this->value * other.value;
        return Money(result, currency);
    }

    Money operator/(Money other) {
        if (this->currency != other.currency)
            other.konversion(this->currency);
        double result = this->value / other.value;
        if (result < 0)
            throw exception();
        return Money(result, currency);
    }
};


#endif //LAB2_OOB_L2_LACATUS_PAUL_LUCIAN_PROBLEM1_MONEY_H