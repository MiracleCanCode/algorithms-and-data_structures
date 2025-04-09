package deque

type Deque struct {
	data []any
}

func New() *Deque {
	return &Deque{
		data: []any{},
	}
}


func (d *Deque) PushBack(val any) {}
func (d *Deque) PushFront(val any) {}
func (d *Deque) PopFront() {}
func (d *Deque) PopBack() {}
