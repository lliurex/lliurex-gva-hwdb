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

#include "libllxgvahwdb.h"

#include <stdio.h>

int main(int argc,char* argv[])
{
    
    printf("%s\n",llx_gva_hwdb_get_vendor());
    printf("%s\n",llx_gva_hwdb_get_system());
    printf("%lu\n",llx_gva_hwdb_get_hash());
    printf("What: %s\n",llx_gva_hwdb_what());
    
    return 0;
}
