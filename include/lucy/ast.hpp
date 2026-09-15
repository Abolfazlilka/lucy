#pragma once
#include "token.hpp"
#include "value.hpp"
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
namespace lucy {
struct Expr{virtual~Expr()=default;};using ExprPtr=std::shared_ptr<Expr>;
struct Literal:Expr{Value value;explicit Literal(Value v):value(std::move(v)){}};
struct Variable:Expr{std::string name;explicit Variable(std::string n):name(std::move(n)){}};
struct Unary:Expr{Token op;ExprPtr right;bool postfix=false;Unary(Token o,ExprPtr r,bool p=false):op(std::move(o)),right(std::move(r)),postfix(p){}};
struct Binary:Expr{ExprPtr left,right;Token op;Binary(ExprPtr l,Token o,ExprPtr r):left(std::move(l)),right(std::move(r)),op(std::move(o)){}};
struct Ternary:Expr{ExprPtr c,t,f;Ternary(ExprPtr a,ExprPtr b,ExprPtr d):c(std::move(a)),t(std::move(b)),f(std::move(d)){}};
struct CallArg{std::string name;ExprPtr value;CallArg(std::string n,ExprPtr v):name(std::move(n)),value(std::move(v)){} };
struct Call:Expr{ExprPtr callee;std::vector<CallArg>args;Call(ExprPtr c,std::vector<CallArg>a):callee(std::move(c)),args(std::move(a)){} };
struct ArrayExpr:Expr{std::vector<ExprPtr>items;explicit ArrayExpr(std::vector<ExprPtr>i):items(std::move(i)){}};
struct MapExpr:Expr{std::vector<std::pair<std::string,ExprPtr>>items;explicit MapExpr(std::vector<std::pair<std::string,ExprPtr>>i):items(std::move(i)){}};
struct Index:Expr{ExprPtr object,index;Index(ExprPtr o,ExprPtr i):object(std::move(o)),index(std::move(i)){}};
struct Member:Expr{ExprPtr object;std::string name;Member(ExprPtr o,std::string n):object(std::move(o)),name(std::move(n)){}};
struct ShellExpr:Expr{std::string command;explicit ShellExpr(std::string c):command(std::move(c)){}};
struct RangeExpr:Expr{ExprPtr a,b;bool inclusive;RangeExpr(ExprPtr x,ExprPtr y,bool i):a(std::move(x)),b(std::move(y)),inclusive(i){}};
struct Stmt{virtual~Stmt()=default;};using StmtPtr=std::shared_ptr<Stmt>;
struct ExprStmt:Stmt{ExprPtr expr;explicit ExprStmt(ExprPtr e):expr(std::move(e)){} };
struct Assign:Stmt{ExprPtr target;Token op;ExprPtr value;Assign(ExprPtr t,Token o,ExprPtr v):target(std::move(t)),op(std::move(o)),value(std::move(v)){} };
struct VarDecl:Stmt{std::string name;ExprPtr value;bool constant=false,global=false;VarDecl(std::string n,ExprPtr v,bool c,bool g):name(std::move(n)),value(std::move(v)),constant(c),global(g){} };
struct Block:Stmt{std::vector<StmtPtr>statements;explicit Block(std::vector<StmtPtr>s):statements(std::move(s)){} };
struct IfStmt:Stmt{ExprPtr condition;StmtPtr then_branch;std::vector<std::pair<ExprPtr,StmtPtr>>else_ifs;StmtPtr else_branch;IfStmt(ExprPtr c,StmtPtr t,std::vector<std::pair<ExprPtr,StmtPtr>>e,StmtPtr x):condition(std::move(c)),then_branch(std::move(t)),else_ifs(std::move(e)),else_branch(std::move(x)){} };
struct WhileStmt:Stmt{ExprPtr condition;StmtPtr body;WhileStmt(ExprPtr c,StmtPtr b):condition(std::move(c)),body(std::move(b)){} };
struct ForStmt:Stmt{std::string name;ExprPtr iterable;StmtPtr body;ForStmt(std::string n,ExprPtr i,StmtPtr b):name(std::move(n)),iterable(std::move(i)),body(std::move(b)){} };
struct LoopStmt:Stmt{StmtPtr body;explicit LoopStmt(StmtPtr b):body(std::move(b)){} };
struct Parameter{std::string name;ExprPtr default_value;bool variadic=false;Parameter(std::string n,ExprPtr d=nullptr,bool v=false):name(std::move(n)),default_value(std::move(d)),variadic(v){} };
struct FunctionStmt:Stmt{std::string name;std::vector<Parameter>params;StmtPtr body;FunctionStmt(std::string n,std::vector<Parameter>p,StmtPtr b):name(std::move(n)),params(std::move(p)),body(std::move(b)){} };
struct ReturnStmt:Stmt{ExprPtr value;explicit ReturnStmt(ExprPtr v):value(std::move(v)){} };
struct ImportStmt:Stmt{std::string module,alias;std::vector<std::string>names;bool selective=false;ImportStmt(std::string m,std::vector<std::string>n={},bool s=false,std::string a=""):module(std::move(m)),alias(std::move(a)),names(std::move(n)),selective(s){} };
struct ClassStmt:Stmt{std::string name,base;std::vector<std::shared_ptr<FunctionStmt>>methods;ClassStmt(std::string n,std::string b,std::vector<std::shared_ptr<FunctionStmt>>m):name(std::move(n)),base(std::move(b)),methods(std::move(m)){} };
struct ThrowStmt:Stmt{ExprPtr value;explicit ThrowStmt(ExprPtr v):value(std::move(v)){} };
struct TryStmt:Stmt{StmtPtr body;std::string catch_type,catch_name;StmtPtr catch_body,finally_body;TryStmt(StmtPtr b,std::string t,std::string n,StmtPtr c,StmtPtr f):body(std::move(b)),catch_type(std::move(t)),catch_name(std::move(n)),catch_body(std::move(c)),finally_body(std::move(f)){} };
struct BreakStmt:Stmt{}; struct ContinueStmt:Stmt{};
struct Function{std::string name;std::vector<Parameter>params;StmtPtr body;std::shared_ptr<Environment>closure;Value::InstancePtr bound_self;std::function<Value(const std::vector<Value>&)>native;};
struct Class{std::string name,base;std::unordered_map<std::string,Value>methods;std::shared_ptr<Class>parent;};
struct Instance{std::shared_ptr<Class>klass;std::unordered_map<std::string,Value>fields;};
}
