from itertools import product

def generate_combinations():
    literal_types = [
        "LiteralInt",
        "LiteralFloat",
        "LiteralDouble",
        "LiteralString",
        "LiteralBool"
    ]

    method_names = [
        "add",
        "subtract",
        "multiply",
        "divide",
        "equal",
        "not_equal",
        "greater_than",
        "less_than",
        "greater_than_or_equal",
        "less_than_or_equal"
    ]

    combinations = list(product(literal_types, repeat=2))
    for method_name in method_names:
        print(f"// {method_name} functions")

        for left, right in combinations:
            print(f"static std::shared_ptr<Literal> {method_name}(std::shared_ptr<{left}> left, std::shared_ptr<{right}> right);")

        print("\n")


if __name__ == "__main__":
    generate_combinations()
