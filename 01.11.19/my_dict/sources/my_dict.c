#include <stdio.h>
#include <stdlib.h>

struct DictItem {
	void* key;
	void* value;
	void* next;
};

typedef struct Dict {
	int point;		// мусор
	struct DictItem* first_item;
	struct DictItem* last_item;
} Dict;

Dict* CreateDict()
{
	Dict* dict = malloc(sizeof(Dict));
	struct DictItem* start_item = malloc(sizeof(struct DictItem));
	start_item->key = NULL;
	start_item->value = NULL;
	start_item->next = NULL;
	dict->first_item = start_item;
	dict->last_item = start_item;

	dict->point = 1;		// мусор

	return dict;
}

void DestroyDict(Dict* _dict)
{
	struct DictItem* current = _dict->first_item;
	struct DictItem* next = NULL;
	while (current) {
		next = current->next;
		free(current);
		current = next;
	}
	free(_dict);
}

void AddNewItem(Dict* _dict, void* _key, void* _value)
{
	struct DictItem* current_last_item = _dict->last_item;
	current_last_item->key = _key;
	current_last_item->value = _value;
	struct DictItem* new_last_item = malloc(sizeof(Dict));
	current_last_item->next = new_last_item;
	_dict->last_item = new_last_item;
	new_last_item->key = NULL;
	new_last_item->value = NULL;
	new_last_item->next = NULL;
}

void* GetValue(Dict* _dict, void* _key)
{
	printf("GetValue(): (size_t)_key(finding...): %p\n", _key);
	struct DictItem* current = _dict->first_item;
	while (current) {
		printf("\tIteration__\t (size_t)current->key: %p\n", current->key);
		if (current->key == _key)
			return current->value;
		current = current->next;
	}
	puts("--------------------------");
}

void ShowDictItem(struct DictItem* _item, char* name)
{
	printf("ShowDictItem():\t (char*)name: %s\t (size_t)_item: %p\n", name, _item);
	printf("\t (size_t)_item->key: %p\t ", _item->key);
	printf("*(int*)_item->key: %i\n", *(int*)_item->key);
	printf("\t (size_t)_item->value: %p\t ", _item->value);
	printf("*(int*)_item->value: %i\n", *(int*)_item->value);
	printf("\t (size_t)_item->next: %p\n", _item->next);
	puts("");
}



int main()		// мусор
{
	Dict* my_dict = CreateDict();
	printf("main():\t (int)my_dict->point(before DestroyDict()): %i\n", my_dict->point);
	puts("");

	int key = 42;
	int value = 24;
	AddNewItem(my_dict, &key, &value);
	ShowDictItem(my_dict->first_item, "my_dict->first_item");

	int key_1 = 83;
	int value_1 = 92;
	AddNewItem(my_dict, &key_1, &value_1);
	ShowDictItem(my_dict->first_item->next, "my_dict->first_item->next");

	printf("main():\t (size_t)GetValue(my_dict, &find_key): %p\n", GetValue(my_dict, &key));
	puts("");

	DestroyDict(my_dict);
	printf("main():\t (int)my_dict->point(after DestroyDict()): %i\n", my_dict->point);
	system("pause");
	return 0;
}