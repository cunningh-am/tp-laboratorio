#include "Employee.h"
#include "../inc/LinkedList.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_nextId();
void controller_saveId(int currentId);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_searchId(LinkedList* pArrayListEmployee, int id);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_printAnEmployee(Employee* emp);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_setEmployee(LinkedList* pArrayListEmployee);
