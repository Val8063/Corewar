/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** op.h
*/

#ifndef _OP_H_
    #define _OP_H_
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <string.h>
    #include <stdint.h>
    #include <unistd.h>
    #include <stdbool.h>

    #define MEM_SIZE (6 * 1024)
    #define IDX_MOD 512 /* modulo of the index < */
    #define MAX_ARGS_NUMBER 4 /* this may not be changed 2^*IND_SIZE */

    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','
    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"

/*
** regs
*/
    #define REG_NUMBER 16 /* r1 <--> rx */

typedef char args_type_t;

    #define T_REG 1 /* register */
    #define T_DIR 2 /* direct  (ld  #1,r1  put 1 into r1) */
    #define T_IND 4
/*
indirect always relative (ld 1,r1 put what's in the address(1+pc) into r1
(4 bytes ))
*/
    #define T_LAB 8 /* LABEL */

/*
** size (in bytes)
*/
    #define DIR_SIZE 4
    #define IND_SIZE 2
    #define REG_SIZE 1

/*
** header
*/
    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define COREWAR_EXEC_MAGIC 0xea83f3

/*
** live
*/
    #define CYCLE_TO_DIE 1536 /* number of cycle before beig declared dead */
    #define CYCLE_DELTA 5
    #define NBR_LIVE 40

/*
** Project macro
*/
    #define MAX_CHAMPIONS 4
    #define ARGS_SKIP 1

#endif
