# OOOP

Лабораторна робота № 1

Перелік 1: структури даних та алгоритми.

5. (***) Черга з пріоритетом на основі списку (реалізації на основі зв’язного списку та масивів змінної довжини) та дерева. Додавання елементу, забирання елементу (за правилами черги), подивитись наступний елемент, не забираючи його. 

Перелік 2: класи для опису даних.

9. (**)Інформація про дату (рік, місяць, день) та час (години, хвилини, секунди). Перевірка правильності дати та часу відповідно до григоріанського календаря. Арифметика моментів часу: різниця між двома моментами часу у заданих одиницях, додавання чи віднімання такої різниці до заданого моменту часу. Обчислення дня тижня для заданої дати.    
a. +* за обчислення додаткових параметрів, наприклад, номер тижня в місяці та в році   
b. +* за альтернативні варіанти побудови дати та часу (наприклад, «перший вівторок листопада»)      
e. +* за підтримку альтернативних календарів (юліанського, …)     

 + запис черги з пріоритетом у файл та зчитування з файлу
 + unit tests

  Реалізовано класів 5 (PriorityQueue, LinkedListPriorityQueue, DynamicArrayPriorityQueue, BinarySearchTreePriorityQueue, Date)             
  Реалізовано полів 10 (int year, int month, int day, int hour, int minute, int second, bool is_gregorian, struct Node, vector elements, struct Node)            
  Реалізовано нетривіальних методів 21 (int getDaysInMonth, bool ifDateInterval, bool check, void add, void subtract, int calculateDayOfWeek, int weekNumberMonth, int weekNumberYear, int weekNumberMonth2, int weekNumberYear2, void GregorianToJulian, void JulianToGregorian, void print, void printAlternative, void enqueue, T dequeue, T peek, void generate, void print, void writeToFile, void readFromFile)
