# Computer-Networks-Lab
Assignments from Computer Network Labs. 

# LAB 6

1. Write a C program in TCP to demonstrate the use of select() system call in the context of I/O multiplexing.

# LAB 5

1. Write a C program in TCP to send a message "Hello KIIT" from client to server. The server will display the message and then send a response message "Thank you" to the client. The client will display the response message.

2. Write a C program in TCP to send a string "Welcome to KIIT" to the server. The server will determine the number of vowels in the string and it will display them.

3. Write a C program in TCP to send a string from client to server. On the server side, display the string first and then check if it is palindrome string.

4. Write a C program in TCP to send an integer array from client to server. On the server side, display the array and determine the sum of elements. This sum will be sent back to the client and display on the client side.

5. Write a C program in TCP to send an integer array from client to server. Display the array on the server machine and determine the second largest element of the array.

# LAB 4

1. Write a program to pass a string from client to server. Display the lower case message in the server. Further, convert the message from lower case to upper case and display the converted message in client side.

2. Write a program to pass a string from client to server. Display the string in server side. Further, find the reverse of the string and send the same to the client and display the  reversed string in client side.

3. Write a program to pass an integer array from client to server and print the array in server side.

4. Write a program to pass an integer array from client to server. Determine the greatest element on the server side and print it in the client side.

# LAB 3

1. Write a C program in UDP to send a message from client to server device.

2. Write a C program in UDP to send a message from server to client device.

# LAB 2

1. Write a C program in UDP to create a socket and assign IP address and port number to the newly created socket using bind function

# LAB 1

1. Write a C program to swap the content of 2 variables using pointer.

2. Write a C program to assign values to each members of the following structure. Pass the populated structure to a function Using call-by address and print the value of each member of the structure with in that function.
struct info{
int roll_no;
char name[50];
float CGPA;
}

3. Write a C program to extract each byte from a given number and store them in separate character variables and print the content of those variables.

4. Write a C Program to enter a number and store the number across the following structure and print the content of each member of the structure. Then aggregate each member of the structure to form the original number and print the same.
struct pkt{
char ch1;
char ch2[2];
char ch3;
};
