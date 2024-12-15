#include "Visitor/OperationsDispatcher.h"

#include "Expressions/Literals/Literal.h"
#include "Expressions/Literals/LiteralBool.h"
#include "Expressions/Literals/LiteralDouble.h"
#include "Expressions/Literals/LiteralFloat.h"
#include "Expressions/Literals/LiteralInt.h"
#include "Expressions/Literals/LiteralString.h"

// Function: add
Literal* OperationsDispatcher::add(LiteralInt* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[add] LiteralInt | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::add(LiteralDouble* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[add] LiteralDouble | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::add(LiteralFloat* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[add] LiteralFloat | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::add(LiteralString* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[add] LiteralString | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::add(LiteralBool* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[add] LiteralBool | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::add(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[add] LiteralInt | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::add(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[add] LiteralDouble | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::add(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[add] LiteralFloat | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::add(LiteralString* left, LiteralString* right) {
return new LiteralString(left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralBool* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[add] LiteralBool | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::add(LiteralInt* left, LiteralFloat* right) {
return new LiteralFloat(left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralDouble* left, LiteralFloat* right) {
return new LiteralDouble(left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralFloat* left, LiteralFloat* right) {
return new LiteralFloat(left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralString* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[add] LiteralString | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::add(LiteralBool* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[add] LiteralBool | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::add(LiteralInt* left, LiteralDouble* right) {
return new LiteralDouble(left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralDouble* left, LiteralDouble* right) {
return new LiteralDouble(left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralFloat* left, LiteralDouble* right) {
return new LiteralDouble(left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralString* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[add] LiteralString | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::add(LiteralBool* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[add] LiteralBool | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::add(LiteralInt* left, LiteralInt* right) {
return new LiteralInt(left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralDouble* left, LiteralInt* right) {
return new LiteralDouble(left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralFloat* left, LiteralInt* right) {
return new LiteralFloat(left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralString* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[add] LiteralString | LiteralInt!");
return nullptr;
}

Literal* OperationsDispatcher::add(LiteralBool* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[add] LiteralBool | LiteralInt!");
return nullptr;
}


// Function: subtract
Literal* OperationsDispatcher::subtract(LiteralInt* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralInt | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::subtract(LiteralDouble* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralDouble | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::subtract(LiteralFloat* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralFloat | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::subtract(LiteralString* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralString | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::subtract(LiteralBool* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralBool | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::subtract(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralInt | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::subtract(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralDouble | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::subtract(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralFloat | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::subtract(LiteralString* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralString | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::subtract(LiteralBool* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralBool | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::subtract(LiteralInt* left, LiteralFloat* right) {
return new LiteralFloat(left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralDouble* left, LiteralFloat* right) {
return new LiteralDouble(left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralFloat* left, LiteralFloat* right) {
return new LiteralFloat(left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralString* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralString | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::subtract(LiteralBool* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralBool | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::subtract(LiteralInt* left, LiteralDouble* right) {
return new LiteralDouble(left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralDouble* left, LiteralDouble* right) {
return new LiteralDouble(left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralFloat* left, LiteralDouble* right) {
return new LiteralDouble(left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralString* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralString | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::subtract(LiteralBool* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralBool | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::subtract(LiteralInt* left, LiteralInt* right) {
return new LiteralInt(left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralDouble* left, LiteralInt* right) {
return new LiteralDouble(left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralFloat* left, LiteralInt* right) {
return new LiteralFloat(left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralString* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralString | LiteralInt!");
return nullptr;
}

Literal* OperationsDispatcher::subtract(LiteralBool* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralBool | LiteralInt!");
return nullptr;
}


// Function: multiply
Literal* OperationsDispatcher::multiply(LiteralInt* left, LiteralBool* right) {
return new LiteralInt(left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralDouble* left, LiteralBool* right) {
return new LiteralDouble(left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralFloat* left, LiteralBool* right) {
return new LiteralFloat(left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralString* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[multiply] LiteralString | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::multiply(LiteralBool* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[multiply] LiteralBool | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::multiply(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[multiply] LiteralInt | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::multiply(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[multiply] LiteralDouble | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::multiply(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[multiply] LiteralFloat | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::multiply(LiteralString* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[multiply] LiteralString | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::multiply(LiteralBool* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[multiply] LiteralBool | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::multiply(LiteralInt* left, LiteralFloat* right) {
return new LiteralFloat(left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralDouble* left, LiteralFloat* right) {
return new LiteralDouble(left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralFloat* left, LiteralFloat* right) {
return new LiteralFloat(left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralString* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[multiply] LiteralString | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::multiply(LiteralBool* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[multiply] LiteralBool | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::multiply(LiteralInt* left, LiteralDouble* right) {
return new LiteralDouble(left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralDouble* left, LiteralDouble* right) {
return new LiteralDouble(left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralFloat* left, LiteralDouble* right) {
return new LiteralDouble(left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralString* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[multiply] LiteralString | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::multiply(LiteralBool* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[multiply] LiteralBool | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::multiply(LiteralInt* left, LiteralInt* right) {
return new LiteralInt(left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralDouble* left, LiteralInt* right) {
return new LiteralDouble(left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralFloat* left, LiteralInt* right) {
return new LiteralFloat(left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralString* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[multiply] LiteralString | LiteralInt!");
return nullptr;
}

Literal* OperationsDispatcher::multiply(LiteralBool* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[multiply] LiteralBool | LiteralInt!");
return nullptr;
}


// Function: divide
Literal* OperationsDispatcher::divide(LiteralInt* left, LiteralBool* right) {
return new LiteralInt(left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralDouble* left, LiteralBool* right) {
return new LiteralDouble(left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralFloat* left, LiteralBool* right) {
return new LiteralFloat(left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralString* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[divide] LiteralString | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::divide(LiteralBool* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[divide] LiteralBool | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::divide(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[divide] LiteralInt | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::divide(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[divide] LiteralDouble | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::divide(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[divide] LiteralFloat | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::divide(LiteralString* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[divide] LiteralString | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::divide(LiteralBool* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[divide] LiteralBool | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::divide(LiteralInt* left, LiteralFloat* right) {
return new LiteralFloat(left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralDouble* left, LiteralFloat* right) {
return new LiteralDouble(left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralFloat* left, LiteralFloat* right) {
return new LiteralFloat(left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralString* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[divide] LiteralString | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::divide(LiteralBool* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[divide] LiteralBool | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::divide(LiteralInt* left, LiteralDouble* right) {
return new LiteralDouble(left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralDouble* left, LiteralDouble* right) {
return new LiteralDouble(left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralFloat* left, LiteralDouble* right) {
return new LiteralDouble(left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralString* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[divide] LiteralString | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::divide(LiteralBool* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[divide] LiteralBool | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::divide(LiteralInt* left, LiteralInt* right) {
return new LiteralInt(left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralDouble* left, LiteralInt* right) {
return new LiteralDouble(left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralFloat* left, LiteralInt* right) {
return new LiteralFloat(left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralString* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[divide] LiteralString | LiteralInt!");
return nullptr;
}

Literal* OperationsDispatcher::divide(LiteralBool* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[divide] LiteralBool | LiteralInt!");
return nullptr;
}


// Function: equal
Literal* OperationsDispatcher::equal(LiteralInt* left, LiteralBool* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralDouble* left, LiteralBool* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralFloat* left, LiteralBool* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralString* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[equal] LiteralString | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::equal(LiteralBool* left, LiteralBool* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[equal] LiteralInt | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::equal(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[equal] LiteralDouble | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::equal(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[equal] LiteralFloat | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::equal(LiteralString* left, LiteralString* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralBool* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[equal] LiteralBool | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::equal(LiteralInt* left, LiteralFloat* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralDouble* left, LiteralFloat* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralFloat* left, LiteralFloat* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralString* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[equal] LiteralString | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::equal(LiteralBool* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[equal] LiteralBool | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::equal(LiteralInt* left, LiteralDouble* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralDouble* left, LiteralDouble* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralFloat* left, LiteralDouble* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralString* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[equal] LiteralString | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::equal(LiteralBool* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[equal] LiteralBool | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::equal(LiteralInt* left, LiteralInt* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralDouble* left, LiteralInt* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralFloat* left, LiteralInt* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralString* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[equal] LiteralString | LiteralInt!");
return nullptr;
}

Literal* OperationsDispatcher::equal(LiteralBool* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[equal] LiteralBool | LiteralInt!");
return nullptr;
}


// Function: not_equal
Literal* OperationsDispatcher::not_equal(LiteralInt* left, LiteralBool* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralDouble* left, LiteralBool* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralFloat* left, LiteralBool* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralString* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[not_equal] LiteralString | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::not_equal(LiteralBool* left, LiteralBool* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[not_equal] LiteralInt | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::not_equal(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[not_equal] LiteralDouble | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::not_equal(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[not_equal] LiteralFloat | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::not_equal(LiteralString* left, LiteralString* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralBool* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[not_equal] LiteralBool | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::not_equal(LiteralInt* left, LiteralFloat* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralDouble* left, LiteralFloat* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralFloat* left, LiteralFloat* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralString* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[not_equal] LiteralString | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::not_equal(LiteralBool* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[not_equal] LiteralBool | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::not_equal(LiteralInt* left, LiteralDouble* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralDouble* left, LiteralDouble* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralFloat* left, LiteralDouble* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralString* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[not_equal] LiteralString | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::not_equal(LiteralBool* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[not_equal] LiteralBool | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::not_equal(LiteralInt* left, LiteralInt* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralDouble* left, LiteralInt* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralFloat* left, LiteralInt* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralString* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[not_equal] LiteralString | LiteralInt!");
return nullptr;
}

Literal* OperationsDispatcher::not_equal(LiteralBool* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[not_equal] LiteralBool | LiteralInt!");
return nullptr;
}


// Function: greater_than
Literal* OperationsDispatcher::greater_than(LiteralInt* left, LiteralBool* right) {
return new LiteralBool(left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralDouble* left, LiteralBool* right) {
return new LiteralBool(left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralFloat* left, LiteralBool* right) {
return new LiteralBool(left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralString* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[greater_than] LiteralString | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than(LiteralBool* left, LiteralBool* right) {
return new LiteralBool(left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[greater_than] LiteralInt | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[greater_than] LiteralDouble | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[greater_than] LiteralFloat | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than(LiteralString* left, LiteralString* right) {
return new LiteralBool(left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralBool* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[greater_than] LiteralBool | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than(LiteralInt* left, LiteralFloat* right) {
return new LiteralBool(left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralDouble* left, LiteralFloat* right) {
return new LiteralBool(left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralFloat* left, LiteralFloat* right) {
return new LiteralBool(left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralString* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[greater_than] LiteralString | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than(LiteralBool* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[greater_than] LiteralBool | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than(LiteralInt* left, LiteralDouble* right) {
return new LiteralBool(left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralDouble* left, LiteralDouble* right) {
return new LiteralBool(left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralFloat* left, LiteralDouble* right) {
return new LiteralBool(left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralString* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[greater_than] LiteralString | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than(LiteralBool* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[greater_than] LiteralBool | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than(LiteralInt* left, LiteralInt* right) {
return new LiteralBool(left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralDouble* left, LiteralInt* right) {
return new LiteralBool(left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralFloat* left, LiteralInt* right) {
return new LiteralBool(left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralString* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[greater_than] LiteralString | LiteralInt!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than(LiteralBool* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[greater_than] LiteralBool | LiteralInt!");
return nullptr;
}


// Function: less_than
Literal* OperationsDispatcher::less_than(LiteralInt* left, LiteralBool* right) {
return new LiteralBool(left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralDouble* left, LiteralBool* right) {
return new LiteralBool(left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralFloat* left, LiteralBool* right) {
return new LiteralBool(left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralString* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[less_than] LiteralString | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::less_than(LiteralBool* left, LiteralBool* right) {
return new LiteralBool(left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[less_than] LiteralInt | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::less_than(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[less_than] LiteralDouble | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::less_than(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[less_than] LiteralFloat | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::less_than(LiteralString* left, LiteralString* right) {
return new LiteralBool(left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralBool* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[less_than] LiteralBool | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::less_than(LiteralInt* left, LiteralFloat* right) {
return new LiteralBool(left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralDouble* left, LiteralFloat* right) {
return new LiteralBool(left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralFloat* left, LiteralFloat* right) {
return new LiteralBool(left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralString* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[less_than] LiteralString | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::less_than(LiteralBool* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[less_than] LiteralBool | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::less_than(LiteralInt* left, LiteralDouble* right) {
return new LiteralBool(left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralDouble* left, LiteralDouble* right) {
return new LiteralBool(left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralFloat* left, LiteralDouble* right) {
return new LiteralBool(left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralString* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[less_than] LiteralString | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::less_than(LiteralBool* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[less_than] LiteralBool | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::less_than(LiteralInt* left, LiteralInt* right) {
return new LiteralBool(left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralDouble* left, LiteralInt* right) {
return new LiteralBool(left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralFloat* left, LiteralInt* right) {
return new LiteralBool(left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralString* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[less_than] LiteralString | LiteralInt!");
return nullptr;
}

Literal* OperationsDispatcher::less_than(LiteralBool* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[less_than] LiteralBool | LiteralInt!");
return nullptr;
}


// Function: greater_than_or_equal
Literal* OperationsDispatcher::greater_than_or_equal(LiteralInt* left, LiteralBool* right) {
return new LiteralBool(left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralDouble* left, LiteralBool* right) {
return new LiteralBool(left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralFloat* left, LiteralBool* right) {
return new LiteralBool(left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralString* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralString | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralBool* left, LiteralBool* right) {
return new LiteralBool(left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralInt | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralDouble | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralFloat | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralString* left, LiteralString* right) {
return new LiteralBool(left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralBool* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralBool | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralInt* left, LiteralFloat* right) {
return new LiteralBool(left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralDouble* left, LiteralFloat* right) {
return new LiteralBool(left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralFloat* left, LiteralFloat* right) {
return new LiteralBool(left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralString* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralString | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralBool* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralBool | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralInt* left, LiteralDouble* right) {
return new LiteralBool(left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralDouble* left, LiteralDouble* right) {
return new LiteralBool(left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralFloat* left, LiteralDouble* right) {
return new LiteralBool(left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralString* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralString | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralBool* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralBool | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralInt* left, LiteralInt* right) {
return new LiteralBool(left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralDouble* left, LiteralInt* right) {
return new LiteralBool(left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralFloat* left, LiteralInt* right) {
return new LiteralBool(left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralString* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralString | LiteralInt!");
return nullptr;
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralBool* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralBool | LiteralInt!");
return nullptr;
}


// Function: less_than_or_equal
Literal* OperationsDispatcher::less_than_or_equal(LiteralInt* left, LiteralBool* right) {
return new LiteralBool(left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralDouble* left, LiteralBool* right) {
return new LiteralBool(left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralFloat* left, LiteralBool* right) {
return new LiteralBool(left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralString* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralString | LiteralBool!");
return nullptr;
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralBool* left, LiteralBool* right) {
return new LiteralBool(left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralInt | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralDouble | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralFloat | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralString* left, LiteralString* right) {
return new LiteralBool(left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralBool* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralBool | LiteralString!");
return nullptr;
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralInt* left, LiteralFloat* right) {
return new LiteralBool(left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralDouble* left, LiteralFloat* right) {
return new LiteralBool(left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralFloat* left, LiteralFloat* right) {
return new LiteralBool(left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralString* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralString | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralBool* left, LiteralFloat* right) {
throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralBool | LiteralFloat!");
return nullptr;
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralInt* left, LiteralDouble* right) {
return new LiteralBool(left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralDouble* left, LiteralDouble* right) {
return new LiteralBool(left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralFloat* left, LiteralDouble* right) {
return new LiteralBool(left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralString* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralString | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralBool* left, LiteralDouble* right) {
throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralBool | LiteralDouble!");
return nullptr;
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralInt* left, LiteralInt* right) {
return new LiteralBool(left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralDouble* left, LiteralInt* right) {
return new LiteralBool(left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralFloat* left, LiteralInt* right) {
return new LiteralBool(left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralString* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralString | LiteralInt!");
return nullptr;
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralBool* left, LiteralInt* right) {
throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralBool | LiteralInt!");
return nullptr;
}


Literal* OperationsDispatcher::negate(LiteralInt* right) {
  return new LiteralInt(-right->value);
}
Literal* OperationsDispatcher::negate(LiteralFloat* right) {
  return new LiteralFloat(-right->value);
}
Literal* OperationsDispatcher::negate(LiteralString* right) {
  throw std::runtime_error("Illegal operation[negate] LiteralString!");
  return nullptr;
}
Literal* OperationsDispatcher::negate(LiteralBool* right) {
  return new LiteralBool(!right->value);
}
Literal* OperationsDispatcher::negate(LiteralDouble* right) {
  return new LiteralDouble(-right->value);
}