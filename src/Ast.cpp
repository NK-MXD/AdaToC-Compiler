#include <Ast.h>

extern FILE *yyout;
int Node::counter = 0;

Node::Node()
{
    seq = counter++;
}

void Node::setNext(Node *node) {
    Node *n = this;
    while (n->getNext()) {
        n = n->getNext();
    }
    if (n == this) {
        this->next = node;
    } else {
        n->setNext(node);
    }
}

void Ast::dump()
{
    fprintf(yyout, "program\n");
    if(root != nullptr)
        root->dump(4);
}

void ExprNode::dump(int level) {
    std::string name, type;
    name = symbolEntry->dump();
    type = symbolEntry->getType()->dump();
    fprintf(yyout, "%*cconst string\ttype:%s\t%s\n", level, ' ', type.c_str(),
            name.c_str());
}

void BinaryExpr::dump(int level)
{
    std::string op_str;
    switch(op)
    {
        case ADD:
            op_str = "add";
            break;
        case SUB:
            op_str = "sub";
            break;
        case AND:
            op_str = "and";
            break;
        case OR:
            op_str = "or";
            break;
        case LESS:
            op_str = "less";
            break;
    }
    fprintf(yyout, "%*cBinaryExpr\top: %s\n", level, ' ', op_str.c_str());
    expr1->dump(level + 4);
    expr2->dump(level + 4);
}

void Constant::dump(int level)
{
    std::string type, value;
    type = symbolEntry->getType()->dump();
    value = symbolEntry->dump();
    fprintf(yyout, "%*cIntegerLiteral\tvalue: %s\ttype: %s\n", level, ' ',
            value.c_str(), type.c_str());
}

void Id::dump(int level)
{
    std::string name, type;
    int scope;
    name = symbolEntry->dump();
    type = symbolEntry->getType()->dump();
    scope = dynamic_cast<IdentifierSymbolEntry*>(symbolEntry)->getScope();
    fprintf(yyout, "%*cId\tname: %s\tscope: %d\ttype: %s\n", level, ' ',
            name.c_str(), scope, type.c_str());
}

void CallExpr::dump(int level) {
    std::string name, type;
    int scope;
    if (symbolEntry) {
        name = symbolEntry->dump();
        type = symbolEntry->getType()->dump();
        scope = dynamic_cast<IdentifierSymbolEntry *>(symbolEntry)->getScope();
        fprintf(yyout, "%*cCallExpr\tfunction name: %s\tscope: %d\ttype: %s\n",
                level, ' ', name.c_str(), scope, type.c_str());
        Node *temp = param;
        while (temp) {
            temp->dump(level + 4);
            temp = temp->getNext();
        }
    }
}

void ExprStmt::dump(int level) {
    fprintf(yyout, "%*cExprStmt\n", level, ' ');
    expr->dump(level + 4);
}

void CompoundStmt::dump(int level)
{
    fprintf(yyout, "%*cCompoundStmt\n", level, ' ');
    stmt->dump(level + 4);
}

void SeqNode::dump(int level)
{
    stmt1->dump(level);
    stmt2->dump(level);
}

void DeclStmt::dump(int level)
{
    fprintf(yyout, "%*cDeclStmt\n", level, ' ');
    id->dump(level + 4);
}

void IfStmt::dump(int level)
{
    fprintf(yyout, "%*cIfStmt\n", level, ' ');
    cond->dump(level + 4);
    thenStmt->dump(level + 4);
}

void ReturnStmt::dump(int level)
{
    fprintf(yyout, "%*cReturnStmt\n", level, ' ');
    retValue->dump(level + 4);
}

void AssignStmt::dump(int level)
{
    fprintf(yyout, "%*cAssignStmt\n", level, ' ');
    lval->dump(level + 4);
    expr->dump(level + 4);
}

void FunctionDef::dump(int level)
{
    std::string name, type;
    name = se->dump();
    type = se->getType()->dump();
    fprintf(yyout, "%*cFunctionDefine function name: %s, type: %s\n", level, ' ', 
            name.c_str(), type.c_str());
    stmt->dump(level + 4);
}