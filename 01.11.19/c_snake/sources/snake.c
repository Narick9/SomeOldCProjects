#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <string.h>
#include <errno.h>

#include <conio.h>
#include <windows.h>


//--------------ERROR--------------
void error_msg(char* _msg)
{
    fprintf(stderr, "ERROR\t %s: %s\n", _msg, strerror(errno));
    exit(1);
}

//--------------Structs--------------
typedef struct {
    int x;
    int y;
    char picture;
} Cell;
typedef struct {
    char trend;
    int size;
    Cell* body;
} Snake;
typedef struct {
    int map_x;
    int map_y;
    char** field;
    int hz;
} Settings;

//--------------Settings--------------
void DestroySettings(Settings* _pBuffer)
{
    for (int x = 0; x < _pBuffer->map_x; x++)
        free(_pBuffer->field[x]);
    free(_pBuffer);
}

Settings* CreateSettings(int _mapX, int _mapY)
{
    Settings* pBuffer = malloc(sizeof(Settings));
    if (pBuffer == NULL)
        error_msg("CreateSettings():\t Failed to get memory");

    pBuffer->map_x = _mapX;
    pBuffer->map_y = _mapY;
    pBuffer->field = malloc(sizeof(size_t) * _mapX);
    if (pBuffer->field == NULL)
        error_msg("CreateSettings():\t Failed to get memory");

    for (int x = 0; x < _mapX; x++) {
        pBuffer->field[x] = malloc(sizeof(char) * _mapY);
        if (pBuffer->field[x] == NULL)
            error_msg("CreateSettings():\t Failed to get memory");
    }
    pBuffer->hz = 8;

    return pBuffer;
}

void SettingsFieldClear(Settings* _pBuffer)
{
    for (int y = 0; y < _pBuffer->map_y; y++)
        for (int x = 0; x < _pBuffer->map_x; x++)
            if (    x == 0 
                ||  x == _pBuffer->map_x - 1
                ||  y == 0
                ||  y == _pBuffer->map_y - 1)
                _pBuffer->field[x][y] = '#';
            else
                _pBuffer->field[x][y] = ' ';
}

void SettingsFieldAdd(Settings* _pBuffer, Snake* _pSnake, Cell* _pApple)
{
    if (_pSnake != NULL) {
        int x, y;
        char picture;
        for (int i = 0; i < _pSnake->size; i++) {
            x = _pSnake->body[i].x;
            y = _pSnake->body[i].y;
            picture = _pSnake->body[i].picture;
            _pBuffer->field[x][y] = picture;
        }
    }
    if (_pApple != NULL)
        _pBuffer->field[_pApple->x][_pApple->y] = _pApple->picture;
}

void SettingsFieldShow(Settings _setts, int _cls)
{
    for (int y = 0; y < _setts.map_y; y++) {
        for (int x = 0; x < _setts.map_x; x++)
            printf("%c", _setts.field[x][y]);
        printf("\n");
    }
    Sleep(1000 / _setts.hz);
    if (_cls)
        system("cls");
}

//--------------Apple--------------
void DestroyApple(Cell* _pBuffer)
{
    free(_pBuffer);
}

Cell* CreateApple(Settings _setts)
{
    Cell* pBuffer = malloc(sizeof(Cell));
    if (pBuffer == NULL)
        error_msg("CreateApple():\t Failed to get memory");

    int x_r, y_r;
    do {
        x_r = rand() % (_setts.map_x - 2) + 1;
        y_r = rand() % (_setts.map_y - 2) + 1;
    } while (_setts.field[x_r][y_r] != ' ');
    pBuffer->x = x_r;
    pBuffer->y = y_r;
    pBuffer->picture = '$';

    return pBuffer;
}

//--------------Snake--------------
void DestroySnake(Snake* _pBuffer)
{
    free(_pBuffer->body);
    free(_pBuffer);
}

Snake* CreateSnake(Settings _setts)
{
    Snake* pBuffer = malloc(sizeof(Snake));
    if (pBuffer == NULL)
        error_msg("CreateSnake():\t Failed to get memory");
    
    int center_x = _setts.map_x / 2;
    int center_y = _setts.map_y / 2;

    pBuffer->trend = 'd';
    pBuffer->size = 3;
    int maxSnakeSize = (_setts.map_x - 2) * (_setts.map_y - 2);
    pBuffer->body = malloc(sizeof(Cell) * maxSnakeSize);
    if (pBuffer->body == NULL)
        error_msg("CreateSnake():\t Failed to get memory");
    pBuffer->body[0].picture = 'O';
    pBuffer->body[0].x = center_x;
    pBuffer->body[0].y = center_y;
    for (int i = 1; i < maxSnakeSize; i++) {
        pBuffer->body[i].x = center_x - i;
        pBuffer->body[i].y = center_y;
        pBuffer->body[i].picture = 'x';
    }

    return pBuffer;
}

void SnakeMovement(Snake* _pBuffer)
{
    for (int i = _pBuffer->size; i >= 1; i--) {
        _pBuffer->body[i].x = _pBuffer->body[i - 1].x;
        _pBuffer->body[i].y = _pBuffer->body[i - 1].y;
    }
    char enter = _pBuffer->trend;
    if (kbhit())
        enter = getch();
    switch (enter) {
        case 'w':   enter = 'w';    break;
        case 'a':   enter = 'a';    break;
        case 's':   enter = 's';    break;
        case 'd':   enter = 'd';    break;
    }
    if (    enter == 'w' && _pBuffer->trend != 's'
        ||  enter == 'a' && _pBuffer->trend != 'd'
        ||  enter == 's' && _pBuffer->trend != 'w'
        ||  enter == 'd' && _pBuffer->trend != 'a')
        _pBuffer->trend = enter;

    switch (_pBuffer->trend) {
        case 'w':   _pBuffer->body[0].y--;   break;
        case 'a':   _pBuffer->body[0].x--;   break;
        case 's':   _pBuffer->body[0].y++;   break;
        case 'd':   _pBuffer->body[0].x++;   break;
    }
}

int SnakeCheck(Snake _snake, Cell _apple, Settings _setts)
{
    char head_cell = _setts.field[_snake.body[0].x][_snake.body[0].y];
    if (head_cell == ' ') {
        return 0;
    } else if (head_cell == _apple.picture) {
        return 2;
    }
    return 1;
}

void SnakeShow(Snake _snake)
{
    printf("_____________SNAKE_____________\n\n\n");
    printf("x: %i\n", _snake.body[0].x);
    printf("y: %i\n", _snake.body[0].y);
    printf("level: %i\n", _snake.size);
    printf("trend: '%c'\n", _snake.trend);
}

//--------------main()--------------
int main(void)
{
    printf("_____________SNAKE_____________\n\n\n");
    printf("Start?\n");
    system("pause");

    Settings* p_setts = CreateSettings(20, 8);
    SettingsFieldClear(p_setts);
    Snake* p_snake = NULL;
    Cell* p_apple = NULL;

    srand(time(NULL));

    int checkResult;
    char enter[50];
    do {
        p_snake = CreateSnake(*p_setts);
        SettingsFieldAdd(p_setts, p_snake, NULL);
        p_apple = CreateApple(*p_setts);
        SettingsFieldAdd(p_setts, NULL, p_apple);
        
        system("cls");
        while (1) {
            SnakeMovement(p_snake);

            checkResult = SnakeCheck(*p_snake, *p_apple, *p_setts);
            if (checkResult == 1) {
                SnakeShow(*p_snake);
                SettingsFieldShow(*p_setts, 0);
                break;
            } else if (checkResult == 2) {
                p_snake->size++;
                SnakeShow(*p_snake);
                SettingsFieldClear(p_setts);
                SettingsFieldAdd(p_setts, p_snake, NULL);
                p_apple = CreateApple(*p_setts);
                SettingsFieldAdd(p_setts, NULL, p_apple);
            } else {
                SnakeShow(*p_snake);
                SettingsFieldClear(p_setts);
                SettingsFieldAdd(p_setts, p_snake, p_apple);
            }
            SettingsFieldShow(*p_setts, 1);
        }

        DestroySnake(p_snake);
        DestroyApple(p_apple);

        printf("_____________END GAME_____________\n");
        printf("Do you want to continue? (y/n): ");
        scanf("%50s", enter);
    } while (enter[0] == 'y');

    DestroySettings(p_setts);

    printf("\nexit\n\n\n");
    system("pause");
    return 0;
}