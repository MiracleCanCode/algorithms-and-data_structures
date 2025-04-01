package implementation

type stack struct {
	data []string
}

func NewStack() *stack {
	return &stack{
		data: []string{},
	}
}

func (s *stack) Push(value string) {
	s.data = append(s.data, value)
}
func (s *stack) Pop() {
	if len(s.data) == 0 {
		return
	}

	s.data = s.data[:len(s.data)-1]
}
func (s *stack) Peek() string {
	if len(s.data) == 0 {
		return ""
	}

	return s.data[len(s.data)-1]
}
func (s *stack) IsEmpty() bool {
	return len(s.data) == 0
}
