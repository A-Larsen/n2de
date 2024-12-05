/* 
 * Copyright (C) 2022  Austin Larsen
 * 
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 * 
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef N2DE_DATABASE_H_
#define N2DE_DATABASE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>

#include "../config.h"
#include "./memory.h"
#include "./error.h"
#include "./files.h"
/* #include "uuid.h" */

#define SQLITE_FOREIGN 6
#define SQLITE_INTEGER_UNIQUE 7
#define SQLITE_TEXT_UNIQUE 8

#define SQLITE_MAX_STRING_SIZE 255
#define SQLITE_MAX_ROW_COUNT 20
#define SQLITE_MAX_QUERY 1024

#define DATABASE_BADSTEP(db, ret) \
    if((ret != SQLITE_DONE) && (ret != SQLITE_ROW)) { \
        N2DE_ERROR( "could not create table\n%s", \
                sqlite3_errmsg(db->sql_db)); \
        exit(1); \
    }

/* because all N2DE headers that are a direct child of the N2DE folder
 * should be able to be used outside of the use of the engine and be modular
 * I will no include respath here, but will later on
 */

typedef const char * sql_t;
typedef void (*db_columns_cb) (char *name, void *data);
typedef void (*db_getall_cb) (sqlite3_stmt *stmt, int i, int size, void *data);

typedef struct _Database {
    sqlite3 *sql_db;
    int type;
    int *data_int;
    char **data_text;
    uint16_t data_size;
} Database;

typedef struct _SchemaKV {
    char name[50];
    char foreign[50];
    int type;
} SchemaKV;

typedef struct _Schema {
    char name[50];
    SchemaKV *kv;
} Schema;

void database_insert(Database *db, char * table,  SchemaKV schema[], ...);

void database_columns(Database *db, char *table, void *data,
                      db_columns_cb callback);

void database_getManyInt(Database *db, char *table, char *row);

void database_getManyText(Database *db, char *table, char *row);

void database_init(Database *db, char *path);

bool database_checkTable(Database *db, char *table);

void database_createTable(Database *db, char * table, SchemaKV *schema);

void database_enableForeignKeys(Database *db);

void database_addForeignKeys(Database *db, char * table, SchemaKV *kv);

void database_exec(Database *db, char *sql);

int database_getColumnNames(Database *db, char *table,
                char names[SQLITE_MAX_ROW_COUNT][SQLITE_MAX_STRING_SIZE]);

void database_getAll(Database *db, char *table, db_getall_cb callback,
                     void *data);

void database_getFromUUID(Database *db, char *table, db_getall_cb callback,
                     void *data, char *uuid);

void database_getFromID(Database *db, char *table, db_getall_cb callback,
                     void *data, char *id);

void database_quit(Database *db);

#endif // N2DE_DATABASE_H_
