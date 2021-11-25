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
#include <string.h>

void show_help()
{
    fprintf(stderr,"LliureX GVA hardware database tool\n\n");
    fprintf(stderr,"Available commands:\n");
    fprintf(stderr,"what\t\tGuesses what gva model this system is\n");
    fprintf(stderr,"is MODEL\tChecks if current system matches given MODEL name\n");
    fprintf(stderr,"info\t\tDumps system info\n");
}

int main(int argc,char* argv[])
{
    if (argc<2) {
        show_help();
        return -1;
    }
    
    if (strcmp(argv[1],"info") == 0) {
        printf("vendor: \"%s\"\n",llx_gva_hwdb_get_vendor());
        printf("system: \"%s\"\n",llx_gva_hwdb_get_system());
        const char* what = llx_gva_hwdb_what();
        if (strlen(what) == 0) {
            printf("what: \"UNKNOWN\"\n");
        }
        else {
            printf("what: \"%s\"\n",what);
        }
        
        return 0;
    }
    
    if (strcmp(argv[1],"what") == 0) {
        const char* what = llx_gva_hwdb_what();
        if (strlen(what) == 0) {
            printf("UNKNOWN\n");
            return -2;
        }
        else {
            printf("%s\n",what);
            return 0;
        }
    }
    
    if (strcmp(argv[1],"is") == 0 && argc>2) {
        const char* what = llx_gva_hwdb_what();
        
        if (strcmp(what,argv[2]) == 0) {
            return 0;
        }
        else {
            return -3;
        }
    }
    
    if (strcmp(argv[1],"compute-hash") == 0 && argc>2) {
        uint64_t hash = llx_gva_hwdb_compute_hash(argv[2]);
        printf("%ld\n",hash);
        
        return 0;
    }
    
    show_help();
    
    return -1;
}
