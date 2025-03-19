// Summarizing: Declaration of all Expression classes.

#ifndef EXPRESSION_WORLD_H
#define EXPRESSION_WORLD_H

#include "Expressions/Assign.h"
#include "Expressions/Binary.h"
#include "Expressions/Expression.h"
#include "Expressions/Grouping.h"
#include "Expressions/Logical.h"
#include "Expressions/Unary.h"
#include "Expressions/Variable.h"
#include "Expressions/Call.h"


// Literals
#include "Expressions/Literals/Literal.h"
#include "Expressions/Literals/LiteralBool.h"
#include "Expressions/Literals/LiteralDouble.h"
#include "Expressions/Literals/LiteralFloat.h"
#include "Expressions/Literals/LiteralInt.h"
#include "Expressions/Literals/LiteralString.h"

#include <any>

#endif  // EXPRESSION_WORLD_H