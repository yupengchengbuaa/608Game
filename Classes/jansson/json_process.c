/*
 * Copyright (c) 2009-2012 Petri Lehtinen <petri@digip.org>
 *
 * Jansson is free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jansson.h"

#if HAVE_LOCALE_H
#include <locale.h>
#endif

#if _WIN32
#include <io.h>  /* for _setmode() */
#include <fcntl.h>  /* for _O_BINARY */
#endif

#define l_isspace(c) ((c) == ' ' || (c) == '\n' || (c) == '\r' || (c) == '\t')

static int getenv_int(const char *name)
{
    char *value, *end;
    long result;

    value = getenv(name);
    if(!value)
        return 0;

    result = strtol(value, &end, 10);
    if(*end != '\0')
        return 0;

    return (int)result;
}

/* Return a pointer to the first non-whitespace character of str.
   Modifies str so that all trailing whitespace characters are
   replaced by '\0'. */
static const char *strip(char *str)
{
    size_t length;
    char *result = str;
    while(*result && l_isspace(*result))
        result++;

    length = strlen(result);
    if(length == 0)
        return result;

    while(l_isspace(result[length - 1]))
        result[--length] = '\0';

    return result;
}

