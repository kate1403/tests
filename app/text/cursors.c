/**
 * cursor.c -- реализует основные функции курсора
 *
 * Copyright (c) 2017, Vladislav Klimenko <klimenko@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Возвращает позицию курсора
 * 
 * @param txt текст
 * @returns позицию курсора
 */
int pos_return(text txt)
{
    return txt -> cursor -> position;
}


/**
 * Возвращает строку курсора
 * 
 * @param txt текст
 * @returns строку курсора
 */
node *line_return(text txt)
{
    return txt -> cursor -> line;
}

/**
 * Поставить курсор в линию line на позицию pos
 * @param txt текст
 * @param _line номер строки
 * @param pos позиция в строке
 * @returns код ошибки
 */
int c_to_pos(text txt, int _line, int pos){
    /* Если текста нет */
    if(txt -> begin == NULL) return 3;
    node *line = tracer(txt, _line);
    /* Если tracer не сработал */    
    if(line == NULL) return 1;
    /* Выход за пределы строки */
    if((pos > (signed)strlen(line -> contents)) || (pos < 0)) return 2;
    txt -> cursor -> line = line;
    txt -> cursor -> position = pos;
    return 0;
}

/**
 * Вставляем в текст курсор
 *
 * @param txt текст
 * @returns none
 *
 */
void print_cursor(text txt){
    int i;
    node *line = txt->cursor->line;
    /* Сдвиг части строки за курсором вправо */
    for(i = strlen(line->contents); i > txt->cursor->position; i--)
		line->contents[i]= line->contents[i - 1];

    (line->contents)[txt->cursor->position]='|';
}

/**
 * Удаляем курсор из текста
 * 
 * @param txt текст
 * @returns none
 *
 */
void remove_cursor(text txt){
    int i;
    node *line = txt->cursor->line;
    /* Сдвиг строки за курсором влево */
    for(i = txt->cursor->position; i < (signed)strlen(line->contents); i++)
	line->contents[i]= line->contents[i + 1];
}

/**
 * Перенос курсора в начало следующего слова
 * @param txt текст
 * @param _line номер строки
 * @param pos позиция в строке
 * @returns none
 */
void mnwbf(text txt){
    int i;
    node *line = txt->cursor->line;
    for(i = txt->cursor->position; i < (signed)strlen(line->contents)-1;i++)
       if((line->contents[i] == ' ') || (line->contents[i+1] != ' ')){
           txt->cursor->position=i + 1; 
           break;
       }
}

/**
 * Перенос курсора вправо
 * @param txt текст
 * @returns none
 */
void mcf(text txt)
{

    /*Если возможно, то переместить курсор вправо */
    if(txt->cursor->position+1<(signed)strlen(txt->cursor->line->contents))
	txt->cursor->position++;

}

/**
 * Поменять данными текщкю строку и строку y
 * @param txt текст
 * @param _line номер строки
 * @param pos позиция в строке
 * @returns код ошибки
 */
void ystring(char* y,text txt){
    int c;
    int i;
   /*Считаем длину строки от а до конца строки*/
    c = strlen(txt->cursor->line->contents) - pos_return(txt);
     /*Сравниваем длины срок y и contents и ставим y на место contents */
    if((signed)strlen(y)<=c){
	for(i = pos_return(txt); i < (signed)strlen(y); i++)
 	txt->cursor->line->contents[pos_return(txt) + i] = y[i];
	}
	else fprintf(stderr, "Замена невозможна\n");
 }
