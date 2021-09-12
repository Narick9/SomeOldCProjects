#include <stdio.h>

#include <allegro5/allegro5.h>		//подключаем основное ядро allegro
#include <allegro5/allegro_font.h>		//подключаем аддон шрифта для отображения текста

void error_msg(char* _msg)
{
	fprintf(stderr, "ERROR\t%s\n", _msg);
	return 1;
}

int main()
{
	if(!al_init())	// инициализируем биты allegro
		error_msg("allegro initialization failed");
	if (!al_install_keyboard())	// подключаем клавиатуру
		error_msg("allegro keyboard initialization failed");

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);	//30 кадров в секунду
	if (!timer)
		error_msg("allegro create_timer() failed");
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();	//создаём очередь событий
	if (!queue)
		error_msg("allegro create_event_queue() failed");
	ALLEGRO_DISPLAY* disp = al_create_display(640, 480);	//размер экрана 320 на 200 пикселей
	if (!disp)
		error_msg("allegro create_display() failed");
	ALLEGRO_FONT* font = al_create_builtin_font();	//создаём шрифт
	if (!font)
		error_msg("allegro create_builtin_font() failed");

	al_register_event_source(queue, al_get_keyboard_event_source());	//связываем клавиатуру
	al_register_event_source(queue, al_get_display_event_source(disp));	//связываем верхнюю панель windows
	al_register_event_source(queue, al_get_timer_event_source(timer));	//связываем наш таймер

	bool done = true;
	bool redraw = true;
	ALLEGRO_EVENT event;	//контейнер для события

	al_start_timer(timer);	//начало отсчёта нашего таймера
	while(1) {	//основной цикл программы
		al_wait_for_event(queue, &event);	//ждём события
		
		switch(event.type) {
		case ALLEGRO_EVENT_TIMER:
			redraw = true;
			break;
		case ALLEGRO_EVENT_KEY_DOWN:
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			done = false;
			break;
		}

		if (done == false)
			break;

		if (redraw && al_is_event_queue_empty(queue)) {
			al_clear_to_color(al_map_rgb(0, 0, 0));	//заполняем экран чёрными пикселями
			al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "It's my text!");
			al_flip_display();	//онбновляем экран

			redraw = false;
		}
	}

	/*очищаем ресуры, которых больше не будем использовать*/
	al_destroy_font(font);	
	al_destroy_display(disp);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);

	return 0;
}