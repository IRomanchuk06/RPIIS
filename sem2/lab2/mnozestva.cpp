#include <stdio.h> //����������� ������� �����/������ 

#include <stdlib.h> //������� ������������� ���������� �������, ��������� ��������� �����, ����� ����������, ������,
                    //���������� � �������������� ����� ������.
#include <string.h>
#define OPENSET_SYMBOL '{'
#define CLOSESET_SYMBOL '}'
#define TERMSET_SYMBOL ';'
#define TERMNAME_SYMBOL ','
#define DEFNAME_SYMBOL '='

#ifndef STR_MAX_LENGTH   //��������� �������������, ������� ���������, 
                           //�� ���� �� ��� ���������� ���������� ��������� STR_MAX_LENGTH. 
                           // ���� ��� �� ���� ����������, �� ��� ������ ������� ����� ��������.

#define STR_MAX_LENGTH 80  //���� ���������� ��������� STR_MAX_LENGTH �� ���� ���������� �����, 
                           //�� ��� ����� ���������� ����� �� ��������� 80.

#else                     //���� ���������� ��������� STR_MAX_LENGTH ��� ���� ���������� �����, 
                          //�� ��� ����� #else ����� ��������.

#error STR_MAX_LENGTH already define    
                                        // ���� ���������� ��������� STR_MAX_LENGTH ��� ���� ���������� �����, 
                                       //�� ����� ������ ������ ���������� � ���������� "STR_MAX_LENGTH already defined".
#endif


#ifndef TRUE
#ifndef FALSE
#define FALSE 0
#define TRUE 1
#else
#define TRUE (!FALSE)  //���� ������ FALSE ���� ���������� �����, �� TRUE ������������ ��� ���������� ��������� FALSE.
#endif
#else
#ifndef FALSE
#define FALSE (!TRUE) //���� ������ TRUE ���� ���������� �����, �� FALSE ������������ ��� ���������� ��������� TRUE.
#endif
#endif


//---------------------���������� ��������� ��� ������������� ���������---------------------------------------------

typedef struct { //� ������� typedef ����� �������� ����� ���, ������� ���� ���������, ������� � �������.
    int u;
    char* name;
    struct _element_of_set* pFirst;
} set;

typedef set element; //set = element

//--------------------���������� ��������� ��� ������������� � ��������� ��������� �������� �� ���������*-------------

typedef struct _element_of_set {
    element* pElement;
    struct _element_of_set* pNext;
} element_of_set;

//------------------------------------������� ������ ��������� ��� ��������-----------------------------------------
//                                           (���������) 
//                                   +������� ������ ��������� ��� �������� �� ��������� ����� (���������)


void fprint_els(FILE*, void*, int, int);
void fprint_set(FILE*, set*);
void fprint_element(FILE*, element*);

int fscan_els(FILE*, void**, int);
int fscan_set(FILE*, set**);
int fscan_element(FILE*, element**);


void initialize_set(set*); // ������� ������������� ���������

int compare_elements(element*, element*); //������� ��������� ���� ���������

element_of_set* add_element(set*, element*); //������� ���������� �������� �� ��������� 

element* find_element(set*, element*); //������� ������ �������� �� ���������

element* get_next_element(set*, element_of_set*); //������� ��������� ���������� �������� �� ���������

void* set_next_element(set*, element_of_set*, element*); //������� ��������� ���������� �������� �� ���������

void go_next(set*, element_of_set**); //������� �������� � ���������� ���������

void remove_next_element(set*, element_of_set*); //������� ���������� ������������ �������� �� ���������

void destroy_elements(set*); //������� ����������� ��������� ���������

void clear_set(set*); //������� ������� ���������

set names; // ��������� ����������� ��������� 

//--------------------------------------------MAIN----------------------------------------------------

int main(int argc, char* argv[]) {
    int return_value = 0;
    FILE* input;
    set general_set;
    set* pSet = NULL;
    set copy;
    element_of_set* pEOSG = NULL;
    element_of_set* pEOS = NULL;
    element* pElement;
    if (argc == 2) if ((input = fopen(argv[1], "r")) != NULL) {
        /* ������������� � ������ ������ �� ����� */
        initialize_set(&names);
        initialize_set(&general_set);
        if ((return_value = fscan_set(input, &pSet)) == 0) return_value--;
        else {
            add_element(&general_set, pSet);
            while ((return_value = fscan_set(input, &pSet)) > 0) add_element(&general_set, pSet);
        }
        fclose(input);
        /* ����������� ������� ���������
        � ����� ���������� */
        if (return_value == 0) do {
            if ((pSet = get_next_element(&general_set, pEOSG)) != NULL) {
                initialize_set(&copy);
                do {
                    if ((pElement = get_next_element(pSet, pEOS)) != NULL) {
                        if (find_element(&copy, pElement) == NULL) add_element(&copy, pElement);
                    }
                    go_next(pSet, &pEOS);
                } while (pEOS != NULL);
                fprint_set(stdout, &copy);
                clear_set(&copy);
            }
            go_next(&general_set, &pEOSG);
        } while (pEOSG != NULL);
        else printf("Syntax error.\n");
        destroy_elements(&names);
        return_value = 1;
    }
    return return_value;
}
