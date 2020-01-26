#include "../../../includes/parsing.h"

//Add back obj
int main(void)
{
	t_obj *lst_obj;
	t_obj obj_first;
	t_obj obj_second;
	t_obj obj_third;
	t_obj obj_forth;

	lst_obj = 0;


	obj_first.type = 1;
	obj_first.color[0] = 1;
	obj_first.color[1] = 1;
	obj_first.color[2] = 1;
	obj_first.obj = 0;
	obj_first.next = 0;

	obj_second.type = 2;
	obj_second.color[0] = 2;
	obj_second.color[1] = 2;
	obj_second.color[2] = 2;
	obj_second.obj = 0;
	obj_second.next = 0;

	obj_third.type = 3;
	obj_third.color[0] = 3;
	obj_third.color[1] = 3;
	obj_third.color[2] = 3;
	obj_third.obj = 0;
	obj_third.next = 0;

	obj_forth.type = 4;
	obj_forth.color[0] = 4;
	obj_forth.color[1] = 4;
	obj_forth.color[2] = 4;
	obj_forth.obj = 0;
	obj_forth.next = 0;

	add_back_obj(&lst_obj, &obj_first);
	add_back_obj(&lst_obj, &obj_second);
	add_back_obj(&lst_obj, &obj_third);
	add_back_obj(&lst_obj, &obj_forth);

	t_obj *current;

	current = lst_obj;
	while (current)
	{
		printf("%d\n", current->type);
		current = current->next;
	}
}