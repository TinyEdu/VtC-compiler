
template<typename R>
class Visitor {
public:
    virtual R visit(class Binary* expr) = 0;
    virtual R visit(class Grouping* expr) = 0;
    virtual R visit(class Literal* expr) = 0;
    virtual R visit(class Unary* expr) = 0;
};


template<typename R>
class Expression {
public:
    virtual ~Expression() = default;
    virtual <R> accept(Visitor<R>* visitor) = 0;
};


template<typename R>
class Binary : public Expression {
public:
    Binary(Expression* left, Token op, Expression* right) : left(left), op(op), right(right) {}
    <R> accept(Visitor<R>* visitor) override {
        return visitor->visit(this);
    }

    Expression* left;
    Token op;
    Expression* right;
};


template<typename R>
class Grouping : public Expression {
public:
    Grouping(Expression* expression) : expression(expression) {}
    <R> accept(Visitor<R>* visitor) override {
        return visitor->visit(this);
    }

    Expression* expression;
};


template<typename R>
class Literal : public Expression {
public:
    Literal(std::any value) : value(value) {}
    <R> accept(Visitor<R>* visitor) override {
        return visitor->visit(this);
    }

    std::any value;
};


template<typename R>
class Unary : public Expression {
public:
    Unary(Token op, Expression* right) : op(op), right(right) {}
    <R> accept(Visitor<R>* visitor) override {
        return visitor->visit(this);
    }

    Token op;
    Expression* right;
};
