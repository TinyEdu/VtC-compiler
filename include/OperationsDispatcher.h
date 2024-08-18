// OperationsDispatcher.h

#ifndef OPERATIONS_DISPATCHER_H
#define OPERATIONS_DISPATCHER_H

#include "ExpressionWorld.h"

class OperationsDispatcher {
 public:
  template<typename T1, typename T2>
  Expression* dispatch(T1 left, T2 right);

  // Every unique possible combination of dispatches for literals
  
  // Addition
  Expression* add(LiteralInt* left, LiteralInt* right);
  Expression* add(LiteralInt* left, LiteralFloat* right);
  Expression* add(LiteralInt* left, LiteralString* right);
  Expression* add(LiteralInt* left, LiteralBool* right);
  Expression* add(LiteralInt* left, LiteralDouble* right);
  
  Expression* add(LiteralFloat* left, LiteralInt* right);
  Expression* add(LiteralFloat* left, LiteralFloat* right);
  Expression* add(LiteralFloat* left, LiteralString* right);
  Expression* add(LiteralFloat* left, LiteralBool* right);
  Expression* add(LiteralFloat* left, LiteralDouble* right);

  Expression* add(LiteralString* left, LiteralInt* right);
  Expression* add(LiteralString* left, LiteralFloat* right);
  Expression* add(LiteralString* left, LiteralString* right);
  Expression* add(LiteralString* left, LiteralBool* right);
  Expression* add(LiteralString* left, LiteralDouble* right);

  Expression* add(LiteralBool* left, LiteralInt* right);
  Expression* add(LiteralBool* left, LiteralFloat* right);
  Expression* add(LiteralBool* left, LiteralString* right);
  Expression* add(LiteralBool* left, LiteralBool* right);
  Expression* add(LiteralBool* left, LiteralDouble* right);

  Expression* add(LiteralDouble* left, LiteralInt* right);
  Expression* add(LiteralDouble* left, LiteralFloat* right);
  Expression* add(LiteralDouble* left, LiteralString* right);
  Expression* add(LiteralDouble* left, LiteralBool* right);
  Expression* add(LiteralDouble* left, LiteralDouble* right);


};


#endif // OPERATIONS_DISPATCHER_H