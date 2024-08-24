#include "OperationsDispatcher.h"
#include "Literal.h"
#include "LiteralBool.h"
#include "LiteralDouble.h"
#include "LiteralFloat.h"
#include "LiteralInt.h"
#include "LiteralString.h"

// Function: add
Literal* OperationsDispatcher::add(LiteralInt* left, LiteralBool* right) {
return new LiteralInt(left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralDouble* left, LiteralBool* right) {
return new LiteralDouble(left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralFloat* left, LiteralBool* right) {
return new LiteralFloat(left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralString* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[add] LiteralString | LiteralBool!");
}

Literal* OperationsDispatcher::add(LiteralBool* left, LiteralBool* right) {
return new LiteralInt(left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[add] LiteralInt | LiteralString!");
}

Literal* OperationsDispatcher::add(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[add] LiteralDouble | LiteralString!");
}

Literal* OperationsDispatcher::add(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[add] LiteralFloat | LiteralString!");
}

Literal* OperationsDispatcher::add(LiteralString* left, LiteralString* right) {
return new LiteralString(left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralBool* left, LiteralString* right) {
return new (left->value + right->value);
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
return new (left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralBool* left, LiteralFloat* right) {
return new (left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralInt* left, LiteralDouble* right) {
return new LiteralDouble(left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralDouble* left, LiteralDouble* right) {
return new LiteralDouble(left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralFloat* left, LiteralDouble* right) {
return new (left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralString* left, LiteralDouble* right) {
return new (left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralBool* left, LiteralDouble* right) {
return new (left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralInt* left, LiteralInt* right) {
return new LiteralInt(left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralDouble* left, LiteralInt* right) {
return new (left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralFloat* left, LiteralInt* right) {
return new (left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralString* left, LiteralInt* right) {
return new (left->value + right->value);
}

Literal* OperationsDispatcher::add(LiteralBool* left, LiteralInt* right) {
return new (left->value + right->value);
}


// Function: subtract
Literal* OperationsDispatcher::subtract(LiteralInt* left, LiteralBool* right) {
return new LiteralInt(left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralDouble* left, LiteralBool* right) {
return new LiteralDouble(left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralFloat* left, LiteralBool* right) {
return new LiteralFloat(left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralString* left, LiteralBool* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralString | LiteralBool!");
}

Literal* OperationsDispatcher::subtract(LiteralBool* left, LiteralBool* right) {
return new LiteralInt(left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralInt | LiteralString!");
}

Literal* OperationsDispatcher::subtract(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralDouble | LiteralString!");
}

Literal* OperationsDispatcher::subtract(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[subtract] LiteralFloat | LiteralString!");
}

Literal* OperationsDispatcher::subtract(LiteralString* left, LiteralString* right) {
return new LiteralString(left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralBool* left, LiteralString* right) {
return new (left->value - right->value);
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
return new (left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralBool* left, LiteralFloat* right) {
return new (left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralInt* left, LiteralDouble* right) {
return new LiteralDouble(left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralDouble* left, LiteralDouble* right) {
return new LiteralDouble(left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralFloat* left, LiteralDouble* right) {
return new (left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralString* left, LiteralDouble* right) {
return new (left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralBool* left, LiteralDouble* right) {
return new (left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralInt* left, LiteralInt* right) {
return new LiteralInt(left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralDouble* left, LiteralInt* right) {
return new (left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralFloat* left, LiteralInt* right) {
return new (left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralString* left, LiteralInt* right) {
return new (left->value - right->value);
}

Literal* OperationsDispatcher::subtract(LiteralBool* left, LiteralInt* right) {
return new (left->value - right->value);
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
}

Literal* OperationsDispatcher::multiply(LiteralBool* left, LiteralBool* right) {
return new LiteralInt(left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[multiply] LiteralInt | LiteralString!");
}

Literal* OperationsDispatcher::multiply(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[multiply] LiteralDouble | LiteralString!");
}

Literal* OperationsDispatcher::multiply(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[multiply] LiteralFloat | LiteralString!");
}

Literal* OperationsDispatcher::multiply(LiteralString* left, LiteralString* right) {
return new LiteralString(left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralBool* left, LiteralString* right) {
return new (left->value * right->value);
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
return new (left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralBool* left, LiteralFloat* right) {
return new (left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralInt* left, LiteralDouble* right) {
return new LiteralDouble(left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralDouble* left, LiteralDouble* right) {
return new LiteralDouble(left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralFloat* left, LiteralDouble* right) {
return new (left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralString* left, LiteralDouble* right) {
return new (left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralBool* left, LiteralDouble* right) {
return new (left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralInt* left, LiteralInt* right) {
return new LiteralInt(left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralDouble* left, LiteralInt* right) {
return new (left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralFloat* left, LiteralInt* right) {
return new (left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralString* left, LiteralInt* right) {
return new (left->value * right->value);
}

Literal* OperationsDispatcher::multiply(LiteralBool* left, LiteralInt* right) {
return new (left->value * right->value);
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
}

Literal* OperationsDispatcher::divide(LiteralBool* left, LiteralBool* right) {
return new LiteralInt(left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[divide] LiteralInt | LiteralString!");
}

Literal* OperationsDispatcher::divide(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[divide] LiteralDouble | LiteralString!");
}

Literal* OperationsDispatcher::divide(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[divide] LiteralFloat | LiteralString!");
}

Literal* OperationsDispatcher::divide(LiteralString* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[divide] LiteralString | LiteralString!");
}

Literal* OperationsDispatcher::divide(LiteralBool* left, LiteralString* right) {
return new (left->value / right->value);
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
return new (left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralBool* left, LiteralFloat* right) {
return new (left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralInt* left, LiteralDouble* right) {
return new LiteralDouble(left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralDouble* left, LiteralDouble* right) {
return new LiteralDouble(left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralFloat* left, LiteralDouble* right) {
return new (left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralString* left, LiteralDouble* right) {
return new (left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralBool* left, LiteralDouble* right) {
return new (left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralInt* left, LiteralInt* right) {
return new LiteralInt(left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralDouble* left, LiteralInt* right) {
return new (left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralFloat* left, LiteralInt* right) {
return new (left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralString* left, LiteralInt* right) {
return new (left->value / right->value);
}

Literal* OperationsDispatcher::divide(LiteralBool* left, LiteralInt* right) {
return new (left->value / right->value);
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
}

Literal* OperationsDispatcher::equal(LiteralBool* left, LiteralBool* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[equal] LiteralInt | LiteralString!");
}

Literal* OperationsDispatcher::equal(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[equal] LiteralDouble | LiteralString!");
}

Literal* OperationsDispatcher::equal(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[equal] LiteralFloat | LiteralString!");
}

Literal* OperationsDispatcher::equal(LiteralString* left, LiteralString* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralBool* left, LiteralString* right) {
return new (left->value == right->value);
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
return new (left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralBool* left, LiteralFloat* right) {
return new (left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralInt* left, LiteralDouble* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralDouble* left, LiteralDouble* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralFloat* left, LiteralDouble* right) {
return new (left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralString* left, LiteralDouble* right) {
return new (left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralBool* left, LiteralDouble* right) {
return new (left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralInt* left, LiteralInt* right) {
return new LiteralBool(left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralDouble* left, LiteralInt* right) {
return new (left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralFloat* left, LiteralInt* right) {
return new (left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralString* left, LiteralInt* right) {
return new (left->value == right->value);
}

Literal* OperationsDispatcher::equal(LiteralBool* left, LiteralInt* right) {
return new (left->value == right->value);
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
}

Literal* OperationsDispatcher::not_equal(LiteralBool* left, LiteralBool* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[not_equal] LiteralInt | LiteralString!");
}

Literal* OperationsDispatcher::not_equal(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[not_equal] LiteralDouble | LiteralString!");
}

Literal* OperationsDispatcher::not_equal(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[not_equal] LiteralFloat | LiteralString!");
}

Literal* OperationsDispatcher::not_equal(LiteralString* left, LiteralString* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralBool* left, LiteralString* right) {
return new (left->value != right->value);
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
return new (left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralBool* left, LiteralFloat* right) {
return new (left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralInt* left, LiteralDouble* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralDouble* left, LiteralDouble* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralFloat* left, LiteralDouble* right) {
return new (left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralString* left, LiteralDouble* right) {
return new (left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralBool* left, LiteralDouble* right) {
return new (left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralInt* left, LiteralInt* right) {
return new LiteralBool(left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralDouble* left, LiteralInt* right) {
return new (left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralFloat* left, LiteralInt* right) {
return new (left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralString* left, LiteralInt* right) {
return new (left->value != right->value);
}

Literal* OperationsDispatcher::not_equal(LiteralBool* left, LiteralInt* right) {
return new (left->value != right->value);
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
}

Literal* OperationsDispatcher::greater_than(LiteralBool* left, LiteralBool* right) {
return new LiteralBool(left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[greater_than] LiteralInt | LiteralString!");
}

Literal* OperationsDispatcher::greater_than(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[greater_than] LiteralDouble | LiteralString!");
}

Literal* OperationsDispatcher::greater_than(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[greater_than] LiteralFloat | LiteralString!");
}

Literal* OperationsDispatcher::greater_than(LiteralString* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[greater_than] LiteralString | LiteralString!");
}

Literal* OperationsDispatcher::greater_than(LiteralBool* left, LiteralString* right) {
return new (left->value > right->value);
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
return new (left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralBool* left, LiteralFloat* right) {
return new (left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralInt* left, LiteralDouble* right) {
return new LiteralBool(left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralDouble* left, LiteralDouble* right) {
return new LiteralBool(left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralFloat* left, LiteralDouble* right) {
return new (left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralString* left, LiteralDouble* right) {
return new (left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralBool* left, LiteralDouble* right) {
return new (left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralInt* left, LiteralInt* right) {
return new LiteralBool(left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralDouble* left, LiteralInt* right) {
return new (left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralFloat* left, LiteralInt* right) {
return new (left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralString* left, LiteralInt* right) {
return new (left->value > right->value);
}

Literal* OperationsDispatcher::greater_than(LiteralBool* left, LiteralInt* right) {
return new (left->value > right->value);
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
}

Literal* OperationsDispatcher::less_than(LiteralBool* left, LiteralBool* right) {
return new LiteralBool(left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[less_than] LiteralInt | LiteralString!");
}

Literal* OperationsDispatcher::less_than(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[less_than] LiteralDouble | LiteralString!");
}

Literal* OperationsDispatcher::less_than(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[less_than] LiteralFloat | LiteralString!");
}

Literal* OperationsDispatcher::less_than(LiteralString* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[less_than] LiteralString | LiteralString!");
}

Literal* OperationsDispatcher::less_than(LiteralBool* left, LiteralString* right) {
return new (left->value < right->value);
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
return new (left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralBool* left, LiteralFloat* right) {
return new (left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralInt* left, LiteralDouble* right) {
return new LiteralBool(left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralDouble* left, LiteralDouble* right) {
return new LiteralBool(left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralFloat* left, LiteralDouble* right) {
return new (left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralString* left, LiteralDouble* right) {
return new (left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralBool* left, LiteralDouble* right) {
return new (left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralInt* left, LiteralInt* right) {
return new LiteralBool(left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralDouble* left, LiteralInt* right) {
return new (left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralFloat* left, LiteralInt* right) {
return new (left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralString* left, LiteralInt* right) {
return new (left->value < right->value);
}

Literal* OperationsDispatcher::less_than(LiteralBool* left, LiteralInt* right) {
return new (left->value < right->value);
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
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralBool* left, LiteralBool* right) {
return new LiteralBool(left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralInt | LiteralString!");
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralDouble | LiteralString!");
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralFloat | LiteralString!");
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralString* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[greater_than_or_equal] LiteralString | LiteralString!");
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralBool* left, LiteralString* right) {
return new (left->value >= right->value);
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
return new (left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralBool* left, LiteralFloat* right) {
return new (left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralInt* left, LiteralDouble* right) {
return new LiteralBool(left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralDouble* left, LiteralDouble* right) {
return new LiteralBool(left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralFloat* left, LiteralDouble* right) {
return new (left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralString* left, LiteralDouble* right) {
return new (left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralBool* left, LiteralDouble* right) {
return new (left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralInt* left, LiteralInt* right) {
return new LiteralBool(left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralDouble* left, LiteralInt* right) {
return new (left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralFloat* left, LiteralInt* right) {
return new (left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralString* left, LiteralInt* right) {
return new (left->value >= right->value);
}

Literal* OperationsDispatcher::greater_than_or_equal(LiteralBool* left, LiteralInt* right) {
return new (left->value >= right->value);
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
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralBool* left, LiteralBool* right) {
return new LiteralBool(left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralInt* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralInt | LiteralString!");
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralDouble* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralDouble | LiteralString!");
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralFloat* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralFloat | LiteralString!");
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralString* left, LiteralString* right) {
throw std::runtime_error("Illegal operation[less_than_or_equal] LiteralString | LiteralString!");
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralBool* left, LiteralString* right) {
return new (left->value <= right->value);
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
return new (left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralBool* left, LiteralFloat* right) {
return new (left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralInt* left, LiteralDouble* right) {
return new LiteralBool(left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralDouble* left, LiteralDouble* right) {
return new LiteralBool(left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralFloat* left, LiteralDouble* right) {
return new (left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralString* left, LiteralDouble* right) {
return new (left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralBool* left, LiteralDouble* right) {
return new (left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralInt* left, LiteralInt* right) {
return new LiteralBool(left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralDouble* left, LiteralInt* right) {
return new (left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralFloat* left, LiteralInt* right) {
return new (left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralString* left, LiteralInt* right) {
return new (left->value <= right->value);
}

Literal* OperationsDispatcher::less_than_or_equal(LiteralBool* left, LiteralInt* right) {
return new (left->value <= right->value);
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