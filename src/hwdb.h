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

#include <stdint.h>

typedef struct {
    uint64_t hash;
    char* what;
    uint32_t format;
} llx_gva_hwdb_t;

llx_gva_hwdb_t llx_gva_hwdb [] = { 
        {2947799435940071112,"TST1",0}, /* Test entry */
        {4071682124959178180,"OR62",0}, /* Investronica, MS-7210 */
        {0,0,0}
};
