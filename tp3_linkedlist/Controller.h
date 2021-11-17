#include "Employee.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_loadID(char* path, int* pID);
int controller_addEmployee(LinkedList* pArrayListEmployee,int* nextId);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_findEmployeeById(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_printEmployee(Employee* unEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_saveID(char* path, int* pId);

