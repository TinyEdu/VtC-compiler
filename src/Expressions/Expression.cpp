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
  if (type == Type::STRING) {
    return value;
  } else if (type == Type::INT) {
    return std::to_string(std::any_cast<int>(value));
  } else if (type == Type::DOUBLE) {
    return std::to_string(std::any_cast<double>(value));
  } else if (type == Type::BOOL) {
    return std::any_cast<bool>(value) ? "true" : "false";
  }
  return "";
}

Expression* operator-(const Expression& lhs) {
  const Literal* _lhs = dynamic_cast<const Literal*>(&lhs);
  if (!_lhs) {
    throw std::invalid_argument("Unsupported type for - operator");
  }

  Literal* result = nullptr;
  if (_lhs->type == Type::DOUBLE) {
    double value = -_lhs->getValue<double>();
    result = new Literal(value);
  } else if (_lhs->type == Type::INT) {
    int value = -_lhs->getValue<int>();
    result = new Literal(value);
  }

  return result;
}

Expression* operator+(const Expression& lhs, const Expression& rhs) {
  const Literal* _lhs = dynamic_cast<const Literal*>(&lhs);
  const Literal* _rhs = dynamic_cast<const Literal*>(&rhs);

  if (!_lhs || !_rhs) {
    throw std::invalid_argument("Unsupported type for + operator");
  }

  Literal* result = nullptr;
  if (_lhs->type == Type::DOUBLE || _rhs->type == Type::DOUBLE) {
    double value = _lhs->getValue<double>() + _rhs->getValue<double>();
    result = new Literal(value);
  } else if (_lhs->type == Type::INT && _rhs->type == Type::INT) {
    int value = _lhs->getValue<int>() + _rhs->getValue<int>();
    result = new Literal(value);
  }

  return result;
}

Expression* operator-(const Expression& lhs, const Expression& rhs) {
  const Literal* _lhs = dynamic_cast<const Literal*>(&lhs);
  const Literal* _rhs = dynamic_cast<const Literal*>(&rhs);

  if (!_lhs || !_rhs) {
    throw std::invalid_argument("Unsupported type for - operator");
  }

  Literal* result = nullptr;
  if (_lhs->type == Type::DOUBLE || _rhs->type == Type::DOUBLE) {
    double value = _lhs->getValue<double>() - _rhs->getValue<double>();
    result = new Literal(Type::DOUBLE, value);
  } else if (_lhs->type == Type::INT && _rhs->type == Type::INT) {
    int value = _lhs->getValue<int>() - _rhs->getValue<int>();
    result = new Literal(Type::INT, value);
  }

  return result;
}

Expression* operator/(const Expression& lhs, const Expression& rhs) {
  const Literal* _lhs = dynamic_cast<const Literal*>(&lhs);
  const Literal* _rhs = dynamic_cast<const Literal*>(&rhs);

  if (!_lhs || !_rhs) {
    throw std::invalid_argument("Unsupported type for / operator");
  }

  Literal* result = nullptr;
  if ((_rhs->type == Type::INT && _rhs->getValue<int>() == 0) ||
      (_rhs->type == Type::DOUBLE && _rhs->getValue<double>() == 0)) {
    result = new Literal(Type::INT, 0);
    std::cout << "CAN'T DIV BY 0.\n";
  } else if (_lhs->type == Type::DOUBLE || _rhs->type == Type::DOUBLE) {
    double value = _lhs->getValue<double>() / _rhs->getValue<double>();
    result = new Literal(Type::DOUBLE, value);
  } else if (_lhs->type == Type::INT && _rhs->type == Type::INT) {
    int value = _lhs->getValue<int>() / _rhs->getValue<int>();
    result = new Literal(Type::INT, value);
  }

  return result;
}

Expression* operator*(const Expression& lhs, const Expression& rhs) {
  const Literal* _lhs = dynamic_cast<const Literal*>(&lhs);
  const Literal* _rhs = dynamic_cast<const Literal*>(&rhs);

  if (!_lhs || !_rhs) {
    throw std::invalid_argument("Unsupported type for * operator");
  }

  Literal* result = nullptr;
  if (_lhs->type == Type::DOUBLE || _rhs->type == Type::DOUBLE) {
    double value = _lhs->getValue<double>() * _rhs->getValue<double>();
    result = new Literal(Type::DOUBLE, value);
  } else if (_lhs->type == Type::INT && _rhs->type == Type::INT) {
    int value = _lhs->getValue<int>() * _rhs->getValue<int>();
    result = new Literal(Type::INT, value);
  }

  return result;
}

bool operator==(const Expression& lhs, const Expression& rhs) {
  const Literal* _lhs = dynamic_cast<const Literal*>(&lhs);
  const Literal* _rhs = dynamic_cast<const Literal*>(&rhs);

  if (!_lhs || !_rhs) {
    throw std::invalid_argument("Unsupported type for == operator");
  }

  if (_lhs->type != _rhs->type) {
    return false;
  }

  if (_lhs->type == Type::BOOL) {
    return _lhs->getValue<bool>() == _rhs->getValue<bool>();
  } else if (_lhs->type == Type::DOUBLE) {
    return _lhs->getValue<double>() == _rhs->getValue<double>();
  } else if (_lhs->type == Type::INT) {
    return _lhs->getValue<int>() == _rhs->getValue<int>();
  } else if (_lhs->type == Type::STRING) {
    return _lhs->getValue<std::string>() == _rhs->getValue<std::string>();
  } else {
    throw std::runtime_error("Unsupported type for comparison");
  }
}

bool operator!=(const Expression& lhs, const Expression& rhs) {
  return !(lhs == rhs);
}

bool operator>(const Expression& lhs, const Expression& rhs) {
  const Literal* _lhs = dynamic_cast<const Literal*>(&lhs);
  const Literal* _rhs = dynamic_cast<const Literal*>(&rhs);

  if (!_lhs || !_rhs) {
    throw std::invalid_argument("Unsupported type for > operator");
  }

  if (_lhs->type != _rhs->type) {
    return false;
  }

  if (_lhs->type == Type::BOOL) {
    return _lhs->getValue<bool>() > _rhs->getValue<bool>();
  } else if (_lhs->type == Type::DOUBLE) {
    return _lhs->getValue<double>() > _rhs->getValue<double>();
  } else if (_lhs->type == Type::INT) {
    return _lhs->getValue<int>() > _rhs->getValue<int>();
  } else if (_lhs->type == Type::STRING) {
    return _lhs->getValue<std::string>() > _rhs->getValue<std::string>();
  } else {
    throw std::runtime_error("Unsupported type for >");
  }
}

bool operator<(const Expression& lhs, const Expression& rhs) {
  return rhs > lhs;
}

bool operator>=(const Expression& lhs, const Expression& rhs) {
  return !(lhs < rhs);
}

bool operator<=(const Expression& lhs, const Expression& rhs) {
  return !(lhs > rhs);
}

Expression* operator!(const Expression& lhs) {
  const Literal* _lhs = dynamic_cast<const Literal*>(&lhs);
  if (!_lhs) {
    throw std::invalid_argument("Unsupported type for ! operator");
  }

  Literal* result = new Literal(true);

  if (_lhs->type == Type::BOOL) {
    result = new Literal(!_lhs->getValue<bool>());
  } else if (_lhs->type == Type::STRING) {
    result == new Literal(_lhs->getValue<std::string>() != "");
  } else if (_lhs->type == Type::INT) {
    result = new Literal(_lhs->getValue<int>() != 0);
  } else if (_lhs->type == Type::DOUBLE) {
    result = new Literal(_lhs->getValue<double>() != 0);
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
  os << "[L&]";
  if (expr.type == Type::BOOL) {
    os << expr.getValue<bool>();
  } else if (expr.type == Type::DOUBLE) {
    os << expr.getValue<double>();
  } else if (expr.type == Type::INT) {
    os << expr.getValue<int>();
  } else if (expr.type == Type::STRING) {
    os << expr.getValue<std::string>();
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const Literal* expr) {
  os << "[L*]";
  if (expr->type == Type::BOOL) {
    os << expr->getValue<bool>();
  } else if (expr->type == Type::DOUBLE) {
    os << expr->getValue<double>();
  } else if (expr->type == Type::INT) {
    os << expr->getValue<int>();
  } else if (expr->type == Type::STRING) {
    os << expr->getValue<std::string>();
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const Variable* expr) {
  os << expr->name.lexeme;
  return os;
}

std::ostream& operator<<(std::ostream& os, const Expression* expr) {
  if (const Literal* _expr = dynamic_cast<const Literal*>(expr)) {
    os << _expr;
  } else if (const Grouping* _expr = dynamic_cast<const Grouping*>(expr)) {
    os << _expr;
  } else if (const Binary* _expr = dynamic_cast<const Binary*>(expr)) {
    os << _expr;
  } else if (const Unary* _expr = dynamic_cast<const Unary*>(expr)) {
    os << _expr;
  } else if (const Variable* _expr = dynamic_cast<const Variable*>(expr)) {
    os << _expr;
  }

  return os;
}

std::ostream& operator<<(std::ostream& os, const Expression& expr) {
  if (const Literal* _expr = dynamic_cast<const Literal*>(&expr)) {
    os << _expr;
  } else if (const Grouping* _expr = dynamic_cast<const Grouping*>(&expr)) {
    os << _expr;
  } else if (const Binary* _expr = dynamic_cast<const Binary*>(&expr)) {
    os << _expr;
  } else if (const Unary* _expr = dynamic_cast<const Unary*>(&expr)) {
    os << _expr;
  } else if (const Variable* _expr = dynamic_cast<const Variable*>(&expr)) {
    os << _expr;
  }

  return os;
}

Variable::Variable(Token name) : name(name) {}

std::any Variable::accept(Visitor* visitor) {
  return visitor->visit(this);
}

Assign::Assign(Token name, Expression* value) : name(name), value(value) {}

std::any Assign::accept(Visitor* visitor) {
  return visitor->visit(this);
}

Logical::Logical(Expression* left, Token op, Expression* right)
    : left(left), op(op), right(right) {}

std::any Logical::accept(Visitor* visitor) {
  return visitor->visit(this);
}
