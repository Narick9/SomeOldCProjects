#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
#include <string.h>

#include <math.h>
#include <time.h>

#include "my_lib.h"

/* -----------------------------STRUCTS----------------------------- */

// Field
void CreateField(Field* _buffer, int _map_x, int _map_y)
{
    int map_x = 20;
    int map_y = 8;
    _buffer->map_x = map_x;
    _buffer->map_y = map_y;
    _buffer->field = malloc(sizeof(size_t) * map_x);
    if (_buffer->field == NULL)     
        error_msg("Failed to get memory");

    for (int x = 0; x < map_x; x++) {
        _buffer->field[x] = malloc(sizeof(char) * map_y);
        if (_buffer->field[x] == NULL)
            error_msg("Failed to get memory");
    }
}
void DestroyField(Field* _buffer)
{
    for (int x = 0; x < _buffer->map_x; x++)
        free(_buffer->field[x]);
    free(_buffer);
}
void FieldClear(Field* _buffer)
{
    for (int y = 0; y < _buffer->map_y; y++)
        for (int x = 0; x < _buffer->map_x; x++)
            _buffer->field[x][y] = ' ';
}
void FieldShow(Field _setts)
{
    for (int y = 0; y < _setts.map_y; y++) {
        for (int x = 0; x < _setts.map_x; x++)
            printf("%c", _setts.field[x][y]);
        printf("\n");
    }
}

// Cell
Cell CreateCell(int _x, int _y, char _picture)
{
    Cell main;
    main.x = _x;
    main.y = _y;
    main.picture = _picture;
}

/* -----------------------------OTHER----------------------------- */

void error_msg(const char* _msg)
{
    fprintf(stderr, "ERROR\t %s: %s\n", _msg, strerror(errno));
	exit(errno);
}

void delay(unsigned int _douration)
{
    clock_t end;
    if ( (end = clock()) == -1 )
        error_msg("clock() failed");
    end += _douration;
    while (clock() < end);  // actually here's delay
}

/* -----------------------------INT/STR/CHAR----------------------------- */

int str_to_int(const char* _str)
{
    int n = 0;      // our number
    short sign = 1; // sign of number
    size_t size = strlen(_str);

    short cycle = 1;
    for (int i = 0, rank = size - 1;    i < size && cycle;   i++, rank--) { // size-1 units is already here
        unsigned int factor = pow(10, rank);
        switch (_str[i]) {
            case '-':
                if (i == 0)
                    sign = -1;
                else
                    cycle = 0;  // break cycle
                break;
            case '0':   break;
            case '1':   n += 1*factor;  break;
            case '2':   n += 2*factor;  break;
            case '3':   n += 3*factor;  break;
            case '4':   n += 4*factor;  break;
            case '5':   n += 5*factor;  break;
            case '6':   n += 6*factor;  break;
            case '7':   n += 7*factor;  break;
            case '8':   n += 8*factor;  break;
            case '9':   n += 9*factor;  break;
            default:    cycle = 0;
        }
    }
    n *= sign;  // add our sign

    return n;
}