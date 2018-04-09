/**
 * pp.c -- вставка новой строки перед предыдущей
 *
 * Copyright (c) 2017,  Vlad Markov <markov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */
#include <stdio.h>
#include "common.h"
#include "text/text.h"
#include "text/_text.h"

void pp(text txt) {

    char bar[MAXLINE + 1];
    
    /* Сохраняем позицию курсора */
    int old_pos = txt->cursor->position;
    node* old_line = txt->cursor->line;
    node* previous_line = txt->cursor->line->previous;
    
    /* Сохраняем позицию последней строки */
    node* penultimate = txt->end;
    
    /* Добавляем новую строку*/
    fgets(bar, MAXLINE, stdin);
    append_line(txt, bar);
    /* Ставим новую строку между предыдущей и текущей */
    if(txt->begin == old_line){
	txt->end->next = txt->begin;
	txt->begin->previous = txt->end;
	txt->begin = txt->end;
	txt->begin->previous = NULL;
	
	txt->end = penultimate;
	txt->end->next = NULL;
    }
    else{
	previous_line->next = txt->cursor->line;
	txt->cursor->line->next = old_line;
	txt->cursor->line->previous = previous_line;
	old_line->previous = txt->cursor->line;
	
	txt->end = penultimate;
	txt->end->next = NULL;
    }
  /* Возвращаем курсор на место*/
  txt->cursor->line = old_line;
  txt->cursor->position = old_pos;
}
