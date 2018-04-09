/**
 * rc.c -- функции для удаления текущей строки
 *
 * Copyright (c) 2017,  Denis Ermolin <dermolin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"
#include "text.h"

/**
 *
 * Удаляет текущую строку
 *
 * @param txt текст
 * @returns код ошибки
 */
int rc(text txt)
{
  /* Если есть только одна строчка, удаляем весь текст */
  if (txt->length == 1) {
      remove_all(txt);
      return 0;
  }

    node *line = txt->cursor->line;

    /* Устанавливаем курсор в начало предыдущей строки или начало следующей */
    if (line != txt->end) {
        txt->cursor->line = txt->cursor->line->next;
        txt->cursor->position = 0;
    } else {
        txt->cursor->line = txt->cursor->line->previous;
        txt->cursor->position = 0;
    }
    /* Удаляем строку */
    if (line == txt->end) {
        txt->end = txt->end->previous;
        txt->end->next = NULL;
    } else if (line == txt->begin) {
        txt->begin = txt->begin->next;
        txt->begin->previous = NULL;
    } else {
        line->next->previous = line->previous;
        line->previous->next = line->next;
    }
    txt->length--;
    return 0;
}
