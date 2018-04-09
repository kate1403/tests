/**
 * shownonempty.c -- реализует команду вывода хранимого текста на экран
 *                   в прямом порядке следования строк, кроме пустых строк
 *
 * Copyright (c) 2017, Denis Ermolin <dermolin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, char *contents);

/**
 * Выводит содержимое указанного файла на экран, без учета пустых строк
 */
void shownonempty(text txt)
{
    /* Вставляет курсор в текст */
    print_cursor(txt);
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line);
    /* Удаляет курсор из текста */
    remove_cursor(txt);
}

/**
 * Выводит содержимое указанного файла на экран, без учета пустых строк
 */
static void show_line(int index, char *contents)
{
    int count = 0, i, end;
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    /* Декларируем неиспользуемый параметр */
    UNUSED(index);
    /* Находим позицию символа конца строки */
    end = strchr(contents, '\0') - contents;
    /* Проверяем сколько пробельных символов находится до символа конца 
строки */
    for (i = 0; i < end; i++) {
        if (isspace(contents[i])) {
            count++;
        }
    }
    /* Выводим строку на экран, если она не пустая */
    if (strlen(contents) - count - 1) {
        printf("%s", contents);
    }
}
