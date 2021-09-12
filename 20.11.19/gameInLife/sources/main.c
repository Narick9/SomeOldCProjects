#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <Windows.h>

#include "my_lib.h"

typedef unsigned int uint;

void AddFrame(Field* _pBuffer, int _x, int _y)
{
    if (    _x == 0 || _x == _pBuffer->map_x - 1
        ||  _y == 0 || _y == _pBuffer->map_y - 1
        )
        _pBuffer->field[_x][_y] = '#';
}

void AddCells(Field* _pBuffer, int _x, int _y)
{
    if (!(    _x == 0 || _x == _pBuffer->map_x - 1
          ||  _y == 0 || _y == _pBuffer->map_y - 1)
        ) {
            if (rand() % 5 == 0)
                _pBuffer->field[_x][_y] = 'O';
        }
}

void Life(Field _field, Field* _pBuffer, int _x, int _y)
{
    if (!(    _x == 0 || _x == _field.map_x - 1
          ||  _y == 0 || _y == _field.map_y - 1)
        ) {
            int neighboures = 0;
            for (int lx = -1; lx < 2; lx++)
                for (int ly = -1; ly < 2; ly++) {
                    if (lx == 0 && ly == 0)
                        continue;
                    if (_field.field[_x + lx][_y + ly] == 'O')
                        neighboures++;
                }
            if (neighboures == 3)
                _pBuffer->field[_x][_y] = 'O';
            else if (neighboures < 2 || neighboures > 3)
                _pBuffer->field[_x][_y] = ' ';
        }
}

int main()
{
    srand( (uint)time(NULL) );

    Field* p_map = malloc(sizeof(Field));
    Field* p_shadowMap = malloc(sizeof(Field));
    if (p_map == NULL || p_shadowMap == NULL)
        error_msg("malloc failed");
    CreateField(p_map, 10, 10);
    FieldClear(p_map);
    CreateField(p_shadowMap, 10, 10);
    FieldClear(p_shadowMap);

    for (int y = 0; y < p_map->map_y; y++)
        for (int x = 0; x < p_map->map_x; x++) {
            AddFrame(p_map, x, y);
            AddCells(p_map, x, y);
        }
    FieldShow(*p_map);
    *p_shadowMap = *p_map;
    Sleep(1 * 1000);

    while (1) {
        for (int y = 0; y < p_map->map_y; y++)
            for (int x = 0; x < p_map->map_x; x++)
                Life(*p_shadowMap, p_map, x, y);
        FieldShow(*p_map);
        *p_shadowMap = *p_map;
        Sleep(1 * 1000);
    }

    return 0;
}