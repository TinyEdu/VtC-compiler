#include "Expression.h"

// Define constructors and accept methods
Binary::Binary(Expression* left, Token op, Expression* right)
    : left(left), op(op), right(right) {}

std::any Binary::accept(Visitor* visitor) {
  return visitor->visit(this);
}

Grouping::Grouping(Expression* expression) : expression(expression) {}

std::any Grouping::accept(Visitor* visitor) {
  return visitor->visit(this);
}

Unary::Unary(Token op, Expression* right) : op(op), right(right) {}

std::any Unary::accept(Visitor* visitor) {
  return visitor->visit(this);
}

// Define constructors and accept methods
Literal::Literal(void* value) {
    type = Type::BOOL; 
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
    // Assuming `value` is a `std::any` containing the actual value
    if (type == Type::STRING) {
        return value;
    } else if (type == Type::INT) {
        return std::to_string(std::any_cast<int>(value));
    } else if (type == Type::DOUBLE) {
        return std::to_string(std::any_cast<double>(value));
    } else if (type == Type::BOOL) {
        return std::any_cast<bool>(value) ? "true" : "false";
    } 
    // Add other types as needed
    return ""; // Default case, should not reach here if all types are handled
}


Literal* operator-(const Literal& lhs) {
    if (lhs.type == Type::BOOL) 
        throw std::invalid_argument("Literal operation. Wrong types [- operator]");

    Literal* result = nullptr;

    if (lhs.type == Type::DOUBLE) {
        double value = -lhs.getValue<double>();
        result = new Literal(value);
    } 
    else if (lhs.type == Type::INT) {
        int value = -lhs.getValue<int>();
        result = new Literal(value);
    } 
    else {
        std::cout << "SOMETHING MIGHT BE OFF - Literal.\n";
    }

    return result;
}

Literal* operator+(const Literal& lhs, const Literal& rhs) {
  if (lhs.type == Type::BOOL || rhs.type == Type::BOOL)
    throw std::invalid_argument("Literal operation. Wrong types");
  if (lhs.type == Type::STRING ^ rhs.type == Type::STRING)
    throw std::invalid_argument("Literal wrong string adding");

  Literal* result = nullptr;
  if (lhs.type == Type::DOUBLE ||
      rhs.type ==
          Type::
              DOUBLE) {  // if one of these values is double --> result is double
    double value = lhs.getValue<double>() + rhs.getValue<double>();
    result = new Literal(Type::DOUBLE, value);
  } else if (lhs.type == Type::INT &&
             rhs.type == Type::INT) {  // if both are int --> result is int
    int value = lhs.getValue<int>() + rhs.getValue<int>();
    result = new Literal(Type::INT, value);
  } else {
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

bool operator!=(const Literal& lhs, const Literal& rhs) {
  return !(lhs == rhs);
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
    return rhs > lhs;
}

bool operator>=(const Literal& lhs, const Literal& rhs) {
    return !(lhs < rhs);
}

bool operator<=(const Literal& lhs, const Literal& rhs) {
  return !(lhs > rhs);
}

Literal* operator!(const Literal& lhs) {
    Literal* result = new Literal(true);

    if (lhs.type == Type::BOOL) {
        result = new Literal(!lhs.getValue<bool>());
    }
    else if (lhs.type == Type::STRING) {
        result == new Literal(lhs.getValue<std::string>() != "");
    }
    else if (lhs.type == Type::INT) {
        result = new Literal(lhs.getValue<int>() != 0);
    }
    else if (lhs.type == Type::DOUBLE) {
        result = new Literal(lhs.getValue<double>() != 0);
    }
    
    return result;
}

std::ostream& operator<<(std::ostream& os, const Grouping* expr) {
    os << expr->expression;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Binary* expr) {
    os << &expr->left << " " << expr->op.lexeme << " " << &expr->right;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Unary* expr) {
    os << expr->op.lexeme << " " << expr->right;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Literal& expr) {
    os << "Literal: ";
    if (expr.type == Type::BOOL) {
        os << expr.getValue<bool>();
    } 
    else if (expr.type == Type::DOUBLE) {
        os << expr.getValue<double>();
    } 
    else if (expr.type == Type::INT) {
        os << expr.getValue<int>();
    } 
    else if (expr.type == Type::STRING) {
        os << expr.getValue<std::string>();
    } 
    else {
        os << "Unsupported type";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Literal* expr) {
    os << "Literal: ";

    return os;
}