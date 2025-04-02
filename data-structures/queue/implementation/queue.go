package implementation

import "slices"

type Queue[T any] struct {
	data []T
}

func NewQueue[T any]() *Queue[T] {
	return &Queue[T]{
		data: []T{},
	}
}

func (q *Queue[T]) Dequeue() {
	if len(q.data) == 0 {
		return
	}

	size := len(q.data)
	q.data = slices.Delete(q.data, size-1, size+1)
}

func (q *Queue[T]) Enqueue(elem T) {
	q.data = append(q.data, elem)
}

func (q *Queue[T]) Size() int {
	return len(q.data)
}

func (q *Queue[T]) Empty() bool {
	return len(q.data) == 0
}
