
void error_msg(const char* _msg);

int str_to_int(const char* _str);

void delay(unsigned int _douration);

// structs

typedef struct Field {
    int map_x;
    int map_y;
    char** field;
} Field;

void CreateField(Field* _buffer, int _map_x, int _map_y);
void DestroyField(Field* _buffer);
void FieldClear(Field* _buffer);
void FieldShow(Field _setts);

typedef struct Cell {
    int x;
    int y;
    char picture;
} Cell;

Cell CreateCell(int _x, int _y, char _picture);