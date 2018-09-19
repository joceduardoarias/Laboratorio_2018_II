#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
void initEmployee(eEmployee* arrayEmployee, int len );
/** \brief busca en la estructura por el valor buscado y devuelve el indice
 *
 * \param eEmployee array a recorrer
 * \param len longitud del array
 * \param valor es el valor a buscar dentro del array
 * \return devuelve -1 si no encuctra coincidencia o retornao el indice
 *
 */

int buscarPrimeraOcurrencia(eEmployee* arrayEmpleado, int len, int valor);
int buscarPrimeraOcurrenciaId(eEmployee* arrayEmpleado, int len, int valor);
void setArrayEmployee(eEmployee*  arrayEmpleado,int index,char* name,char* lastName,float salary,int sector,int id,int isEpmty);
#endif // EMPLOYEE_H_INCLUDED
