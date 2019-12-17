//
// Created by roee on 17/12/2019.
//

#include "Expression.h"

#ifndef UPDATEDSIM_INTERPRETER_H
#define UPDATEDSIM_INTERPRETER_H
#include <map>
#include <string>
#include <list>

class Interpreter {


public:
private:
    map<string, double> mapVariables;


public:
    Expression *interpret(string str);

    void setVariables(string str);

    bool isNumber(char ch);

    bool isOperator(char ch);

    bool isNotValid(list <string> strings);

    queue<string> shuntingYard(list <string> str);

    bool isOperator(string str);

    bool checkIfOperator(char ch);

    int precedence(string str);

    list <string> splitTheString(string str);

    string changeVar(string str);
};
class BinaryOperator : public Expression {
protected:
    Expression *left;
    Expression *right;
public:
    BinaryOperator(Expression *left, Expression *right);

    ~BinaryOperator();


};

class Minus : public BinaryOperator {
public:
    Minus(Expression *left, Expression *right);

    virtual double calculate();
};

class Mul : public BinaryOperator {
public:
    Mul(Expression *left, Expression *right);

    virtual double calculate();
};

class Div : public BinaryOperator {
public:
    Div(Expression *left, Expression *right);

    virtual double calculate();
};

class Plus : public BinaryOperator {
public:
    Plus(Expression *left, Expression *right);

    virtual double calculate();

};


class UnaryOperator : public Expression {
protected:
    Expression *exp;
public:
    UnaryOperator(Expression *exp);

    ~UnaryOperator();
};


class UPlus : public UnaryOperator {

public:
    UPlus(Expression *exp);


    virtual double calculate();
};

class UMinus : public UnaryOperator {

public:
    explicit UMinus(Expression *exp);

    double calculate() override;
};


class Value : public Expression {
private:
    double value;
public:
    Value(const double num);

    //virtual?
    virtual double calculate();
};

class Variable : public Expression {
private:
    string name;
    double value;
public:
    Variable(string name, double value);

    double calculate();

    Variable &operator++();

    Variable &operator++(int);

    Variable &operator--();

    Variable &operator--(int);

    Variable &operator+=(double num);

    Variable &operator-=(double num);
    // ~Variable();

};

#endif //UPDATEDSIM_INTERPRETER_H
