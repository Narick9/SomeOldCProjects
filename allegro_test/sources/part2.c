#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include < allegro5/allegro5.h>
#include < allegro5/allegro_font.h>
#include < allegro5/allegro_image.h>
#include < allegro5/allegro_primitives.h>

#include "..\resource.h"

void must_init(bool test, const char* description)  //проверка на ошибки
{
	if (test)
        return;
	fprintf(stderr, "couldn't initialize %s\n", description);
	system("pause");
	exit(1);
}

int randrange(int min, int max)
{
	return min + rand() % (max - min + 1);
}

enum BOUNCER_TYPE {
	BT_HELLO,
	BT_MYSHA,
	BT_TRIANGLE,
	BT_RECTANGLE_1,
	BT_RECTANGLE_2,
	BT_CIRCLE,
	BT_LINE1,
	BT_LINE2,
	BT_N
};

typedef struct BOUNCER
{
	float x, y;
	float width, height;
	float dx, dy;
} BOUNCER;

int main()
{
	must_init( al_init(), "allegro");   //инициализируем аллегро
	must_init( al_install_keyboard(), "keyboard");  //подключаем клавиатуру
	must_init(al_init_image_addon(), " image addon");  //инициализируем аддон для изображений
	must_init(al_init_primitives_addon(), " primitives");   //инициализируем аддон для примитивов

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0); //создаём таймер
	must_init(timer, " timer");


	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();   //создаём очередь
	must_init(queue, "queue");

	al_set_new_display_option( ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST); //создаём сглаживение
	al_set_new_display_option( ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);        //
	al_set_new_bitmap_flags( ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);      //

	ALLEGRO_DISPLAY* disp = al_create_display(640, 480);    //создаём дисплей
	must_init(disp, "display");

	ALLEGRO_FONT* font = al_create_builtin_font();  //создаём обычный шрифт
	must_init(font, "font");

	ALLEGRO_BITMAP* mysha = al_load_bitmap("mysha.png");    //заргужаем картику 
	must_init(mysha, "mysha.png");

	al_register_event_source(queue, al_get_keyboard_event_source());    //связываем клавиатуру с нашей очередью
	al_register_event_source(queue, al_get_display_event_source(disp)); //связываем панель окна с нашей очередью
	al_register_event_source(queue, al_get_timer_event_source(timer));  //связываем наш таймер с нашей очередью

	bool done = false;  //флаг цикла
	bool redraw = true; //флаг рисования нового кадра
	ALLEGRO_EVENT event;    //буффер события

	BOUNCER obj[BT_N];
	for (int i = 0; i < BT_N; i++)
	{
		BOUNCER* b = &obj[i];
		b->x = randrange(0, 640);
		b->y = randrange(0, 480);
		switch (i) {
		case BT_HELLO:			b->width = 100;		b->height = 10;			break;
		case BT_MYSHA:			b->width = 320;		b->height = 200;		break;
		case BT_TRIANGLE:		b->width = 50;		b->height = 50;			break;
		case BT_RECTANGLE_1:	b->width = 100;		b->height = 80;			break;
		case BT_RECTANGLE_2:	b->width = 120;		b->height = 100;		break;
		case BT_CIRCLE:			b->width = 60;		b->height = b->width;	break;
		case BT_LINE1:			b->width = 20;		b->height = 100;		break;
		case BT_LINE2:			b->width = 70;		b->height = -20;		break;
		}
		b->dx = randrange(-4, 4);
		b->dy = randrange(-4, 4);
	}

	al_start_timer(timer);  //начинаем отсчёт до следующего кадра
	while (1)
	{
		al_wait_for_event(queue, &event);   //ждём новое событие

		switch (event.type) {   //реагируем на событие
		case ALLEGRO_EVENT_TIMER:
			for (int i = 0; i < BT_N; i++) {
				BOUNCER* b = &obj[i];
				b->x += b->dx;
				b->y += b->dy;

				if (b->x < 0) {
					b->x = 0;
					b->dx *= -1;
				} else if (b->x + b->width < 0) {
					b->x = -b->width;
					b->dx *= -1;
				}
				if (b->x + b->width > 640) {
					b->x = 640 - b->width;
					b->dx *= -1;
				} else if (b->x > 640) {
					b->x = 640;
					b->dx *= -1;
				}
				if (b->y < 0) {
					b->y = 0;
					b->dy *= -1;
				} else if (b->y + b->height < 0) {
					b->y = -b->height;
					b->dy *= -1;
				}
				if (b->y + b->height > 480) {
					b->y = 480 - b->height;
					b->dy *= -1;
				} else if (b->y > 480) {
					b->y = 480;
					b->dy *= -1;
				}
			}
			redraw = true;
			break;
		case ALLEGRO_EVENT_KEY_DOWN:
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			done = true;
			break;
		}

		if (done)
			break;

		if (redraw && al_is_event_queue_empty(queue)) { //если пришло время рисовать кадр
			ALLEGRO_VERTEX v[4];
			al_clear_to_color(al_map_rgb(0, 0, 0));

			for (int i = 0; i < BT_N; i++) {
				BOUNCER* b = &obj[i];
				switch (i) {
				case BT_HELLO:
					al_draw_text(font, al_map_rgba_f(1, 1, 1, 1), b->x, b->y, 0, "Hello world!");
					break;
				case BT_MYSHA:
					al_draw_bitmap(mysha, b->x, b->y, 0);
					break;
				case BT_TRIANGLE:
					al_draw_filled_triangle(b->x, b->y, b->x + b->width, b->y + 25, 
											b->x, b->y + b->height, al_map_rgba_f(0, 1, 0, 0.2));
					break;
				case BT_RECTANGLE_1:
					al_draw_filled_rectangle(b->x, b->y, b->x + b->width, b->y + b->height, 
											al_map_rgba_f(0, 0, 0.5, 0.5));
					break;
				case BT_RECTANGLE_2:
					v[0].x = b->x; v[0].y = b->y; v[0].z = 0; v[0].color = al_map_rgba_f(1, 0, 0, 0.2);
					v[1].x = b->x + b->width; v[1].y = b->y; v[1].z = 0; v[1].color = al_map_rgba_f(0, 1, 0, 0.4);
					v[2].x = b->x; v[2].y = b->y + b->height; v[2].z = 0; v[2].color = al_map_rgba_f(0, 0, 1, 0.6);
					v[3].x = b->x + b->width; v[3].y = b->y + b->height; v[3].z = 0; v[3].color = al_map_rgba_f(1, 1, 0, 1);
					al_draw_prim(v, NULL, NULL, 0, 4, ALLEGRO_PRIM_TRIANGLE_STRIP);
					break;
				case BT_CIRCLE:
					al_draw_circle(b->x + b->width/2, b->y + b->width/2, b->width/2, al_map_rgb_f(1, 0, 1), 2);
					break;
				case BT_LINE1:
					al_draw_line(b->x, b->y, b->x + b->width, b->y + b->height, al_map_rgb_f(1, 0, 0), 1);
					break;
				case BT_LINE2:
					al_draw_line(b->x, b->y, b->x + b->width, b->y + b->height, al_map_rgb_f(1, 1, 0), 1);
					break;
				}
			}
			al_flip_display();
			redraw = false;
		}
	}

	al_destroy_bitmap(mysha);       //очищаем память от мусора
	al_destroy_font(font);          //
	al_destroy_display(disp);       //
	al_destroy_timer(timer);        //
	al_destroy_event_queue(queue);  //
	return 0;
}