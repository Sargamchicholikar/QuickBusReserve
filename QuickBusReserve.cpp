#include <iostream>
#include <string>
using namespace std;

struct Customer {
    string name;
    int age;
    string travelDate;
    string departurePlace;
    string arrivalPlace;
    int seatNumber;
};

struct Queue {
    int front, rear, size;
    unsigned capacity;
    Customer* array;
};

Queue* createQueue(unsigned capacity) {
    Queue* queue = new Queue;
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = new Customer[queue->capacity];
    return queue;
}

bool isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

bool isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, Customer customer) {
    if (isFull(queue))
        return;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = customer;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;

    Customer customer = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return customer.seatNumber;
}

void displayCustomers(Queue* queue) {
    if (isEmpty(queue)) {
        std::cout << "No bookings currently.\n";
        return;
    }

    cout << "Customer details:\n";
    int i = queue->front;
    while (i != queue->rear) {
        Customer customer = queue->array[i];
        cout << "Name: " << customer.name << "\n";
        cout << "Age: " << customer.age << "\n";
        cout << "Travel Date: " << customer.travelDate << "\n";
        cout << "Departure Place: " << customer.departurePlace << "\n";
        cout << "Arrival Place: " << customer.arrivalPlace << "\n";
        cout << "Seat Number: " << customer.seatNumber << "\n";
        cout << "\n";
        i = (i + 1) % queue->capacity;
    }
    Customer customer = queue->array[queue->rear];
    cout << "Name: " << customer.name << "\n";
    cout << "Age: " << customer.age << "\n";
    cout << "Travel Date: " << customer.travelDate << "\n";
    cout << "Departure Place: " << customer.departurePlace << "\n";
    cout << "Arrival Place: " << customer.arrivalPlace << "\n";
    cout << "Seat Number: " << customer.seatNumber << "\n";
}

int main() {
    unsigned capacity = 10;
    Queue* queue = createQueue(capacity);

    while (true) {
        cout << "\n1. Book ticket\n";
        cout << "2. Cancel ticket\n";
        cout << "3. Display bookings\n";
        cout << "4. Exit\n\n";
        int choice;
        cout<<"Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (!isFull(queue)) {
                    Customer customer;
                    cout << "Enter seat number: ";
                    cin >> customer.seatNumber;

                    bool alreadyBooked = false;
                    for (int i = queue->front; i != queue->rear; i = (i + 1) % queue->capacity) {
                        if (queue->array[i].seatNumber == customer.seatNumber) {
                            alreadyBooked = true;
                            break;
                        }
                    }
                    if (queue->array[queue->rear].seatNumber == customer.seatNumber) {
                        alreadyBooked = true;
                    }

                    if (alreadyBooked) {
                        std::cout << "The seat no. is already booked.\n";
                        break;
                    }

                    cout << "Enter name: ";
                    cin.ignore();
                    getline(cin, customer.name);
                    cout << "Enter age: ";
                    cin >> customer.age;
                    cout << "Enter travel date: ";
                    cin.ignore();
                    getline(cin, customer.travelDate);
                    cout << "Enter departure place: ";
                    getline(cin, customer.departurePlace);
                    cout << "Enter arrival place: ";
                    getline(cin, customer.arrivalPlace);
                    enqueue(queue, customer);
                    cout << "Ticket booked for seat " << customer.seatNumber << "\n";
                } else {
                    cout << "Sorry, the bus is full.\n";
                }
                break;
            }

            case 2:
           {
                if (!isEmpty(queue)) {
                    int seat = dequeue(queue);
                    cout << "Ticket canceled for seat " << seat << "\n";
                } else {
                    cout << "No bookings to cancel.\n";
                }
                break;
            }

            case 3:
                displayCustomers(queue);
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
