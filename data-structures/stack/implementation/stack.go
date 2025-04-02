package implementation

type stack[T any] struct {
	data []T
}

func NewStack[T any]() *stack[T] {
	return &stack[T]{
		data: []T{},
	}
}

func (s *stack[T]) Push(value T) {
	s.data = append(s.data, value)
}
func (s *stack[T]) Pop() {
	if len(s.data) == 0 {
		return
	}

	s.data = s.data[:len(s.data)-1]
}
func (s *stack[T]) Peek() T {
	if len(s.data) == 0 {
		panic("")
	}

	return s.data[len(s.data)-1]
}
func (s *stack[T]) IsEmpty() bool {
	return len(s.data) == 0
}
