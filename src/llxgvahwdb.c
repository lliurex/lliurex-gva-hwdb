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
    fprintf(stderr,"what-format\tGuesses what gva format this system is\n");
    fprintf(stderr,"is MODEL\tChecks if current system matches given MODEL name\n");
    fprintf(stderr,"info\t\tDumps system info\n");
    fprintf(stderr,"list-db\t\tList current database\n");
}

int main(int argc,char* argv[])
{
    const char* format_names[] = {"Desktop","Laptop"};
    
    if (argc<2) {
        show_help();
        return -1;
    }
    
    if (strcmp(argv[1],"info") == 0) {
        printf("vendor: \"%s\"\n",llx_gva_hwdb_get_vendor());
        printf("system: \"%s\"\n",llx_gva_hwdb_get_system());
        llx_gva_hwdb_t* what = llx_gva_hwdb_what_db();

        if (what == 0) {
            printf("what: UNKNOWN\n");
            printf("format: UNKNOWN\n");
        }
        else {
            printf("what: %s\n",what->what);
            printf("format: %s\n",format_names[what->format]);
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
    
    if (strcmp(argv[1],"what-format") == 0) {
        llx_gva_hwdb_t* what = llx_gva_hwdb_what_db();
        if (what == 0) {
            printf("UNKNOWN\n");
            return -2;
        }
        else {
            printf("%s\n",format_names[what->format]);
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
        printf("%lu\n",hash);
        
        return 0;
    }
    
    if (strcmp(argv[1],"list-db") == 0) {
        
        llx_gva_hwdb_t* info=llx_gva_hwdb;
    
        while (info->hash!=0) {
            printf("%s %s %s %s\n",info->what,format_names[info->format],info->vendor,info->system);
            info++;
        }
        
        return 0;
    }
    
    if (strcmp(argv[1],"check-db") == 0) {
        llx_gva_hwdb_t* info=llx_gva_hwdb;
        char tmp[LLX_GVA_HWDB_MAX_BUFFER];
        size_t n = 0;

        char* status[] = {"[Ok]","[Bad checksum]"};

        while (info->hash!=0) {
            n = strlen(info->vendor);
            strcpy(tmp,info->vendor);
            strcpy(tmp+n,info->system);
            uint64_t hash = llx_gva_hwdb_compute_hash(tmp);


            printf("%s %s %s\n",info->vendor,info->system,(hash==info->hash) ? status[0] : status[1]);
            info++;
        }

        return 0;
    }

    show_help();
    
    return -1;
}
