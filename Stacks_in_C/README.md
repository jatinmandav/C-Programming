# Stacks-In-C
Stacks In C Programming

A stack is a container of objects that are inserted and removed according to LIFO principle (LIFO : Last In First Out). The name "stack" for this data type of structure comes from the analogy to a set of physical items stacked on top of each other, which makes it easy to take an item off the top of the stack, while getting to an item deeper in the stack may require taking off multiple other items first.

In the pushdown stacks only two operations are allowed: Push and Pop. Push adds a new element on top of the stack, whereas Pop, removes the Topmost element from stack.

  - Infix to Postfix Expression Conversion
    - Algorithm:
      - Scan the infix expression from left to right.
      - If the scanned character is Operand, output it.
      - Else,
        - If the Precedence of scanned operator is greater than the precedence of the operator in the stack(or the stack is empty), push it.
        - Else, Pop the operator from the stack until the precedence of the scanned operator is less or equal to the precedence of the operator residing on the top of the stack. Push the scanned operator to the stack.
      - If the scanned character is an '(', push it to the stack.
      - If the scanned character is an ')', Pop and output the stack until an '(' is encountered.
      - Repeat until expression is scanned.
      - Pop and output from stack until stack is empty.
    - Code: [Infix to Postfix Epression Conversion](Stacks_In_C/InfixToPostfixUsingStacks.c/)
  
  - Postfix Expression Evaluation
    - Algorithm:
      - Create a Stack to store Operands (or Values).
      - Scan the given Expression:
        - If the element is a number, push it to the stack.
        - If the element is an operator, pop operands from the stack.
        - Evaluate the operator and push it back to the stack.
      - When the expression ends, the Number in the stack is the final result.
    - Code: [Postfix Expression Evaluation](Stacks_In_C/PostfixEvaluationUsingStacks.c/)
