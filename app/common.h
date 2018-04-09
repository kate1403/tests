/**
 * common.h -- прототипы функций реализации команд редактора
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

/**
 * Выводит содержимое указанного файла на экран и нумерует
 */
void shownum(text txt);

/**
 * Сохраняет в указанный файл
 */

void save(text txt,  char *f);
/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);


/**
 * Удаляет последнюю строку
 * 
 * @param txt текст
 * @returns none
 */
void rt(text txt);

/**
 * Выводит содержимое файла на экран в обратном порядке
 */

void showrev(text txt);

/**
 * Перемещает курсор на один символ влево
 */

void mcb(text txt);

/**
 * Удаляет последнюю строку
 */

/**
 * перемещает курсор в текущей строке на заданную позицию
 */
int r_in_cur(text txt, int cpos);

/**
 * Выводит нечетные строки файла
 */
void showodd(text txt);

/**
 * объединяет строку с курсором со следующей строкой
 */
void j (text txt);


/* Удаляет строку перед текущей */
void rp(text txt);

/* Переносит курсор в начало следующего слова */
void mnwbf(text txt);

/* Выводит длину строк */
void showlengths(text txt);

void show_lengths(int index, char *contents);

/**
 * Выводит содержимое файла на экран в прямом порядке, без учета пустых строк
 */
void shownonempty(text txt);

/**
 * Перемещает курсор на начало текущего слова
 */
void mwbb(text txt);

/**
 * Удаляет текущую строку
 */
int rc(text txt);

/**
 * Сдвигает курсор вправо на 1 символ
 */
void mcf(text txt);

/**
 * Выводит строки с цифрами
 */
void showdigits(text txt);

/**
 * Удаляет первую строку
 */
void rh(text txt);

/*Перемещение текущей строки в конец текста */
void ce(text txt);

/*Замена строки от курсора и до конца заданной строкой */
void ystring(text txt);

/*Вывод буквенных символов каждой строки, которым предшествует пробельный символ */
void showwordsbeginnings(text txt);

/**
 * Выводит содержимое указанного файла на экран в порядке строк 2-1 4-3
 */
void showevenbeforeodd(text txt);
/**
 * Перемещает курсор на начало предыдущей строки
 */
void mplb(text txt);
/**
 * Вставляет новую строку перед текущей
 */
void pp(text txt);

/**
 * Выводит на экран файл, начиная слова с заглавных букв
 */
void showupfirst(text txt);

/**
 * Перемещает курсор в конец текущей строки
 */
void mle(text txt);

/**
 * Удаляет первую непустую строку
 */
void r1ne(text txt);

#endif
