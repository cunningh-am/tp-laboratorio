#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* anEmployee);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Compara los ID de los empleados
 * \param employee1 void* Puntero a void del primer empleado a comparar
 * \param employee2 void* Puntero a void del segundo empleado a comparar
 * \return int 1 si el orden es descendente, -1 si es ascendente
 */
int employee_sortById(void* employee1, void* employee2);

/** \brief Compara los nombres de los empleados
 * \param employee1 void* Puntero a void del primer empleado a comparar
 * \param employee2 void* Puntero a void del segundo empleado a comparar
 * \return int 1 si el orden es descendente, -1 si es ascendente
 */
int employee_sortByName(void* employee1, void* employee2);

/** \brief Compara las horas trabajadas de los empleados
 * \param employee1 void* Puntero a void del primer empleado a comparar
 * \param employee2 void* Puntero a void del segundo empleado a comparar
 * \return int 1 si el orden es descendente, -1 si es ascendente
 */
int employee_sortByHours(void* employee1, void* employee2);

/** \brief Compara los sueldos de los empleados
 * \param employee1 void* Puntero a void del primer empleado a comparar
 * \param employee2 void* Puntero a void del segundo empleado a comparar
 * \return int 1 si el orden es descendente, -1 si es ascendente
 */
int employee_sortBySalary(void* employee1, void* employee2);
#endif // employee_H_INCLUDED
