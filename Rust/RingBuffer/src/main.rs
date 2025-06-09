use crate::ring_buffer::{add_data, create_ring_buffer, dequeue_data, pop_data, print_statistics, RingBuffer};

mod ring_buffer;

fn main() {
    let mut buffer: RingBuffer = create_ring_buffer(25);
    print_statistics(&buffer);
    add_data(&mut buffer, 5);
    print_statistics(&buffer);
    add_data(&mut buffer, 10);
    print_statistics(&buffer);
    add_data(&mut buffer, 15);
    print_statistics(&buffer);
    let mut test: Option<u8> = pop_data(&mut buffer);
    print_statistics(&buffer);
    println!("{}", test.unwrap());
    test = dequeue_data(&mut buffer);
    print_statistics(&buffer);
    println!("{}", test.unwrap());
}
