/**
 * rc.c -- Функция, удаляющая первую непустую строку
 *
 * Copyright (c) 2017,  Denis Korolevskiy <korolevs@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"
#include "text.h"


int r1ne(text txt)
{

    /* Ищем указатель на первую непустую строку */
    int i, len, found = 0;
    node *line = txt->begin;

    /* Цикл по строкам */
    while(line->next != NULL){
	len = (signed)strlen(line->contents) - 1;

	/* Цикл по символам, ищет в непустой строке символы кроме пробела */
	for(i = 0; i < len; i++)
	    if(line->contents[i] != ' '){
		break;
	    }

	if(i < len && len != 0){
	    found =1;
	    break;
	}else
	    line = line->next;
    }


    /* Если непустых строк нет, выход с сообщением об ошибке*/
    if(found == 0) {
	fprintf(stderr,"Non-emplty lines not found.\n");
	return 1;
    }

    /* Если строка в файле всего одна, удаляем весь файл, иначе передвигаем курсор на найденную строку */
    if (txt->length == 1){
	remove_all(txt);
	return 0;
    }else txt->cursor->line = line;

    
    /* Устанавливаем курсор в начало предыдущей строки или начало следующей, одна из них точно существует */
    if (line != txt->end) {
        txt->cursor->line = txt->cursor->line->next;
        txt->cursor->position = 0;
    } else {
        txt->cursor->line = txt->cursor->line->previous;
        txt->cursor->position = 0;
    }
    
    /* Удаляем строку меняя указатели и освобождая память */
    if (line == txt->begin) {
        txt->begin = txt->begin->next;
        txt->begin->previous = NULL;
    } else if (line == txt->end) {
        txt->end = txt->end->previous;
        txt->end->next = NULL;
    } else {
        line->next->previous = line->previous;
        line->previous->next = line->next;
    }

    free (line);

    /* Уменьшаем сохраненный размер файла */
    txt->length--;
    return 0;
}
