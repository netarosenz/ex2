/******************
Name: Neta Rosenzweig
ID: 323885582
Assignment: ex2
*******************/

#include <stdio.h>

#define zero 0 // Define the value for zero
#define one 1 // Define the value for one
#define two 2 // Define the value for two
#define four 4 // Define the value for four
#define ten 10 // Define the value for ten
#define correct 1 // Define the value for a "correct" state

int main() {
    int run = correct; // Initialize the "run" variable to control the main loop
    while (run) { // Main loop that runs until "run" is set to zero
        printf("Choose an option:\n"); // Print the menu options
        printf("     1. Happy Face\n");
        printf("     2. Balanced Number\n");
        printf("     3. Generous Number\n");
        printf("     4. Circle Of Joy\n");
        printf("     5. Happy Numbers\n");
        printf("     6. Festival Of Laughter\n");
        printf("     7. Exit\n");
        int option; // Variable to store the user's menu choice
        scanf("%d", &option); // Read the user's menu choice
        switch (option) { // Switch statement to handle the menu choice
            case 1: { // Case 1: Draw a "Happy Face"
                char eyes, nose, mouth; // Variables for the face's symbols
                int face_size; // Variable for the size of the face
                printf("Enter symbols for the eyes, nose, and mouth:\n");
                scanf(" %c %c %c", &eyes, &nose, &mouth); // Get symbols for eyes, nose, and mouth
                printf("Enter face size:\n");
                do { // Loop until a valid face size is entered
                    scanf("%d", &face_size); // Read the face size
                    if (face_size <= zero || face_size % two == zero) { // Check if the size is positive and odd
                        printf("The face's size must be an odd and positive number, please try again:\n");
                    }
                } while (face_size <= zero || face_size % two == zero); // Repeat until the size is valid

                int spaces_eyes = (face_size); // Calculate the spaces between the eyes
                printf("%c", eyes); // Print the first eye
                for (int j = zero; j < spaces_eyes; j++) { // Loop to print spaces between the eyes
                    printf(" ");
                }
                printf("%c\n", eyes); // Print the second eye

                for (int i = zero; i < one; i++) { // Loop to print the nose
                    for (int j = zero; j < (face_size + one) / two; j++) { // Print spaces before the nose
                        printf(" ");
                    }
                    printf("%c", nose); // Print the nose
                }
                printf("\n");
                printf("\\"); // Start the mouth with a backslash
                for (int j = zero; j < (face_size); j++) { // Print the mouth
                    printf("%c", mouth);
                }
                printf("/\n"); // End the mouth with a forward slash
                break; // Exit case 1
            }

            case 2: { // Case 2: Check if a number is balanced
                int number; // Variable to store the input number
                printf("Enter a number:\n");
                do { // Loop until a positive number is entered
                    scanf("%d", &number); // Read the number
                    if (number <= zero) { // Check if the number is positive
                        printf("Only positive number is allowed, please try again:\n");
                    }
                } while (number <= zero); // Repeat until the number is positive

                int digits = zero; // Initialize digit counter
                int sum = number; // Copy the number for processing
                while (sum > zero) { // Loop to count the digits
                    digits++; // Increment digit counter
                    sum /= ten; // Remove the last digit
                }
                int right = zero; // Initialize the sum of the right side digits
                int left = zero; // Initialize the sum of the left side digits
                int middle = digits / two; // Calculate the middle index
                sum = number; // Reset sum to the original number

                for (int i = zero; i < middle; i++) { // Loop to calculate the sum of the right side digits
                    right += sum % ten; // Add the last digit to the right sum
                    sum /= ten; // Remove the last digit
                }

                if (digits % two != zero) { // If the number of digits is odd, skip the middle digit
                    sum /= ten;
                }

                for (int i = zero; i < middle; i++) { // Loop to calculate the sum of the left side digits
                    left += sum % ten; // Add the last digit to the left sum
                    sum /= ten; // Remove the last digit
                }

                if (left == right) { // Compare the left and right sums
                    printf("This number is balanced and brings harmony!\n");
                } else {
                    printf("This number isn't balanced and destroys harmony.\n");
                }
                break; // Exit case 2
            }

            case 3: { // Case 3: Check if a number is generous
                int number; // Variable to store the input number
                printf("Enter a number:\n");
                do { // Loop until a positive number is entered
                    scanf("%d", &number); // Read the number
                    if (number <= zero) { // Check if the number is positive
                        printf("Only positive number is allowed, please try again:\n");
                    }
                } while (number <= zero); // Repeat until the number is positive

                int divisors = zero; // Initialize the sum of proper divisors
                for (int i = one; i < number; i++) { // Loop to find proper divisors
                    if (number % i == zero) { // Check if "i" is a divisor
                        divisors += i; // Add the divisor to the sum
                    }
                }

                if (divisors > number) { // Compare the sum of divisors to the number
                    printf("This number is generous!\n");
                } else {
                    printf("This number does not share.\n");
                }
                break; // Exit case 3
            }

            case 4: { // Case 4: Check if a number and its reverse are both prime
                int number; // Variable to store the input number
                printf("Enter a number:\n");
                do { // Loop until a positive number is entered
                    scanf("%d", &number); // Read the number
                    if (number <= zero) { // Check if the number is positive
                        printf("Only positive number is allowed, please try again:\n");
                    }
                } while (number <= zero); // Repeat until the number is positive

                int prime = number; // Copy the number for processing
                int revers_prime = zero; // Initialize the reversed number

                while (prime > zero) { // Loop to reverse the number
                    revers_prime = revers_prime * ten + prime % ten; // Add the last digit to the reversed number
                    prime /= ten; // Remove the last digit
                }

                prime = number; // Reset "prime" to the original number
                int result = one; // Initialize result as true

                if (prime < two || revers_prime < two) { // Check if either number is less than 2
                    result = zero; // Set result to false
                } else {
                    for (int i = two; i * i <= prime; i++) { // Check if "prime" is not prime
                        if (prime % i == zero) {
                            result = zero; // Set result to false
                            break;
                        }
                    }
                    for (int i = two; i * i <= revers_prime; i++) { // Check if "revers_prime" is not prime
                        if (revers_prime % i == zero) {
                            result = zero; // Set result to false
                            break;
                        }
                    }
                }

                if (result) { // If both numbers are prime
                    printf("This number completes the circle of joy!\n");
                } else {
                    printf("The circle remains incomplete.\n");
                }
                break; // Exit case 4
            }

            case 5: { // Case 5: Print all "Happy Numbers" up to a given number
                int number; // Variable to store the input number
                printf("Enter a number:\n");
                scanf("%d", &number);
                while (number <= zero) { // Loop until a positive number is entered
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%d", &number); // Read the number
                }
                printf("Between 1 and %d only these numbers bring happiness: ", number);

                for (int i = one; i <= number; i++) { // Loop through all numbers up to "number"
                    int temp = i; // Copy the current number for processing
                    int sum = zero; // Initialize the sum of squared digits

                    while (one) { // Loop until the number is determined to be happy or not
                        int digit = temp % ten; // Get the last digit
                        sum += (digit * digit); // Add the square of the digit to the sum
                        temp /= ten; // Remove the last digit

                        if (temp == zero) { // If all digits have been processed
                            if (sum == one) { // If the number is happy
                                printf("%d ", i); // Print the happy number
                                break;
                            }
                            if (sum == four) { // If the number is not happy
                                break;
                            }
                            temp = sum; // Reset "temp" to the sum
                            sum = zero; // Reset the sum
                        }
                    }
                }
                printf("\n");
                break; // Exit case 5
            }

            case 6: { // Case 6: Replace numbers with "Smile!", "Cheer!" or "Festival!"
                int smile_number, cheer_number; // Variables for smile and cheer numbers
                int max = zero; // Variable for the maximum range
                printf("Enter a smile and cheer number:\n");
                scanf("%*[^\n]%*[\n]"); // Clear the buffer
                scanf(" smile: %d, cheer: %d", &smile_number, &cheer_number); // Get smile and cheer numbers

                while (smile_number <= zero || cheer_number <= zero || smile_number == cheer_number) { // Validate the input
                    printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
                    scanf("%*[^\n]%*[\n]"); // Clear the buffer
                    scanf(" smile: %d, cheer: %d", &smile_number, &cheer_number); // Read the input again
                }

                printf("Enter maximum number for the festival:\n");
                scanf("%d", &max); // Get the maximum number

                while (max <= zero) { // Validate the maximum number
                    printf("Only positive maximum number is allowed, please try again:\n");
                    scanf("%d", &max); // Read the input again
                }

                for (int i = one; i <= max; i++) { // Loop through all numbers up to "max"
                    if (((i % smile_number) == zero) && (i % cheer_number) != zero) { // If divisible by smile_number only
                        printf("Smile!\n");
                    } else if ((i % smile_number) != zero && (i % cheer_number) == zero) { // If divisible by cheer_number only
                        printf("Cheer!\n");
                    } else if ((i % smile_number) == zero && (i % cheer_number) == zero) { // If divisible by both
                        printf("Festival!\n");
                    } else {
                        printf("%d\n", i); // Otherwise, print the number
                    }
                }
                break; // Exit case 6
            }

            case 7: // Case 7: Exit the program
                printf("Thank you for your journey through Numeria!\n");
                run = !correct; // Set "run" to 0 to exit the main loop
                break;

            default: // Handle invalid menu options
                printf("This option is not available, please try again.\n");
                break;
        }
    }
    return 0; // End of the program
}
