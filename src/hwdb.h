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

typedef enum {
    LLX_GVA_HWDB_DESKTOP = 0,
    LLX_GVA_HWDB_LAPTOP
} llx_gva_hwdb_format_t;

typedef struct {
    uint64_t hash;
    char* what;
    llx_gva_hwdb_format_t format;
    char* vendor;
    char* system;
} llx_gva_hwdb_t;

llx_gva_hwdb_t llx_gva_hwdb [] = { 
       /* {2947799435940071112U,"TST1",LLX_GVA_HWDB_DESKTOP,"",""}, */
        {4071682124959178180U,"OR62",LLX_GVA_HWDB_DESKTOP,"Investronica","MS-7210"},
        {12035700818783202010U,"PRJ1",LLX_GVA_HWDB_LAPTOP,"HP","HP ProBook 440 G6 (4RZ48AV)"},
        {2105838388923405639U,"ORJ2",LLX_GVA_HWDB_DESKTOP,"TEKNOSERVICE","TTL-TEKNOSLIM (ASUS_MB_CNL)"},
        {9504963959125139900U,"_ASUS_",LLX_GVA_HWDB_LAPTOP,"ASUSTeK COMPUTER INC.","ASUS BR1100FKA BR1100FKA_BR1100FKA"},
        {15811257294219722714U,"_LENOVO_",LLX_GVA_HWDB_LAPTOP,"LENOVO","82J1"},
        {17814104592024589437U,"_ACER_",LLX_GVA_HWDB_LAPTOP,"Acer","TravelMate P214-41-G3"},
        {1,"_IDEAPAD_",LLX_GVA_HWDB_LAPTOP,"LENOVO","20269"},
        {0,0,0,0,0}
};
