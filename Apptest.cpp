#include <iostream>

class Bin;
class Grp;

class Expr {
public:
    virtual void process(Expr* expr) = 0;
    virtual void process(Bin* expr) = 0;
    virtual void process(Grp* expr) = 0;
    virtual ~Expr() = default;
};

class Bin : public Expr {
public:
    void process(Expr* expr) override {
        expr->process(this);
    }

    void process(Bin* expr) override {
        std::cout << "Bin in Bin" << std::endl;
    }

    void process(Grp* expr) override {
        std::cout << "Grp in Bin" << std::endl;
    }
};

class Grp : public Expr {
public:
    void process(Expr* expr) override {
        expr->process(this);
    }

    void process(Bin* expr) override {
        std::cout << "Bin in Grp" << std::endl;
    }

    void process(Grp* expr) override {
        std::cout << "Grp in Grp" << std::endl;
    }
};

    Expr* a = new Bin();
    Expr* b = new Grp();
    a->process(b);

_____________________________________________________________________________________


#include <iostream>

class Bin;
class Grp;

class Expr {
public:
    virtual void process(Expr* expr) = 0;
    virtual void process(Bin* expr) = 0;
    virtual void process(Grp* expr) = 0;
    virtual ~Expr() = default;
};

class Bin : public Expr {
public:
    void process(Expr* expr) override {
        expr->process(this);
    }

    void process(Bin* expr) override {
        std::cout << "Bin in Bin" << std::endl;
    }

    void process(Grp* expr) override {
        std::cout << "Grp in Bin" << std::endl;
    }
};

class Grp : public Expr {
public:
    void process(Expr* expr) override {
        expr->process(this);
    }

    void process(Bin* expr) override {
        std::cout << "Bin in Grp" << std::endl;
    }

    void process(Grp* expr) override {
        std::cout << "Grp in Grp" << std::endl;
    }
};

int main() {
    Expr* a = new Bin();
    Expr* b = new Grp();
    a->process(b);
    delete a;
    delete b;
    return 0;
}


Functions should return Literal* and at end call an outside function

Add(l,r)
or
Review(TokenType,l,r)


Template
Static Literal Review(T1 a, T2 b, TokenType type)
Switch type:
  Case(plus);
      return reviewer::add(a, b);


Can I write a template function like this
Template
Static Literal Review(T1 a, T2 b, TokenType type)
Switch type:
  Case(plus);
      return reviewer::add(a, b);

And then declare all possible combinations of reviewer::add()
Like this
add(Bin,Grp)
add(Grp,Bin)
Etc.


#include <iostream>

enum class TokenType { Plus, Minus, Multiply, Divide };

template <typename T1, typename T2>
static auto Review(T1 a, T2 b, TokenType type) {
    switch (type) {
    case TokenType::Plus:
        return reviewer::add(a, b);
    case TokenType::Minus:
        return reviewer::subtract(a, b);
    case TokenType::Multiply:
        return reviewer::multiply(a, b);
    case TokenType::Divide:
        return reviewer::divide(a, b);
    default:
        throw std::invalid_argument("Unsupported operation");
    }
}



#include <iostream>
#include <type_traits>

enum class TokenType { Plus, Minus, Multiply, Divide };

class Bin {};  // Example class
class Grp {};  // Example class

namespace reviewer {

    // Example for valid operations
    int add(int a, int b) {
        return a + b;
    }

    Bin add(const Bin& a, const Grp& b) {
        // Implement addition for Bin and Grp
        return a;  // Dummy implementation
    }

    // Enable divide only if T1 and T2 are not Bin and Grp
    template <typename T1, typename T2>
    auto divide(const T1& a, const T2& b) -> std::enable_if_t<!std::is_same_v<T1, Bin> || !std::is_same_v<T2, Grp>, decltype(a / b)> {
        return a / b;
    }

    // Overload for when you attempt to divide Bin by Grp
    template <typename T1, typename T2>
    auto divide(const T1& a, const T2& b) -> std::enable_if_t<std::is_same_v<T1, Bin> && std::is_same_v<T2, Grp>, void> {
        std::cerr << "Error: Division between Bin and Grp is not supported!" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

template <typename T1, typename T2>
static auto Review(T1 a, T2 b, TokenType type) {
    switch (type) {
    case TokenType::Plus:
        return reviewer::add(a, b);
    case TokenType::Minus:
        // You would define and call subtract(a, b) here
        return 0;  // Placeholder
    case TokenType::Multiply:
        // You would define and call multiply(a, b) here
        return 0;  // Placeholder
    case TokenType::Divide:
        return reviewer::divide(a, b);
    default:
        throw std::invalid_argument("Unsupported operation");
    }
}

int main() {
    Bin bin;
    Grp grp;
    Review(bin, grp, TokenType::Divide);  // This will print an error and exit
    return 0;
}




Template class for handling cases we don't want to let 
