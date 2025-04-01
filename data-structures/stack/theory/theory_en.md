## Stack - a data structure that operates on the "last in, first out" (LIFO) principle.  

#### Imagine a `stack` as a stack of plates: the plate that was placed first will be used last, while the plate that was placed last will be used first.  

The main operations that can be performed on a stack include:  

- Adding an element to the top of the stack (**push**) — O(1).  
- Removing an element from the top of the stack (**pop**) — O(1).  
- Returning the top element without removing it (**peek**) — O(1).  
- Checking if the stack is empty (**isEmpty**) — O(1).  

`It is important to note that a stack consists of a list of elements and a pointer to the top of the stack, which points to the most recently added element.  

Each time a new element is added to the stack, the top pointer moves to the next element. When an element is removed from the top of the stack, the pointer shifts to the previous element. If the pointer reaches the end of the stack, the stack is empty.`

<a href="https://education.yandex.ru/handbook/algorithms/article/stek">Cтек - основы алгоритмов (яндекс)</a><br>
<a href="https://medium.com/nuances-of-programming/%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D1%83%D1%80%D1%8B-%D0%B4%D0%B0%D0%BD%D0%BD%D1%8B%D1%85-%D0%B8-%D0%B0%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D1%8B-%D1%81%D1%82%D0%B5%D0%BA-fee8792751d2">Структуры данных и алгоритмы: стек | by Андрей Шагин</a>
