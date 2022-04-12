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

#include <smbios_c/smbios.h>
#include <smbios_c/system_info.h>

#include <string.h>
#include <stdint.h>
#include <stdio.h>

char buffer[LLX_GVA_HWDB_MAX_BUFFER];

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

char* llx_gva_hwdb_get_vendor()
{
    char* tmp = sysinfo_get_vendor_name();
    
    if (tmp) {
        strcpy(buffer,tmp);
        sysinfo_string_free(tmp);
    }
    else {
        buffer[0] = 0;
    }
    
    return buffer;
}

char* llx_gva_hwdb_get_system()
{
    char* tmp = sysinfo_get_system_name();
    
    if (tmp) {
        strcpy(buffer,tmp);
        sysinfo_string_free(tmp);
    }
    else {
        buffer[0] = 0;
    }
    
    return buffer;
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
    buffer[0] = 0;
    
    uint64_t me = llx_gva_hwdb_get_hash();
    
    llx_gva_hwdb_t* info=llx_gva_hwdb;
    
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
