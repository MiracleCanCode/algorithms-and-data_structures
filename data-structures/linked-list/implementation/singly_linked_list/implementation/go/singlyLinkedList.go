package main

// Структура элемента списка
// value - значение узла(данные которые хранятся в узле списка)
// nextItemPtr - указатель на следующий элемент списка
type SingleLinkedListItem struct {
	value       any
	nextItemPtr *SingleLinkedListItem
}

// Структура списка 
// head - указатель на начало списка
// length - длина списка
type SingleLinkedList struct {
	head *SingleLinkedListItem
	length int
}

func NewSingleLinkedList() *SingleLinkedList {
	return &SingleLinkedList{
		head: nil,
		length: 0,
	}
}

func (s *SingleLinkedList) InsertInHead(value any) {
	// Создаем новый узел списка
	newItem := &SingleLinkedListItem{
		value:       value,
		nextItemPtr: nil,
	}
	// Если список пуст - то просто вставляем
	// Иначе сдвигаем голову и вставляем
	if s.head == nil {
		s.head = newItem
	} else {
		prevNode := s.head
		s.head = newItem
		newItem.nextItemPtr = prevNode
	}
	s.length++
}

func (s *SingleLinkedList) InsertInTail(value any) {
	// Создаем новый узел для вставки в конец
	newNode := &SingleLinkedListItem{
		value: value,
		nextItemPtr: nil,
	}
	
	// Если список пустой, то мы вставляем элемент в начало
	if s.head == nil {
		s.head = newNode
	} else {
		// Создаем копию головы(начала списка)
		prevNode := s.head
		// Итерируемся по списку, устанавливая prevNode как следующий элемент
		// prevNode пока nextItemPtr не будет nil(дойдем до конца списка)
		for prevNode.nextItemPtr != nil {
			prevNode = prevNode.nextItemPtr
		}
		// Устанавливаем хвост списка(конец списка)
		prevNode.nextItemPtr = newNode
	}
	// Увеличиваем длину на 1
	s.length++
}

func (s *SingleLinkedList) AddItem(n int, value any) {
	// Если n равна 0 - то вставляем элемент в начало
	if n == 0 {
		s.InsertInHead(value)
		return
	}
	// Если n == s.length-1 - то мы вставляем элемент в конец списка
	if n == s.length {
		s.InsertInTail(value)
		return
	}
	
	// Создаем новый узел для вставки в список
	newNode := &SingleLinkedListItem{
		value: value,
		nextItemPtr: nil,
	}

	prevNode := s.head
	// Итерируемся по списку до n-1 
	for i := 0; i < n-1; i++ {
		prevNode = prevNode.nextItemPtr
	}
	
	// Вставляем элемент в позицию n и увеличиваем длину списка на 1
	newNode.nextItemPtr = prevNode.nextItemPtr
	prevNode.nextItemPtr = newNode
	s.length++
}

func (s *SingleLinkedList) RemoveHead() {
	// удаляем первый элемент списка
	prevHead := s.head
	s.head = prevHead.nextItemPtr
	s.length--
}

func (s *SingleLinkedList) RemoveTail() {
	// итерируемся по списку до конца и удаляем конечный элемент
	prevNode := s.head
	var prevTailNode *SingleLinkedListItem
	for prevNode.nextItemPtr != nil {
		prevTailNode = prevNode
		prevNode = prevNode.nextItemPtr
	}

	prevTailNode.nextItemPtr = nil
	s.length--
}

func (s *SingleLinkedList) Remove(n int) {
	// если n == 0 - то удаляем начало списка 
	// n - это индекс элемента который нужно удалить
	if n == 0 {
		s.RemoveHead()
		return
	}
	
	// если n == длине нашего списка - то удаляем последний элемент
	if n == s.length {
		s.RemoveTail()
		return
	}

	// итерируемся по списку до n-го элемента
	prevNode := s.head
	for i := 0; i < n-1; i++ {
		prevNode = prevNode.nextItemPtr
	}
	
	// меняем указатели элемента которого нужно удалить
	// уменьшаем длину списка на 1
	prevNNode := prevNode.nextItemPtr
	prevNode.nextItemPtr = prevNNode.nextItemPtr
	s.length--
}
