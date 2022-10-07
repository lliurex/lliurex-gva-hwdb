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

#include <string.h>
#include <stdint.h>
#include <stdio.h>

char buffer[LLX_GVA_HWDB_MAX_BUFFER];

static void clear_buffer()
{
    buffer[0] = 0;
}

static char* read_dmi_property(const char* what)
{
    FILE* f=NULL;
    char path[128];

    sprintf(path,"/sys/devices/virtual/dmi/id/%s",what);

    f=fopen(path,"r");
    clear_buffer();

    size_t rb = fread(buffer,1,sizeof(buffer),f);
    if (rb > 1) {
        if (buffer[rb-1] == '\n') {
            buffer[rb-1] = 0;
        }
    }

    fclose(f);

    return buffer;
}

/*
 * Based on Wolfgang Brehm code from:
 * https://stackoverflow.com/questions/7666509/hash-function-for-string
 */
static uint64_t murmur64 (const char* key)
{
  uint64_t h = 525201411107845655ull;
  
  for (;*key;++key) {
    h ^= *key;
    h *= 0x5bd1e9955bd1e995;
    h ^= h >> 47;
  }
  
  return h;
}

static int min3i(int a,int b,int c)
{
    if (a <= b && a <= c) {
        return a;
    }
    else {
        if(b <= a && b <= c) {
            return b;
        }
        else {
            if(c <= a && c <= b) {
                return c;
            }
        }
    }

    // may we land here?
    return -1;
}

/*
 Based on this:
 https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C
*/
static int levenshtein(char *s1, char *s2)
{
    unsigned int x, y, s1len, s2len;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int matrix[s2len+1][s1len+1];
    matrix[0][0] = 0;
    for (x = 1; x <= s2len; x++)
        matrix[x][0] = matrix[x-1][0] + 1;
    for (y = 1; y <= s1len; y++)
        matrix[0][y] = matrix[0][y-1] + 1;
    for (x = 1; x <= s2len; x++)
        for (y = 1; y <= s1len; y++)
            matrix[x][y] = min3i(matrix[x-1][y] + 1, matrix[x][y-1] + 1, matrix[x-1][y-1] + (s1[y-1] == s2[x-1] ? 0 : 1));

    return(matrix[s2len][s1len]);
}

char* llx_gva_hwdb_get_vendor()
{
    return read_dmi_property("sys_vendor");
}

char* llx_gva_hwdb_get_system()
{
    return read_dmi_property("product_name");
}

uint64_t llx_gva_hwdb_get_hash()
{
    char str[LLX_GVA_HWDB_MAX_BUFFER];
    size_t n=0;
    
    char* tmp = llx_gva_hwdb_get_vendor();
    n = strlen(tmp);
    strcpy(str,tmp);
    
    tmp = llx_gva_hwdb_get_system();
    strcpy(str+n,tmp);
    
    return murmur64(str);
}

uint64_t llx_gva_hwdb_compute_hash(char* digest)
{
    return murmur64(digest);
}

char* llx_gva_hwdb_what()
{
    
    uint64_t me = llx_gva_hwdb_get_hash();
    
    llx_gva_hwdb_t* info=llx_gva_hwdb;

    clear_buffer();

    while (info->hash!=0) {
        if (info->hash==me) {
            strcpy(buffer,info->what);
            break;
        }
        
        info++;
    }
    
    return buffer;
}

llx_gva_hwdb_t* llx_gva_hwdb_what_db()
{
    uint64_t me = llx_gva_hwdb_get_hash();
    
    llx_gva_hwdb_t* info=llx_gva_hwdb;
    
    while (info->hash!=0) {
        if (info->hash==me) {
            return info;
        }
        info++;
    }
    
    return NULL;
}

void test()
{
    llx_gva_hwdb_t* info=llx_gva_hwdb;
    char* vendor = llx_gva_hwdb_get_vendor();

    while (info->hash!=0) {
        int distance = levenshtein(vendor,info->vendor);

        printf("levenshtein: %d %s %s\n",distance,vendor,info->vendor);
        info++;
    }
}
