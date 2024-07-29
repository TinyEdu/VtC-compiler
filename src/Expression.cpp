#include "Expression.h"
#include "Visitor.h"

// Define constructors and accept methods
Literal::Literal(void* value) {
    type = Type::BOOL; // Assuming this default, modify as per actual logic
    this->value = value;
}

Literal::Literal(bool value) {
    type = Type::BOOL;
    this->value = value;
}

Literal::Literal(const std::string& value) {
    type = Type::STRING;
    this->value = value;
}

Literal::Literal(int value) {
    type = Type::INT;
    this->value = value;
}

Literal::Literal(double value) {
    type = Type::DOUBLE;
    this->value = value;
}

Literal::Literal(Type type, std::any value) {
    this->type = type;
    this->value = value;
}

std::any Literal::accept(Visitor* visitor) {
    return visitor->visit(this);
}

std::any Literal::getValue() {
  return value;
}


Literal* operator+(const Literal& lhs, const Literal& rhs) {
    if (lhs.type == Type::BOOL || rhs.type == Type::BOOL) 
        throw std::invalid_argument("Literal operation. Wrong types"); 
    if (lhs.type == Type::STRING ^ rhs.type == Type::STRING) 
        throw std::invalid_argument("Literal wrong string adding");

    Literal* result = nullptr;
    if (lhs.type == Type::DOUBLE || rhs.type == Type::DOUBLE) {
        double value = lhs.getValue<double>() + rhs.getValue<double>();
        result = new Literal(Type::DOUBLE, value);
    } 
    else if (lhs.type == Type::INT && rhs.type == Type::INT) {
        int value = lhs.getValue<int>() + rhs.getValue<int>();
        result = new Literal(Type::INT, value);
    } 
    else {
        std::cout << "SOMETHING MIGHT BE OFF + Literal.\n";
    }

    return result;
}

Literal* operator-(const Literal& lhs, const Literal& rhs) {
    if (lhs.type == Type::BOOL || rhs.type == Type::BOOL) 
        throw std::invalid_argument("Literal operation. Wrong types"); 
    if (lhs.type == Type::STRING ^ rhs.type == Type::STRING) 
        throw std::invalid_argument("Literal wrong string adding");

    Literal* result = nullptr;
    if (lhs.type == Type::DOUBLE || rhs.type == Type::DOUBLE) {
        double value = lhs.getValue<double>() - rhs.getValue<double>();
        result = new Literal(Type::DOUBLE, value);
    } 
    else if (lhs.type == Type::INT && rhs.type == Type::INT) {
        int value = lhs.getValue<int>() - rhs.getValue<int>();
        result = new Literal(Type::INT, value);
    } 
    else {
        std::cout << "SOMETHING MIGHT BE OFF - Literal.\n";
    }
    return result;
}

Literal* operator/(const Literal& lhs, const Literal& rhs) {
    if (lhs.type == Type::BOOL || rhs.type == Type::BOOL) 
        throw std::invalid_argument("Literal operation. Wrong types"); 
    if (lhs.type == Type::STRING ^ rhs.type == Type::STRING) 
        throw std::invalid_argument("Literal wrong string adding");


    Literal* result = nullptr;
    if ((rhs.type == Type::INT && rhs.getValue<int>() == 0) ||
        (rhs.type == Type::DOUBLE && rhs.getValue<double>() == 0)) {
        result = new Literal(Type::INT, 0);
        std::cout << "CAN'T DIV BY 0.\n";
    }

    if (lhs.type == Type::DOUBLE || rhs.type == Type::DOUBLE) {
        double value = lhs.getValue<double>() / rhs.getValue<double>();
        result = new Literal(Type::DOUBLE, value);
    } 
    else if (lhs.type == Type::INT && rhs.type == Type::INT) {
        int value = lhs.getValue<int>() / rhs.getValue<int>();
        result = new Literal(Type::INT, value);
    } 
    else {
        std::cout << "SOMETHING MIGHT BE OFF / Literal.\n";
    }
    return result;
}

Literal* operator*(const Literal& lhs, const Literal& rhs) {
    if (lhs.type == Type::BOOL || rhs.type == Type::BOOL) 
        throw std::invalid_argument("Literal operation. Wrong types"); 
    if (lhs.type == Type::STRING ^ rhs.type == Type::STRING) 
        throw std::invalid_argument("Literal wrong string adding");


    Literal* result = nullptr;
    if (lhs.type == Type::DOUBLE || rhs.type == Type::DOUBLE) {
        double value = lhs.getValue<double>() * rhs.getValue<double>();
        result = new Literal(Type::DOUBLE, value);
    } 
    else if (lhs.type == Type::INT && rhs.type == Type::INT) {
        int value = lhs.getValue<int>() * rhs.getValue<int>();
        result = new Literal(Type::INT, value);
    } 
    else {
        std::cout << "SOMETHING MIGHT BE OFF * Literal.\n";
    }
    return result;
}

bool operator==(const Literal& lhs, const Literal& rhs) {
    if (lhs.type != rhs.type) {
        return false;
    }
    
    if (lhs.type == Type::BOOL) {
        return lhs.getValue<bool>() == rhs.getValue<bool>();
    }
    else if (lhs.type == Type::DOUBLE) {
        return lhs.getValue<double>() == rhs.getValue<double>();
    }
    else if (lhs.type == Type::INT) {
        return lhs.getValue<int>() == rhs.getValue<int>();
    }
    else if (lhs.type == Type::STRING) {
        return lhs.getValue<std::string>() == rhs.getValue<std::string>();
    }
    else {
        throw std::runtime_error("Unsupported type for comparison");
    }

    return false;
}

bool operator>(const Literal& lhs, const Literal& rhs) {
    if (lhs.type != rhs.type) {
        return false;
    }
    
    if (lhs.type == Type::BOOL) {
        return lhs.getValue<bool>() > rhs.getValue<bool>();
    }
    else if (lhs.type == Type::DOUBLE) {
        return lhs.getValue<double>() > rhs.getValue<double>();
    }
    else if (lhs.type == Type::INT) {
        return lhs.getValue<int>() > rhs.getValue<int>();
    }
    else if (lhs.type == Type::STRING) {
        return lhs.getValue<std::string>() > rhs.getValue<std::string>();
    }
    else {
        throw std::runtime_error("Unsupported type for >");
    }

    return false;
}

bool operator<(const Literal& lhs, const Literal& rhs) {
    return lhs > rhs;
}

Literal* operator!(const Literal& lhs) {
    if (lhs.type != Type::BOOL) 
        throw std::invalid_argument("Literal operation. Wrong types [! operator]");

    Literal* result = new Literal(!lhs.getValue<bool>());
    return result;
}



