## Стек - структура данных, работающая по принципу «последним пришёл, первым ушёл» (LIFO — last in, first out)

#### Представьте `стек` как стопку тарелок, тарелка которую положили первой будет использована последней, а тарелка котрую положили последней будет использована первой

Основные операции, которые можно производить со стеком, включают:

Добавление элемента в вершину стека (push) — O(1).<br>
Удаление элемента из вершины стека (pop) — O(1). <br>
Возврат верхнего элемента без его удаления (peek) — O(1). <br>
Проверка стека на пустоту (isEmpty) — O(1). <br>

`Стоит отметить, что стек представляет собой список с элементами и указателя на вершину стека, указывающего на последний элемент, добавленный в стек.

Каждый раз, когда в стек добавляется новый элемент, указатель на вершину смещается на следующий элемент. Когда элемент удаляется из вершины стека, указатель смещается на предыдущий элемент. Если указатель находится в конце стека, то стек пуст`

<a href="https://education.yandex.ru/handbook/algorithms/article/stek">Cтек - основы алгоритмов (яндекс)</a><br>
<a href="https://medium.com/nuances-of-programming/%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D1%83%D1%80%D1%8B-%D0%B4%D0%B0%D0%BD%D0%BD%D1%8B%D1%85-%D0%B8-%D0%B0%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D1%8B-%D1%81%D1%82%D0%B5%D0%BA-fee8792751d2">Структуры данных и алгоритмы: стек | by Андрей Шагин</a>