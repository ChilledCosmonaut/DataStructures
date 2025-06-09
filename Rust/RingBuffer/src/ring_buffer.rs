pub struct RingBuffer {
    vec: Vec<u8>,
    head: usize,
    tail: usize,
    size: usize
}

pub fn create_ring_buffer(size: usize) -> RingBuffer {
    let buffer =  RingBuffer {
        vec: Vec::with_capacity(size),
        head: 0,
        tail: 0,
        size
    };
    
    buffer
}

pub fn add_data(buffer: &mut RingBuffer, data: u8) {
    buffer.vec.push(data);
    buffer.head += 1;
    
    if buffer.head >= buffer.size {
        buffer.head = 0;
    }
}

pub fn pop_data(buffer: &mut RingBuffer) -> Option<u8> {
    if buffer.tail == buffer.head {
        return None;
    }

    if buffer.head == 0 {
        buffer.head = buffer.size;
    }
    buffer.head -= 1;
    
    let data: u8 = buffer.vec[buffer.head];
    
    Some(data)
}

pub fn dequeue_data(buffer: &mut RingBuffer) -> Option<u8> {
    if buffer.tail == buffer.head {
        return None;
    }

    let data: u8 = buffer.vec[buffer.tail];
    
    buffer.tail += 1;
    if buffer. tail >= buffer.size {
        buffer.tail = 0;
    }
    
    Some(data)
}

pub fn print_statistics(buffer: &RingBuffer) {
    println!("Ringbuffer head: {0}\nRingbuffer tail: {1}\n Ringbuffer size: {2}\n", buffer.head, buffer.tail, buffer.size);
}