/**
 * mwbb.c -- реализует перемещение курсора в начало текущего слова,
 * если это возможно
 *
 * Copyright (c) 2017, Denis Ermolin <dermolin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <ctype.h>
#include "_text.h"

/**
 * Перемещаем курсор в начало слова
 *
 * @param txt текст
 * @returns none
 *
 */
void mwbb(text txt)
{
    /* Создаем указатель на ктроку с курсором */
    char *current = txt->cursor->line->contents;
    int pos = txt->cursor->position;
    /* Если курсор уже в начале слова */
    if ((((!isalpha(current[pos - 1]))) > 0 || pos - 1 == -1)
        && isalpha(current[pos + 1]) > 0) {
        return;
        /* Перемещаем курсор */
    } else {
        while (isalpha(current[pos - 1])) {
            pos--;
        }
        txt->cursor->position = pos;
    }
}
