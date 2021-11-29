/*
    This file is part of lliurex-gva-hwdb

    Copyright (C) 2021  Enrique Medina Gremaldos <quiqueiii@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef LLIUREX_GVA_HWDB
#define LLIUREX_GVA_HWDB

#include "hwdb.h"

#include <stdint.h>

/*!
* returns system vendor name or empty string if name can not be retrieved
* dont free the pointer
*/
char* llx_gva_hwdb_get_vendor();

/*!
* returns system name or empty string if name can not be retrieved
* dont free the pointer
*/
char* llx_gva_hwdb_get_system();

/*!
* returns current system hash
*/
uint64_t llx_gva_hwdb_get_hash();

/*!
* returns hash for given string
*/
uint64_t llx_gva_hwdb_compute_hash(char* digest);

/*!
* returns guessed system or empty string if error
* dont free the pointer
*/
char* llx_gva_hwdb_what();

/*!
* returns entry db to guessed system or null if fails to guess it
* dont free the pointer
*/
llx_gva_hwdb_t* llx_gva_hwdb_what_db();

#endif
