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
    char* what;
    llx_gva_hwdb_format_t format;
    char* vendor;
    char* system;
} llx_gva_hwdb_t;

llx_gva_hwdb_t llx_gva_hwdb [] = { 
       /* {"TST1",LLX_GVA_HWDB_DESKTOP,"",""}, */
        {"OR62",LLX_GVA_HWDB_DESKTOP,"Investronica","MS-7210"},
        {"PRJ1",LLX_GVA_HWDB_LAPTOP,"HP","HP ProBook 440 G6 (4RZ48AV)"},
        {"ORJ2",LLX_GVA_HWDB_DESKTOP,"TEKNOSERVICE","TTL-TEKNOSLIM (ASUS_MB_CNL)"}, /* where this id came from? ORI2 perhaps? */
        {"ORJ2",LLX_GVA_HWDB_DESKTOP,"TICNOVA Quality Team S.l.","E70 SFF"},
        {"ORI1",LLX_GVA_HWDB_DESKTOP,"HP","HP ProDesk 600 G4 SFF"}, //untested
        {"CLG1/CLH1",LLX_GVA_HWDB_DESKTOP,"HP","HP t730 Thin Client"}, //untested
        {"PRM1/PRM2",LLX_GVA_HWDB_LAPTOP,"Acer","TravelMate P214-54"},
        {"PRM3",LLX_GVA_HWDB_LAPTOP,"Acer","TravelMate Spin B311R-32"},
        {0,0,0,0}
};
