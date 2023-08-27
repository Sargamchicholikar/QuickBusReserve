 # QuickBusReserve

**Key features of the system:-** 

**>>Custom Queue Implementation:** The code defines a custom queue structure (Queue) that manages customer data. It provides functions to create a queue, enqueue customers, dequeue customers, and check whether the queue is full or empty.

**>>Customer Data Structure:** The code defines a Customer structure to hold customer details, including name, age, travel date, departure place, arrival place, and seat number.

![image](https://github.com/Sargamchicholikar/QuickBusReserve/assets/115207284/523d73d7-975f-42bd-8635-8b32da341c9f)


**>>Booking Functionality:** Users can book tickets by entering a seat number. The code checks if the seat is already booked and prompts the user if it's already taken. If the seat is available, the user is prompted to enter customer details, which are then enqueued into the queue.

**>>Cancellation Functionality:** Users can cancel tickets, and the seat is dequeued from the queue. If there are no bookings, an appropriate message is displayed.

**>>Displaying Customer Details:** Users can choose to display all customer details including name, age, travel date, departure place, arrival place, and seat number. This information is fetched from the queue and displayed.

**>>User Interface:** The program offers a menu-driven user interface, allowing users to choose various options such as booking, cancellation, displaying bookings, and exiting the program.

![image](https://github.com/Sargamchicholikar/QuickBusReserve/assets/115207284/15897594-1738-48ee-85db-072be397120c)


**>>Error Handling:** The program includes error handling for invalid menu choices, full queue situations (no more bookings allowed), and empty queue situations (no bookings to cancel).

**>>Structured Customer Data:** The code provides a structured approach to storing and managing customer data, making it easy to associate customer details with specific seat numbers.
