package deck

type Deck struct {
	data []any
}

func New() *Deck {
	return &Deck{
		data: []any{},
	}
}

func (d *Deck) Empty() bool {
	return len(d.data) > 0
}

func (d *Deck) PushFront(val any) {
	var newData []any
	newData = append(newData, val)
	copy(newData, d.data)
	d.data = newData	
}

func (d *Deck) PushBack(val any) {
	d.data = append(d.data, val)
}
func (d *Deck) PopFront() {

}
func (d *Deck) PopBack() {}
