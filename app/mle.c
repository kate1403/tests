/**
 * mplb.c -- переводит курсор на начало предыдущей строки
 *
 * Copyright (c) 2017, Denis Korolevskiy <korolevs@petrsu.ru>
 *
 * This code is licensed under a MIT-stile license.
 */
#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include "text/_text.h"
/**
 * Перенос курсора в конец текущей строки
 * @param txt текст
 * @returns none
*/
void mle(text txt)
{
    txt->cursor->position = (signed)strlen(txt->cursor->line->contents) - 1;
}
