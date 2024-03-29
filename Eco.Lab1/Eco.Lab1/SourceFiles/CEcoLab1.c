/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoLab1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CEcoLab1.h"
#include "IdEcoCalculatorA.h"


int IsEqualGUID(const UGUID* guid1, const UGUID* guid2) {
    return memcmp(guid1, guid2, sizeof(UGUID)) == 0;
}
/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoLab1
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1_QueryInterface(/* in */ struct IEcoLab1* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoLab1) ) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
    else if (IsEqualGUID(riid, &IID_IEcoCalculatorY)) {
        *ppv = &pCMe->m_pVTblIEcoCalculatorY;
        ++pCMe->m_cRef;
    }
    else if (IsEqualGUID(riid, &IID_IEcoCalculatorX)) {
        if (pCMe->m_pInnerUnknown == 0) {
            *ppv = &pCMe->m_pVTblIEcoCalculatorX;
        }
        else {
            pCMe->m_pInnerUnknown->pVTbl->QueryInterface(pCMe->m_pInnerUnknown, riid, ppv);
        }
        ++pCMe->m_cRef;
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}


/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoLab1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1_AddRef(/* in */ struct IEcoLab1* me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoLab1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1_Release(/* in */ struct IEcoLab1* me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoLab1((IEcoLab1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

int16_t ECOCALLMETHOD IEcoCalculatorX_QueryInterface(/* in */ struct IEcoCalculatorX* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*));
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return result;
    }

    return ((IEcoUnknown *)&pCMe->m_pVTblIEcoLab1)->pVTbl->AddRef((IEcoUnknown *)&pCMe->m_pVTblIEcoLab1);
}

uint32_t ECOCALLMETHOD IEcoCalculatorX_AddRef(/* in */ struct IEcoCalculatorX* me) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ((IEcoUnknown *)&pCMe->m_pVTblIEcoLab1)->pVTbl->AddRef((IEcoUnknown *)&pCMe->m_pVTblIEcoLab1);
}

uint32_t ECOCALLMETHOD IEcoCalculatorX_Release(/* in */ struct IEcoCalculatorX* me) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    return ((IEcoUnknown *)&pCMe->m_pVTblIEcoLab1)->pVTbl->Release((IEcoUnknown *)&pCMe->m_pVTblIEcoLab1);
}

int32_t ECOCALLMETHOD Addition(/* in */ struct IEcoCalculatorX* me, /* in */ int16_t a, /* in */ int16_t b) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*));
    int32_t result = 0;

    /* Проверка указателей */
    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pIEcoCalculatorX != 0) {
        result = pCMe->m_pIEcoCalculatorX->pVTbl->Addition(pCMe->m_pIEcoCalculatorX, a, b);
    }

    return result;
}

int16_t ECOCALLMETHOD Subtraction(/* in */ struct IEcoCalculatorX* me, /* in */ int16_t a, /* in */ int16_t b) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*));
    int16_t result = 0;

    /* Проверка указателей */
    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pIEcoCalculatorX != 0) {
        result = pCMe->m_pIEcoCalculatorX->pVTbl->Subtraction(pCMe->m_pIEcoCalculatorX, a, b);
    }

    return result;
}

int16_t ECOCALLMETHOD IEcoCalculatorY_QueryInterface(/* in */ struct IEcoCalculatorY* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*));
    int16_t result;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    return ((IEcoUnknown *)&pCMe->m_pVTblIEcoLab1)->pVTbl->QueryInterface((IEcoUnknown *)&pCMe->m_pVTblIEcoLab1, riid, ppv);
}

uint32_t ECOCALLMETHOD IEcoCalculatorY_AddRef(/* in */ struct IEcoCalculatorY* me) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(struct IEcoLab1*));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ((IEcoUnknown *)&pCMe->m_pVTblIEcoLab1)->pVTbl->AddRef((IEcoUnknown *)&pCMe->m_pVTblIEcoLab1);
}

uint32_t ECOCALLMETHOD IEcoCalculatorY_Release(/* in */ struct IEcoCalculatorY* me) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(struct IEcoLab1*));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ((IEcoUnknown *)&pCMe->m_pVTblIEcoLab1)->pVTbl->Release((IEcoUnknown *)&pCMe->m_pVTblIEcoLab1);
}

int32_t ECOCALLMETHOD Multiplication(/* in */ struct IEcoCalculatorY* me, /* in */ int16_t a, /* in */ int16_t b) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(struct IEcoLab1*));
    int32_t result = 0;

    /* Проверка указателей */
    if (me == 0 ) {
        return -1;
    }

    return pCMe->m_pIEcoCalculatorY->pVTbl->Multiplication(pCMe->m_pIEcoCalculatorY, a, b);
}

int16_t ECOCALLMETHOD Division(/* in */ struct IEcoCalculatorY* me, /* in */ int16_t a, /* in */ int16_t b) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(struct IEcoLab1*));
    int16_t result = 0;

    /* Проверка указателей */
    if (me == 0 ) {
        return -1;
    }

    return pCMe->m_pIEcoCalculatorY->pVTbl->Division(pCMe->m_pIEcoCalculatorY, a, b);
}


// Копирует заданное число байт
void copy_bytes(char *src, char *dst, size_t count) {
    char *end = src + count;
    while (src < end) {
        *(dst++) = *(src++);
    }
}

// Структура для узла бинарного дерева
struct Node {
    char *data;
    struct Node *left, *right;
};

// Функция для создания нового узла дерева
struct Node* newNode(struct CEcoLab1* pCMe, char *item, size_t elem_size) {
    struct Node* temp = pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, sizeof(struct Node));
    temp->data = pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, elem_size);
    copy_bytes(item, temp->data, elem_size);
    temp->left = temp->right = NULL;
    return temp;
}

// Функция для вставки нового узла в бинарное дерево
struct Node* insert(struct CEcoLab1* pCMe, struct Node* node, char *key, size_t elem_size, int (*comp)(const void *, const void *)) {
    if (node == NULL) return newNode(pCMe, key, elem_size);

    if (comp(key, node->data) < 0)
        node->left = insert(pCMe, node->left, key, elem_size, comp);
    else
        node->right = insert(pCMe, node->right, key, elem_size, comp);

    return node;
}

// Функция для обхода дерева в порядке возрастания
void inOrder(struct Node* root, char **arr, size_t elem_size) {
    if (root != NULL) {
        inOrder(root->left, arr, elem_size);
        copy_bytes(root->data, *arr, elem_size);
        *arr += elem_size;
        inOrder(root->right, arr, elem_size);
    }
}

void freeTree(struct Node* node, CEcoLab1* pCMe) {
    if (node == NULL) return;

    freeTree(node->left, pCMe);
    freeTree(node->right, pCMe);

    pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, node);
}

// Функция для сортировки массива с использованием Tree Sort
void treeSort(struct CEcoLab1* pCMe, char *arr, size_t n, size_t elem_size, int (*comp)(const void *, const void *)) {
    struct Node *root = NULL;

    // Вставляем все элементы массива в бинарное дерево
    for (int i = 0; i < n; i++)
        root = insert(pCMe, root, (char*)arr + i * elem_size, elem_size, comp);

    // Обходим дерево в порядке возрастания и записываем отсортированные элементы обратно в массив
    inOrder(root, &arr, elem_size);
    
    freeTree(root, pCMe);
}

/*
 *
 * <сводка>
 *   Функция TreeSort реализует сортировку двоичным деревом
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1_qsort(
                                        struct IEcoLab1* me,
                                        void* pData,
                                        size_t elem_count,
                                        size_t elem_size,
                                        int (__cdecl *compare)(const void *, const void*)) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателей */
    if (me == 0 || pData == 0 || compare == 0) {
        return -1;
    }
        
    // Tree sort
    treeSort(pCMe, pData, elem_count, elem_size, compare);
    
    return 0;
}

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCEcoLab1(/*in*/ struct IEcoLab1* me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;



    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);
    
    return result;
}

// Виртуальные таблицы

/* Create Virtual Table IEcoLab1 */
IEcoLab1VTbl g_x277FC00C35624096AFCFC125B94EEC90VTbl = {
    CEcoLab1_QueryInterface,
    CEcoLab1_AddRef,
    CEcoLab1_Release,
    CEcoLab1_qsort
};

IEcoCalculatorXVTbl g_x9322111622484742AE0682819447843DVTblLab1 = {
    IEcoCalculatorX_QueryInterface,
    IEcoCalculatorX_AddRef,
    IEcoCalculatorX_Release,
    Addition,
    Subtraction
};

IEcoCalculatorYVTbl g_xBD6414C29096423EA90C04D77AFD1CADVTblC = {
    IEcoCalculatorY_QueryInterface,
    IEcoCalculatorY_AddRef,
    IEcoCalculatorY_Release,
    Multiplication,
    Division
};
/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCEcoLab1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoLab1** ppIEcoLab1) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoLab1* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
    
    /* Проверка указателей */
    if (ppIEcoLab1 == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoLab1*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoLab1));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoLab1 */
    pCMe->m_pVTblIEcoLab1 = &g_x277FC00C35624096AFCFC125B94EEC90VTbl;
    
    pCMe->m_pVTblIEcoCalculatorY = &g_xBD6414C29096423EA90C04D77AFD1CADVTblC;
    pCMe->m_pVTblIEcoCalculatorX = &g_x9322111622484742AE0682819447843DVTblLab1;

    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoLab1 = (IEcoLab1*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteCEcoLab1(/* in */ IEcoLab1* pIEcoLab1) {
    CEcoLab1* pCMe = (CEcoLab1*)pIEcoLab1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoLab1 != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_Name != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}

