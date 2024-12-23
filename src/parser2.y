/******* A YACC grammar for Ada 9X *********************************/
/* Copyright (C) Intermetrics, Inc. 1994 Cambridge, MA  USA        */
/* Copying permitted if accompanied by this statement.             */
/* Derivative works are permitted if accompanied by this statement.*/
/* This grammar is thought to be correct as of May 1, 1994         */
/* but as usual there is *no warranty* to that effect.             */
/*******************************************************************/
%code top{

    int yylex();
    int yyerror(char const*);
}

%token TIC
%token DOT_DOT
%token LT_LT
%token BOX
%token LT_EQ
%token EXPON
%token NE
%token GT_GT
%token GE
%token IS_ASSIGNED
%token RIGHT_SHAFT
%token ABORT
%token ABS
%token ABSTRACT
%token ACCEPT
%token ACCESS
%token ALIASED
%token ALL
%token AND
%token ARRAY
%token AT
%token BEGiN
%token BODY
%token CASE
%token CONSTANT
%token DECLARE
%token DELAY
%token DELTA
%token DIGITS
%token DO
%token ELSE
%token ELSIF
%token END
%token ENTRY
%token EXCEPTION
%token EXIT
%token FOR
%token FUNCTION
%token GENERIC
%token GOTO
%token IF
%token IN
%token IS
%token LIMITED
%token LOOP
%token MOD
%token NEW
%token NOT
%token NuLL
%token OF
%token OR
%token OTHERS
%token OUT
%token PACKAGE
%token PRAGMA
%token PRIVATE
%token PROCEDURE
%token PROTECTED
%token RAISE
%token RANGE
%token RECORD
%token REM
%token RENAMES
%token REQUEUE
%token RETURN
%token REVERSE
%token SELECT
%token SEPARATE
%token SUBTYPE
%token TAGGED
%token TASK
%token TERMINATE
%token THEN
%token TYPE
%token UNTIL
%token USE
%token WHEN
%token WHILE
%token WITH
%token XOR
%token char_lit
%token identifier
%token char_string
%token numeric_lit

%{
%}

%%

goal_symbol : compilation
	;

pragma  : PRAGMA identifier ';'
	| PRAGMA simple_name '(' pragma_arg_s ')' ';'
	;

pragma_arg_s : pragma_arg
	| pragma_arg_s ',' pragma_arg
	;

pragma_arg : expression
	| simple_name RIGHT_SHAFT expression
	;

pragma_s : pragma
	| pragma_s pragma
	;

decl    : object_decl
	| number_decl
	| type_decl
	| subtype_decl
	| subprog_decl
	| pkg_decl
	| task_decl
	| prot_decl
	| exception_decl
	| rename_decl
	| generic_decl
	| body_stub
	| error ';'
	;

object_decl : def_id_s ':' object_qualifier_opt object_subtype_def init_opt ';'
	;

def_id_s : def_id
	| def_id_s ',' def_id
	;

def_id  : identifier
	;

object_qualifier_opt : %empty
	| ALIASED
	| CONSTANT
	| ALIASED CONSTANT
	;

object_subtype_def : subtype_ind
	| array_type
	;

init_opt : %empty
	| IS_ASSIGNED expression
	;

number_decl : def_id_s ':' CONSTANT IS_ASSIGNED expression ';'
	;

type_decl : TYPE identifier discrim_part_opt type_completion ';'
	;

discrim_part_opt : %empty
	| discrim_part
	| '(' BOX ')'
	;

type_completion :%empty
	| IS type_def
	;

type_def : enumeration_type 
	| integer_type
	| real_type
	| array_type
	| record_type
	| access_type
	| derived_type
	| private_type
	;

subtype_decl : SUBTYPE identifier IS subtype_ind ';'
	;

subtype_ind : name constraint
	| name
	;

constraint : range_constraint
	| decimal_digits_constraint
	;

decimal_digits_constraint : DIGITS expression range_constr_opt
	;

derived_type : NEW subtype_ind
	| NEW subtype_ind WITH PRIVATE
	| NEW subtype_ind WITH record_def
	| ABSTRACT NEW subtype_ind WITH PRIVATE
	| ABSTRACT NEW subtype_ind WITH record_def
	;

range_constraint : RANGE range
	;

range : simple_expression DOT_DOT simple_expression
	| name TIC RANGE
	| name TIC RANGE '(' expression ')'
	;

enumeration_type : '(' enum_id_s ')'

enum_id_s : enum_id
	| enum_id_s ',' enum_id
	;

enum_id : identifier
	| char_lit
	;

integer_type : range_spec
	| MOD expression
	;
	

range_spec : range_constraint
	;

range_spec_opt : %empty
	| range_spec
	;

real_type : float_type
	| fixed_type
	;

float_type : DIGITS expression range_spec_opt
	;

fixed_type : DELTA expression range_spec
	| DELTA expression DIGITS expression range_spec_opt
	;

array_type : unconstr_array_type
	| constr_array_type
	;

unconstr_array_type : ARRAY '(' index_s ')' OF component_subtype_def
	;

constr_array_type : ARRAY iter_index_constraint OF component_subtype_def
	;

component_subtype_def : aliased_opt subtype_ind
	;

aliased_opt : %empty 
	| ALIASED
	;

index_s : index
	| index_s ',' index
	;

index : name RANGE BOX
	;

iter_index_constraint : '(' iter_discrete_range_s ')'
	;

iter_discrete_range_s : discrete_range
	| iter_discrete_range_s ',' discrete_range
	;

discrete_range : name range_constr_opt
	| range
	;

range_constr_opt : %empty
	| range_constraint
	;

record_type : tagged_opt limited_opt record_def
	;

record_def : RECORD pragma_s comp_list END RECORD
	| NuLL RECORD
	;

tagged_opt : %empty
	| TAGGED
	| ABSTRACT TAGGED
	;

comp_list : comp_decl_s variant_part_opt
	| variant_part pragma_s
	| NuLL ';' pragma_s
	;

comp_decl_s : comp_decl
	| comp_decl_s pragma_s comp_decl
	;

variant_part_opt : pragma_s
	| pragma_s variant_part pragma_s
	;

comp_decl : def_id_s ':' component_subtype_def init_opt ';'
	| error ';'
	;

discrim_part : '(' discrim_spec_s ')'
	;

discrim_spec_s : discrim_spec
	| discrim_spec_s ';' discrim_spec
	;

discrim_spec : def_id_s ':' access_opt mark init_opt
	| error
	;

access_opt : %empty
	| ACCESS
	;

variant_part : CASE simple_name IS pragma_s variant_s END CASE ';'
	;

variant_s : variant
	| variant_s variant
	;

variant : WHEN choice_s RIGHT_SHAFT pragma_s comp_list
	;

choice_s : choice
	| choice_s '|' choice
	;

choice : expression
	| discrete_with_range
	| OTHERS
	;

discrete_with_range : name range_constraint
	| range
	;

access_type : ACCESS subtype_ind
	| ACCESS CONSTANT subtype_ind
	| ACCESS ALL subtype_ind
	| ACCESS prot_opt PROCEDURE formal_part_opt
	| ACCESS prot_opt FUNCTION formal_part_opt RETURN mark
	;

prot_opt : %empty
	| PROTECTED
	;

decl_part :%empty
	| decl_item_or_body_s1
	;

decl_item_s : %empty 
	| decl_item_s1
	;

decl_item_s1 : decl_item
	| decl_item_s1 decl_item
	;

decl_item : decl
	| use_clause
	| rep_spec
	| pragma
	;

decl_item_or_body_s1 : decl_item_or_body
	| decl_item_or_body_s1 decl_item_or_body
	;

decl_item_or_body : body
	| decl_item
	;

body : subprog_body
	| pkg_body
	| task_body
	| prot_body
	;

name : simple_name
	| indexed_comp
	| selected_comp
	| attribute
	| operator_symbol
	;

mark : simple_name
	| mark TIC attribute_id
	| mark '.' simple_name
	;

simple_name : identifier
	;

compound_name : simple_name
	| compound_name '.' simple_name
	;

c_name_list : compound_name
	 | c_name_list ',' compound_name
	;

used_char : char_lit
	;

operator_symbol : char_string
	;

indexed_comp : name '(' value_s ')'
	;

value_s : value
	| value_s ',' value
	;

value : expression
	| comp_assoc
	| discrete_with_range
	| error
	;

selected_comp : name '.' simple_name
	| name '.' used_char
	| name '.' operator_symbol
	| name '.' ALL
	;

attribute : name TIC attribute_id
	;

attribute_id : identifier
	| DIGITS
	| DELTA
	| ACCESS
	;

literal : numeric_lit
	| used_char
	| NuLL
	;

aggregate : '(' comp_assoc ')'
	| '(' value_s_2 ')'
	| '(' expression WITH value_s ')'
	| '(' expression WITH NuLL RECORD ')'
	| '(' NuLL RECORD ')'
	;

value_s_2 : value ',' value
	| value_s_2 ',' value
	;

comp_assoc : choice_s RIGHT_SHAFT expression
	;

expression : relation
	| expression logical relation
	| expression short_circuit relation
	;

logical : AND
	| OR
	| XOR
	;

short_circuit : AND THEN
	| OR ELSE
	;

relation : simple_expression
	| simple_expression relational simple_expression
	| simple_expression membership range
	| simple_expression membership name
	;

relational : '='
	| NE
	| '<'
	| LT_EQ
	| '>'
	| GE
	;

membership : IN
	| NOT IN
	;

simple_expression : unary term
	| term
	| simple_expression adding term
	;

unary   : '+'
	| '-'
	;

adding  : '+'
	| '-'
	| '&'
	;

term    : factor
	| term multiplying factor
	;

multiplying : '*'
	| '/'
	| MOD
	| REM
	;

factor : primary
	| NOT primary
	| ABS primary
	| primary EXPON primary
	;

primary : literal
	| name
	| allocator
	| qualified
	| parenthesized_primary
	;

parenthesized_primary : aggregate
	| '(' expression ')'
	;

qualified : name TIC parenthesized_primary
	;

allocator : NEW name
	| NEW qualified
	;

statement_s : statement
	| statement_s statement
	;

statement : unlabeled
	| label statement
	;

unlabeled : simple_stmt
	| compound_stmt
	| pragma
	;

simple_stmt : null_stmt
	| assign_stmt
	| exit_stmt
	| return_stmt
	| goto_stmt
	| procedure_call
	| delay_stmt
	| abort_stmt
	| raise_stmt
	| code_stmt
	| requeue_stmt
	| error ';'
	;

compound_stmt : if_stmt
	| case_stmt
	| loop_stmt
	| block
	| accept_stmt
	| select_stmt
	;

label : LT_LT identifier GT_GT
	;

null_stmt : NuLL ';'
	;

assign_stmt : name IS_ASSIGNED expression ';'
	;

if_stmt : IF cond_clause_s else_opt END IF ';'
	;

cond_clause_s : cond_clause
	| cond_clause_s ELSIF cond_clause
	;

cond_clause : cond_part statement_s
	;

cond_part : condition THEN
	;

condition : expression
	;

else_opt : %empty
	| ELSE statement_s
	;

case_stmt : case_hdr pragma_s alternative_s END CASE ';'
	;

case_hdr : CASE expression IS
	;

alternative_s : %empty
	| alternative_s alternative
	;

alternative : WHEN choice_s RIGHT_SHAFT statement_s
	;

loop_stmt : label_opt iteration basic_loop id_opt ';'
	;

label_opt : %empty
	| identifier ':'
	;

iteration : %empty
	| WHILE condition
	| iter_part reverse_opt discrete_range
	;

iter_part : FOR identifier IN
	;

reverse_opt : %empty
	| REVERSE
	;

basic_loop : LOOP statement_s END LOOP
	;

id_opt : %empty
	| designator
	;

block : label_opt block_decl block_body END id_opt ';'
	;

block_decl : %empty
	| DECLARE decl_part
	;

block_body : BEGiN handled_stmt_s
	;

handled_stmt_s : statement_s except_handler_part_opt 
	; 

except_handler_part_opt : %empty
	| except_handler_part
	;

exit_stmt : EXIT name_opt when_opt ';'
	;

name_opt : %empty
	| name
	;

when_opt : %empty
	| WHEN condition
	;

return_stmt : RETURN ';'
	| RETURN expression ';'
	;

goto_stmt : GOTO name ';'
	;

subprog_decl : subprog_spec ';'
	| generic_subp_inst ';'
	| subprog_spec_is_push ABSTRACT ';'
	;

subprog_spec : PROCEDURE compound_name formal_part_opt
	| FUNCTION designator formal_part_opt RETURN name
	| FUNCTION designator  /* for generic inst and generic rename */
	;

designator : compound_name
	| char_string
	;

formal_part_opt : %empty 
	| formal_part
	;

formal_part : '(' param_s ')'
	;

param_s : param
	| param_s ';' param
	;

param : def_id_s ':' mode mark init_opt
	| error
	;

mode : %empty
	| IN
	| OUT
	| IN OUT
	| ACCESS
	;

subprog_spec_is_push : subprog_spec IS
	;

subprog_body : subprog_spec_is_push
	       decl_part block_body END id_opt ';'
	;

procedure_call : name ';'
	;

pkg_decl : pkg_spec ';'
	| generic_pkg_inst ';'
	;

pkg_spec : PACKAGE compound_name IS 
	     decl_item_s private_part END c_id_opt
	;

private_part : %empty
	| PRIVATE decl_item_s
	;

c_id_opt : %empty 
	| compound_name
	;

pkg_body : PACKAGE BODY compound_name IS
	       decl_part body_opt END c_id_opt ';'
	;

body_opt : %empty
	| block_body
	;

private_type : tagged_opt limited_opt PRIVATE
	;

limited_opt : %empty
	| LIMITED
	;

use_clause : USE name_s ';'
	| USE TYPE name_s ';'
	;

name_s : name
	| name_s ',' name
	;

rename_decl : def_id_s ':' object_qualifier_opt subtype_ind renames ';'
	| def_id_s ':' EXCEPTION renames ';'
	| rename_unit
	;

rename_unit : PACKAGE compound_name renames ';'
	| subprog_spec renames ';'
	| generic_formal_part PACKAGE compound_name renames ';'
	| generic_formal_part subprog_spec renames ';'
	;

renames : RENAMES name
	;

task_decl : task_spec ';'
	;

task_spec : TASK simple_name task_def
	| TASK TYPE simple_name discrim_part_opt task_def
	;

task_def : %empty
	| IS entry_decl_s rep_spec_s task_private_opt END id_opt
	;

task_private_opt : %empty
	| PRIVATE entry_decl_s rep_spec_s
	;

task_body : TASK BODY simple_name IS
	       decl_part block_body END id_opt ';'
	;

prot_decl : prot_spec ';'
	;

prot_spec : PROTECTED identifier prot_def
	| PROTECTED TYPE simple_name discrim_part_opt prot_def
	;

prot_def : IS prot_op_decl_s prot_private_opt END id_opt
	;

prot_private_opt : %empty
	| PRIVATE prot_elem_decl_s 


prot_op_decl_s : %empty 
	| prot_op_decl_s prot_op_decl
	;

prot_op_decl : entry_decl
	| subprog_spec ';'
	| rep_spec
	| pragma
	;

prot_elem_decl_s : %empty 
	| prot_elem_decl_s prot_elem_decl
	;

prot_elem_decl : prot_op_decl | comp_decl ;

prot_body : PROTECTED BODY simple_name IS
	       prot_op_body_s END id_opt ';'
	;

prot_op_body_s : pragma_s
	| prot_op_body_s prot_op_body pragma_s
	;

prot_op_body : entry_body
	| subprog_body
	| subprog_spec ';'
	;

entry_decl_s : pragma_s
	| entry_decl_s entry_decl pragma_s
	;

entry_decl : ENTRY identifier formal_part_opt ';'
	| ENTRY identifier '(' discrete_range ')' formal_part_opt ';'
	;

entry_body : ENTRY identifier formal_part_opt WHEN condition entry_body_part
	| ENTRY identifier '(' iter_part discrete_range ')' 
		formal_part_opt WHEN condition entry_body_part
	;

entry_body_part : ';'
	| IS decl_part block_body END id_opt ';'
	;

rep_spec_s : %empty
	| rep_spec_s rep_spec pragma_s
	;

entry_call : procedure_call
	;

accept_stmt : accept_hdr ';'
	| accept_hdr DO handled_stmt_s END id_opt ';'
	;

accept_hdr : ACCEPT entry_name formal_part_opt
	;

entry_name : simple_name
	| entry_name '(' expression ')'
	;

delay_stmt : DELAY expression ';'
	| DELAY UNTIL expression ';'
	;

select_stmt : select_wait
	| async_select
	| timed_entry_call
	| cond_entry_call
	;

select_wait : SELECT guarded_select_alt or_select else_opt
	      END SELECT ';'
	;

guarded_select_alt : select_alt
	| WHEN condition RIGHT_SHAFT select_alt
	;

or_select : %empty
	| or_select OR guarded_select_alt
	;

select_alt : accept_stmt stmts_opt
	| delay_stmt stmts_opt
	| TERMINATE ';'
	;

delay_or_entry_alt : delay_stmt stmts_opt
	| entry_call stmts_opt

async_select : SELECT delay_or_entry_alt
	       THEN ABORT statement_s
	       END SELECT ';'
	;

timed_entry_call : SELECT entry_call stmts_opt 
		   OR delay_stmt stmts_opt
	           END SELECT ';'
	;

cond_entry_call : SELECT entry_call stmts_opt 
		  ELSE statement_s
	          END SELECT ';'
	;

stmts_opt : %empty
	| statement_s
	;

abort_stmt : ABORT name_s ';'
	;

compilation : %empty
	| compilation comp_unit
	| pragma pragma_s
	;

comp_unit : context_spec private_opt unit pragma_s
	| private_opt unit pragma_s
	;

private_opt : %empty
	| PRIVATE
	;

context_spec : with_clause use_clause_opt
	| context_spec with_clause use_clause_opt
	| context_spec pragma
	;

with_clause : WITH c_name_list ';'
	;

use_clause_opt : %empty
	| use_clause_opt use_clause
	;

unit : pkg_decl
	| pkg_body
	| subprog_decl
	| subprog_body
	| subunit
	| generic_decl
	| rename_unit
	;

subunit : SEPARATE '(' compound_name ')'
	      subunit_body
	;

subunit_body : subprog_body
	| pkg_body
	| task_body
	| prot_body
	;

body_stub : TASK BODY simple_name IS SEPARATE ';'
	| PACKAGE BODY compound_name IS SEPARATE ';'
	| subprog_spec IS SEPARATE ';'
	| PROTECTED BODY simple_name IS SEPARATE ';'
	;

exception_decl : def_id_s ':' EXCEPTION ';'
	;

except_handler_part : EXCEPTION exception_handler
	| except_handler_part exception_handler
	;

exception_handler : WHEN except_choice_s RIGHT_SHAFT statement_s
	| WHEN identifier ':' except_choice_s RIGHT_SHAFT statement_s
	;

except_choice_s : except_choice
	| except_choice_s '|' except_choice
	;

except_choice : name
	| OTHERS
	;

raise_stmt : RAISE name_opt ';'
	;

requeue_stmt : REQUEUE name ';'
	| REQUEUE name WITH ABORT ';'
	;

generic_decl : generic_formal_part subprog_spec ';'
	| generic_formal_part pkg_spec ';'
	;

generic_formal_part : GENERIC
	| generic_formal_part generic_formal
	;

generic_formal : param ';'
	| TYPE simple_name generic_discrim_part_opt IS generic_type_def ';'
	| WITH PROCEDURE simple_name 
	    formal_part_opt subp_default ';'
	| WITH FUNCTION designator 
	    formal_part_opt RETURN name subp_default ';'
	| WITH PACKAGE simple_name IS NEW name '(' BOX ')' ';'
	| WITH PACKAGE simple_name IS NEW name ';'
	| use_clause
	;

generic_discrim_part_opt : %empty
	| discrim_part
	| '(' BOX ')'
	;

subp_default : %empty
	| IS name
	| IS BOX
	;

generic_type_def : '(' BOX ')'
	| RANGE BOX
	| MOD BOX
	| DELTA BOX
	| DELTA BOX DIGITS BOX
	| DIGITS BOX
	| array_type
	| access_type
	| private_type
	| generic_derived_type
	;

generic_derived_type : NEW subtype_ind
	| NEW subtype_ind WITH PRIVATE
	| ABSTRACT NEW subtype_ind WITH PRIVATE
	;

generic_subp_inst : subprog_spec IS generic_inst
	;

generic_pkg_inst : PACKAGE compound_name IS generic_inst
	;

generic_inst : NEW name
	;

rep_spec : attrib_def
	| record_type_spec
	| address_spec
	;

attrib_def : FOR mark USE expression ';'
	;

record_type_spec : FOR mark USE RECORD align_opt comp_loc_s END RECORD ';'
	;

align_opt : %empty
	| AT MOD expression ';'
	;

comp_loc_s : %empty
	| comp_loc_s mark AT expression RANGE range ';'
	;

address_spec : FOR mark USE AT expression ';'
	;

code_stmt : qualified ';'
	;

%%