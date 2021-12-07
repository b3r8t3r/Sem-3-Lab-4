// Приведенный ниже блок ifdef — это стандартный метод создания макросов, упрощающий процедуру
// экспорта из библиотек DLL. Все файлы данной DLL скомпилированы с использованием символа {0}_EXPORTS
// Символ, определенный в командной строке. Этот символ не должен быть определен в каком-либо проекте,
// использующем данную DLL. Благодаря этому любой другой проект, исходные файлы которого включают данный файл, видит
// функции {0}_API как импортированные из DLL, тогда как данная DLL видит символы,
// определяемые данным макросом, как экспортированные.
#ifdef IERRORDLL_EXPORTS
#define IERRORDLL_API __declspec(dllexport)
#else
#define IERRORDLL_API __declspec(dllimport)
#endif

// Этот класс экспортирован из библиотеки DLL
class IERRORDLL_API CIErrorDLL {
public:
	CIErrorDLL(void);
	// TODO: добавьте сюда свои методы.
};

extern IERRORDLL_API int nIErrorDLL;

IERRORDLL_API int fnIErrorDLL(void);
